#ifndef TFRECUENCIA_H
#define TFRECUENCIA_H

#include "Dataset4.h"
#include <vector>

class FrequencyTable {
private:
    DataSet data;
    std::vector<int> values;
    std::vector<int> absoluteFrequency;
    std::vector<double> relativeFrequency;
    std::vector<double> percentage;

public:
    FrequencyTable();
    FrequencyTable(const DataSet& ds);

    ~FrequencyTable();

    void setDataSet(const DataSet& ds);
    DataSet getDataSet() const;

    void calculateAbsoluteFrequencies();
    void calculateRelativeFrequencies();
    void calculatePercentages();
    void buildTable();

    void printTable() const;
};

#endif