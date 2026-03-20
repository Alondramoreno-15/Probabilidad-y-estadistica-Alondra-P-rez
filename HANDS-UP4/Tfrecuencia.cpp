#include "Tfrecuencia.h"
#include "Dataset4.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

FrequencyTable::FrequencyTable() {
}

FrequencyTable::FrequencyTable(const DataSet& ds) : data(ds) {
}

FrequencyTable::~FrequencyTable() {
}

void FrequencyTable::setDataSet(const DataSet& ds) {
    data = ds;
}

DataSet FrequencyTable::getDataSet() const {
    return data;
}

void FrequencyTable::calculateAbsoluteFrequencies() {
    values.clear();
    absoluteFrequency.clear();

    vector<int> rawData = data.getData();
    map<int, int> counter;

    for (size_t i = 0; i < rawData.size(); i++) 
        counter[rawData[i]]++;

    for (map<int, int>::iterator it = counter.begin(); it != counter.end(); ++it) {
        values.push_back(it->first);
        absoluteFrequency.push_back(it->second);
    }
}

void FrequencyTable::calculateRelativeFrequencies() {
    relativeFrequency.clear();

    vector<int> rawData = data.getData();
    int n = rawData.size();

    if (n == 0) return;

    for (size_t i = 0; i < absoluteFrequency.size(); i++) 
        relativeFrequency.push_back(static_cast<double>(absoluteFrequency[i]) / n);
}

void FrequencyTable::calculatePercentages() {
    percentage.clear();

    if (relativeFrequency.empty()) return;

    for (size_t i = 0; i < relativeFrequency.size(); i++) 
        percentage.push_back(relativeFrequency[i] * 100.0);
}

void FrequencyTable::buildTable() {
    calculateAbsoluteFrequencies();
    calculateRelativeFrequencies();
    calculatePercentages();
}

void FrequencyTable::printTable() const {
    cout << "\nTABLA DE FRECUENCIAS\n";
    cout << "----------------------------------------------\n";
    cout << left << setw(10) << "Dato"
         << setw(20) << "Frec. Absoluta"
         << setw(20) << "Frec. Relativa"
         << setw(15) << "Porcentaje" << endl;
    cout << "----------------------------------------------\n";

    for (size_t i = 0; i < values.size(); i++) {
        cout << left << setw(10) << values[i]
             << setw(20) << absoluteFrequency[i]
             << setw(20) << fixed << setprecision(4) << relativeFrequency[i]
             << setw(15) << fixed << setprecision(2) << percentage[i] << "%" << endl;
    }

    cout << "----------------------------------------------\n";
}