#pragma once
#include "figure.hpp"
#include <stdexcept>
#include <vector>

template <typename T>
class Trapezoid : public Figure<T> {
private:
    T topSide;
    T bottomSide;
    T height;
public:
    Trapezoid(const Point<T>& c = Point<T>(), T top = T(), T bottom = T(), T h = T())
            : Figure<T>(c), topSide(top), bottomSide(bottom), height(h) {
        if(top < T() || bottom < T() || h < T())
            throw std::invalid_argument("Sides and height must be non-negative");
    }

    virtual ~Trapezoid() = default;

    virtual T getArea() const override {
        return (topSide + bottomSide) * height / static_cast<T>(2);
    }

    virtual std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Trapezoid<T>>(*this);
    }

    virtual std::vector<Point<T>> getVertices() const override {
        std::vector<Point<T>> verts;
        T halfH = height / static_cast<T>(2);
        verts.push_back(Point<T>(this->center.x - topSide / static_cast<T>(2), this->center.y + halfH));
        verts.push_back(Point<T>(this->center.x + topSide / static_cast<T>(2), this->center.y + halfH));
        verts.push_back(Point<T>(this->center.x + bottomSide / static_cast<T>(2), this->center.y - halfH));
        verts.push_back(Point<T>(this->center.x - bottomSide / static_cast<T>(2), this->center.y - halfH));
        return verts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid<T>& trap) {
        os << static_cast<const Figure<T>&>(trap)
           << "\nTop side: " << trap.topSide
           << "\nBottom side: " << trap.bottomSide
           << "\nHeight: " << trap.height
           << "\nArea: " << trap.getArea()
           << "\nVertices:";
        auto verts = trap.getVertices();
        for (size_t i = 0; i < verts.size(); i++) {
            os << "\n  " << i+1 << ": " << verts[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Trapezoid<T>& trap) {
        std::cout << "Enter center (x y): ";
        is >> trap.center;
        std::cout << "Enter top side, bottom side and height: ";
        is >> trap.topSide >> trap.bottomSide >> trap.height;
        if(trap.topSide < T() || trap.bottomSide < T() || trap.height < T())
            throw std::invalid_argument("Sides and height must be non-negative");
        return is;
    }
};
