#include "Dataset4.h"
#include "Tfrecuencia.h"
#include <iostream>

using namespace std;

int main() {
    DataSet ds;

    ds.printData();

    FrequencyTable ft(ds);
    ft.buildTable();

    ft.printTable();

    return 0;
}