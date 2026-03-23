#ifndef CENTRALTENDENCYM_H
#define CENTRALTENDENCYM_H

#include "hands-up3.h"
#include <vector>
#include <string>

struct Intervalo {
    double inferior;
    double superior;
    double marcaClase; // Punto medio
};

class FrequencyTable {
private:
    DataSet data;
    std::vector<Intervalo> intervalos;
    std::vector<int> f_absoluta;
    std::vector<int> f_acumulada;
    std::vector<double> f_relativa;
    std::vector<double> f_rel_acumulada;
    std::vector<double> porcentaje;

public:
    FrequencyTable();
    FrequencyTable(const DataSet& ds);
    ~FrequencyTable();

    void buildTable();
    void printTable() const;
};

#endif