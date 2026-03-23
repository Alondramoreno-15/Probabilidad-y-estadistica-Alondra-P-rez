#include "hands-up5.h"
#include "Tabla3m.h"
#include <iostream>

using namespace std;

int main() {
    DataSet ds; 
    ds.printData();

    FrequencyTable ft(ds);
    ft.buildTable();
    ft.printTable();
    ft.printMeasures();

    return 0;
}