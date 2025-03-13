#pragma once
#include <iostream>
#include <vector>
#include <utility>

class Figure {
protected:
    double x, y;
public:
    Figure(double x = 0, double y = 0);
    virtual ~Figure() = default;

    virtual double getArea() const = 0;
    virtual Figure* clone() const = 0;
    virtual std::pair<double, double> getCenter() const = 0;
    virtual std::vector<std::pair<double, double>> getVertices() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};
