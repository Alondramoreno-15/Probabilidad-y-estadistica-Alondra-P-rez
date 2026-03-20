#ifndef CENTRAL_TENDENCY_H
#define CENTRAL_TENDENCY_H

#include "hands-up3.h"

class CentralTendencyM {

private:
    const DataSet& dataset;  // ← referencia, no puntero

public:
    CentralTendencyM(const DataSet& d);

    double mean() const;
    double median() const;
    int mode() const;
};

#endif