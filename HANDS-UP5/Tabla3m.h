#ifndef TABLA3M_H
#define TABLA3M_H 

#include "hands-up5.h"
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

    double calculateMean() const;
    double calculateMedian() const;
    double calculateMode() const;
    void printMeasures() const;
};

#endif