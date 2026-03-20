#include "hands-up3.h"
#include <iostream>


DataSet::DataSet() {
    size = 5;
    data = new int [size];

    data[0] = 4;
    data[1] = 8;
    data[2] = 8;
    data[3] = 16;
    data[4] = 20;
}

DataSet::~DataSet(){
    delete [] data;
}

int* DataSet::getData()const{
    return data;
}

int DataSet::getSize()const{
    return size;
}

void DataSet::printData()const{
    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
