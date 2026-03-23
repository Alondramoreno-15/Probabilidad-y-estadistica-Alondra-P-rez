#include "Tabla3m.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

FrequencyTable::FrequencyTable() {}

FrequencyTable::FrequencyTable(const DataSet& ds) : data(ds) {}

FrequencyTable::~FrequencyTable() {}

void FrequencyTable::buildTable() {
    vector<int> valores = data.getData();
    int n = valores.size();
    if (n == 0) return;

    // 1. Número de clases usando la Regla de Sturges
    int k = ceil(1 + 3.322 * log10(n));
    
    // 2. Cálculo de Rango y Ancho de clase
    int minVal = valores.front();
    int maxVal = valores.back();
    double rango = maxVal - minVal;
    double ancho = ceil(rango / k);

    // Limpiar contenedores para evitar datos basura
    intervalos.clear();
    f_absoluta.assign(k, 0);
    f_acumulada.clear();
    f_relativa.clear();
    f_rel_acumulada.clear();
    porcentaje.clear();

    // 3. Creación de intervalos y conteo de Frecuencia Absoluta (f)
    double limiteInf = minVal;
    for (int i = 0; i < k; i++) {
        Intervalo inter;
        inter.inferior = limiteInf;
        inter.superior = limiteInf + ancho;
        inter.marcaClase = (inter.inferior + inter.superior) / 2.0; // Punto Medio Xc
        intervalos.push_back(inter);

        for (int val : valores) {
            if (i == k - 1) { // Última clase incluye el límite superior
                if (val >= inter.inferior && val <= inter.superior) f_absoluta[i]++;
            } else {
                if (val >= inter.inferior && val < inter.superior) f_absoluta[i]++;
            }
        }
        limiteInf += ancho;
    }

    // 4. Cálculo de Frecuencias Acumuladas y Porcentajes
    int sumaAbs = 0;
    double sumaRel = 0;
    for (int i = 0; i < k; i++) {
        sumaAbs += f_absoluta[i]; // Fa
        double rel = (double)f_absoluta[i] / n; // fr
        sumaRel += rel; // fra

        f_acumulada.push_back(sumaAbs);
        f_relativa.push_back(rel);
        f_rel_acumulada.push_back(sumaRel);
        porcentaje.push_back(rel * 100.0);
    }
}

void FrequencyTable::printTable() const {
    cout << "\nTABLA DE DATOS AGRUPADOS (n=" << data.getData().size() << ")\n";
    cout << string(90, '-') << endl;
    cout << left << setw(6) << "Clase" 
         << setw(15) << "Límite" 
         << setw(6) << "f" 
         << setw(8) << "Xc" 
         << setw(6) << "Fa" 
         << setw(8) << "fr" 
         << setw(8) << "fra" 
         << "Porcentaje %" << endl;
    cout << string(90, '-') << endl;

    for (size_t i = 0; i < intervalos.size(); i++) {
        string limiteStr = to_string((int)intervalos[i].inferior) + "-" + to_string((int)intervalos[i].superior);
        cout << left << setw(6) << (i + 1)
             << setw(15) << limiteStr
             << setw(6) << f_absoluta[i]
             << setw(8) << fixed << setprecision(1) << intervalos[i].marcaClase
             << setw(6) << f_acumulada[i]
             << setw(8) << setprecision(3) << f_relativa[i]
             << setw(8) << f_rel_acumulada[i]
             << setprecision(1) << porcentaje[i] << "%" << endl;
    }
    cout << string(90, '-') << endl;
}

// --- Medidas de Tendencia Central ---

double FrequencyTable::calculateMean() const {
    double sum = 0;
    int n = f_acumulada.back(); 
    for (size_t i = 0; i < intervalos.size(); i++) {
        sum += intervalos[i].marcaClase * f_absoluta[i];
    }
    return sum / n;
}

double FrequencyTable::calculateMedian() const {
    int n = f_acumulada.back();
    double posicion = n / 2.0;
    int idx = 0;

    // Buscar clase mediana
    while (idx < f_acumulada.size() && f_acumulada[idx] < posicion) {
        idx++;
    }

    double Li = intervalos[idx].inferior;
    double Fi_1 = (idx == 0) ? 0 : f_acumulada[idx - 1];
    double fi = f_absoluta[idx];
    double A = intervalos[idx].superior - intervalos[idx].inferior;

    return Li + ((posicion - Fi_1) / fi) * A;
}

double FrequencyTable::calculateMode() const {
    int idx = 0;
    for (size_t i = 1; i < f_absoluta.size(); i++) {
        if (f_absoluta[i] > f_absoluta[idx]) idx = i;
    }

    double Li = intervalos[idx].inferior;
    double fi = f_absoluta[idx];
    double fi_prev = (idx == 0) ? 0 : f_absoluta[idx - 1];
    double fi_next = (idx == (int)f_absoluta.size() - 1) ? 0 : f_absoluta[idx + 1];
    double A = intervalos[idx].superior - intervalos[idx].inferior;

    double d1 = fi - fi_prev;
    double d2 = fi - fi_next;

    if ((d1 + d2) == 0) return Li; // Evitar división por cero si todas las frecuencias son iguales
    return Li + (d1 / (d1 + d2)) * A;
}

void FrequencyTable::printMeasures() const {
    cout << "\nMEDIDAS DE TENDENCIA CENTRAL" << endl;
    cout << "------------------------------------" << endl;
    cout << "Media (Promedio):   " << fixed << setprecision(2) << calculateMean() << endl;
    cout << "Mediana:            " << calculateMedian() << endl;
    cout << "Moda:               " << calculateMode() << endl;
    cout << "------------------------------------" << endl;
}