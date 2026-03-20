#include "CentralTendencyM.h"
#include <algorithm>

CentralTendencyM::CentralTendencyM(const DataSet& d)
    : dataset(d) {}

double CentralTendencyM::mean() const {

    int sum = 0;

    int* data = dataset.getData();
    int size = dataset.getSize();

    for (int i = 0; i < size; i++)
        sum += data[i];

    return (double)sum / size;
}

double CentralTendencyM::median() const {

    int size = dataset.getSize();
    int* data = dataset.getData();

    int* copy = new int[size];

    for (int i = 0; i < size; i++)
        copy[i] = data[i];

    std::sort(copy, copy + size);

    double med;

    if (size % 2 == 0)
        med = (copy[size/2 - 1] + copy[size/2]) / 2.0;
    else
        med = copy[size/2];

    delete[] copy;

    return med;
}

int CentralTendencyM::mode() const {

    int* data = dataset.getData();
    int size = dataset.getSize();

    int mode = data[0];
    int maxCount = 0;

    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {
            if (data[j] == data[i])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }

    return mode;
}