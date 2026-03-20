#include <iostream>
#include "hands-up2.h"

using namespace std;

int main(){
    point data [SIZE]= {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };
    cout<< "x[0]= "<<data [0].x<< endl;
    cout<< "y[0]= "<<data [0].y<<endl;

    cout<<"total de la suma en X= "<<sumax(data, SIZE)<<endl;
    cout<<"total de la suma en Y= "<<sumay(data, SIZE)<<endl;
    cout<<"total de la suma en XY= "<<sumaXY(data, SIZE)<<endl;

    return 0;
}