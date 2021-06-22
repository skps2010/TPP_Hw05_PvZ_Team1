#ifndef map__
#define map__
#include <iostream>
#include "land.h"

class map
{
public:
    map() : row_(8), land_(new land[row_]()){};
    map(const int row) : row_(row), land_(new land[row_]()){};
    ~map()
    {
        delete[] land_;
    }

private:
    int row_;
    land *land_;
};

#endif