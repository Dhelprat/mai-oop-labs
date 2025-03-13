#pragma once
#include "figure.h"

class Triangle final : public Figure {
private:
    double side;
public:
    Triangle(double x = 0, double y = 0, double s = 0);
    virtual ~Triangle() override;

    std::pair<double, double> getCenter() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    double getArea() const override;
    Figure* clone() const override;
    bool operator==(const Figure &other) const;

    friend std::ostream& operator<<(std::ostream& os, const Triangle &tr);
    friend std::istream& operator>>(std::istream& is, Triangle &tr);
};
