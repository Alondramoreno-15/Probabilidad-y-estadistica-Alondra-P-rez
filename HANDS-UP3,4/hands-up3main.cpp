#include "hands-up3.h"
#include <iostream>     
#include "CentralTendencyM.h"

using namespace std;    

int main(){
    DataSet data;
    data.printData();

    CentralTendencyM ct(data); 

    cout << "Mean: " << ct.mean() << endl;
    cout << "Mediana: " << ct.median() << endl;
    cout << "Moda: " << ct.mode() << endl;

    return 0;
}

