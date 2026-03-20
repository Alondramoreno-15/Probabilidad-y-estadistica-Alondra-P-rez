#include "hands-up2.h"

int sumax(const point data [], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += data[i].x;
    return total;
}

int sumay(const point data[], int size)
{
    int total = 0;
    for (int i= 0; i< size; i++)
        total += data[i].y;
    return total;
}

int sumaXY(const point data [], int size)
{
    int total = 0;
    for(int i = 0; i<size; i++)
    total += data [i].x * data[i].y;
    return total;
}