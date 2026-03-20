#ifndef HANDS_UP2_H
#define HANDS_UP2_H

const int SIZE = 5;

struct point{
    int x;
    int y;
};

int sumax(const point data[], int size);
int sumay(const point data[], int size);
int sumaXY(const point data[], int size);

#endif

