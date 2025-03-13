#pragma once
#include "figure.hpp"
#include <stdexcept>
#include <vector>

template <typename T>
class Square : public Figure<T> {
private:
    T side;
public:
    Square(const Point<T>& c = Point<T>(), T s = T()) : Figure<T>(c), side(s) {
        if(s < T())
            throw std::invalid_argument("Side cannot be negative");
    }

    virtual ~Square() = default;

    virtual T getArea() const override {
        return side * side;
    }

    virtual std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Square<T>>(*this);
    }

    virtual std::vector<Point<T>> getVertices() const override {
        std::vector<Point<T>> verts;
        T half = side / static_cast<T>(2);
        verts.push_back(Point<T>(this->center.x - half, this->center.y + half));
        verts.push_back(Point<T>(this->center.x + half, this->center.y + half));
        verts.push_back(Point<T>(this->center.x + half, this->center.y - half));
        verts.push_back(Point<T>(this->center.x - half, this->center.y - half));
        return verts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Square<T>& sq) {
        os << static_cast<const Figure<T>&>(sq)
           << "\nSide: " << sq.side
           << "\nArea: " << sq.getArea()
           << "\nVertices:";
        auto verts = sq.getVertices();
        for (size_t i = 0; i < verts.size(); i++) {
            os << "\n  " << i+1 << ": " << verts[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Square<T>& sq) {
        std::cout << "Enter center (x y): ";
        is >> sq.center;
        std::cout << "Enter side: ";
        is >> sq.side;
        if(sq.side < T())
            throw std::invalid_argument("Side cannot be negative");
        return is;
    }
};
