#include "hands-up3.h"
#include "CentralTendencyM.h"
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

