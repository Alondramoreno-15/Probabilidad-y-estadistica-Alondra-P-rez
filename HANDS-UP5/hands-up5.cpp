#include "hands-up5.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

DataSet::DataSet() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 90); 

    for (int i = 0; i < 40; i++) 
        data.push_back(dist(gen));
    
    sort(data.begin(), data.end()); 
}
DataSet::DataSet(const vector<int>& values) : data(values) {}
DataSet::~DataSet() {}

void DataSet::setData(const vector<int>& values) { data = values; }
vector<int> DataSet::getData() const { return data; }

void DataSet::printData() const {
    cout << "Datos generados (" << data.size() << "): ";
    for (int x : data) cout << x << " ";
    cout << endl;
}