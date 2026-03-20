#ifndef HANDS_UP3_H
#define HANDS_UP3_H

class DataSet{
    int* data;
    int size;

    public:
    DataSet();
    ~DataSet();

    int* getData()const;
    int getSize()const;

    void printData()const;

};

#endif 
