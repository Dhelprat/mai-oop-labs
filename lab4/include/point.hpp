#pragma once
#include <iostream>

template <typename T>
class Point {
public:
    T x, y;

    Point(T x_val = T(), T y_val = T()) : x(x_val), y(y_val) {}

    friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt) {
        os << "(" << pt.x << ", " << pt.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point<T>& pt) {
        is >> pt.x >> pt.y;
        return is;
    }
};
