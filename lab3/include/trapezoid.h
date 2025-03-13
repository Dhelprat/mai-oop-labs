#pragma once
#include "figure.h"

class Trapezoid final : public Figure {
private:
    double topSide;
    double bottomSide;
    double height;
public:
    Trapezoid(double x = 0, double y = 0, double top = 0, double bottom = 0, double h = 0);
    virtual ~Trapezoid() override;

    std::pair<double, double> getCenter() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    double getArea() const override;
    Figure* clone() const override;
    bool operator==(const Figure &other) const;

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid &trap);
    friend std::istream& operator>>(std::istream& is, Trapezoid &trap);
};
