#include "CentralTendencyM.h"
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

    // 1. Número de clases (Sturges)
    int k = ceil(1 + 3.322 * log10(n));
    
    // 2. Rango y Ancho
    int minVal = valores.front();
    int maxVal = valores.back();
    double rango = maxVal - minVal;
    double ancho = ceil(rango / k);

    // Limpiar contenedores
    intervalos.clear();
    f_absoluta.assign(k, 0);
    f_acumulada.clear();
    f_relativa.clear();
    f_rel_acumulada.clear();
    porcentaje.clear();

    // 3. Crear intervalos y contar frecuencias
    double limiteInf = minVal;
    for (int i = 0; i < k; i++) {
        Intervalo inter;
        inter.inferior = limiteInf;
        inter.superior = limiteInf + ancho;
        inter.marcaClase = (inter.inferior + inter.superior) / 2.0;
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

    // 4. Calcular acumuladas y porcentajes
    int sumaAbs = 0;
    double sumaRel = 0;
    for (int i = 0; i < k; i++) {
        sumaAbs += f_absoluta[i];
        double rel = (double)f_absoluta[i] / n;
        sumaRel += rel;

        f_acumulada.push_back(sumaAbs);
        f_relativa.push_back(rel);
        f_rel_acumulada.push_back(sumaRel);
        porcentaje.push_back(rel * 100.0);
    }
}

void FrequencyTable::printTable() const {
    cout << "\nTABLA DE DATOS AGRUPADOS (n=" << data.getData().size() << ")\n";
    cout << string(85, '-') << endl;
    cout << left << setw(6) << "Clase" 
         << setw(15) << "Límite" 
         << setw(6) << "f" 
         << setw(8) << "Xc" 
         << setw(6) << "Fa" 
         << setw(8) << "fr" 
         << setw(8) << "fra" 
         << "Porcentaje %" << endl;
    cout << string(85, '-') << endl;

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
    cout << string(85, '-') << endl;
}