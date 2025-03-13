#pragma once
#include "figure.h"

class FigureArray {
private:
    Figure **figures;
    size_t size;
    size_t capacity;
public:
    FigureArray(size_t initial_capacity = 10);
    ~FigureArray();

    void add(Figure *fig);
    void remove(size_t index);
    double getTotalArea() const;
    void printAll() const;
    Figure* at(size_t index) const;
};
