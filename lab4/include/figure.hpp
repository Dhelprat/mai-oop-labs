#pragma once
#include "point.hpp"
#include <vector>
#include <iostream>
#include <memory>

template <typename T>
class Figure {
protected:
    Point<T> center;
public:
    Figure(const Point<T>& c = Point<T>()) : center(c) {}
    virtual ~Figure() = default;

    virtual T getArea() const = 0;
    virtual std::shared_ptr<Figure<T>> clone() const = 0;
    virtual Point<T> getCenter() const { return center; }
    virtual std::vector<Point<T>> getVertices() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
        os << "Center: " << fig.center;
        return os;
    }

    // Оператор ввода оставляем на усмотрение конкретных фигур
};
