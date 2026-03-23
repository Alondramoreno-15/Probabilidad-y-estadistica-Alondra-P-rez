#ifndef HANDS_UP3_H
#define HANDS_UP3_H

#include <vector>

class DataSet {
private:
    std::vector<int> data;

public:
    DataSet();
    DataSet(const std::vector<int>& values);

    ~DataSet();

    void setData(const std::vector<int>& values);
    std::vector<int> getData() const;

    void printData() const;
};

#endif
