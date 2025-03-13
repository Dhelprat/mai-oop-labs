#include "trapezoid.h"
#include "exceptions.h"
#include <cmath>
#include <vector>

Trapezoid::Trapezoid(double x, double y, double top, double bottom, double h)
        : Figure(x, y), topSide(top), bottomSide(bottom), height(h) {
    if (top < 0 || bottom < 0 || h < 0) {
        throw NegativeSideException();
    }
}

Trapezoid::~Trapezoid() {}

std::pair<double, double> Trapezoid::getCenter() const {
    return {x, y};
}

std::vector<std::pair<double, double>> Trapezoid::getVertices() const {
    std::vector<std::pair<double, double>> verts;
    double halfH = height / 2;
    verts.push_back({x - topSide / 2, y + halfH});
    verts.push_back({x + topSide / 2, y + halfH});
    verts.push_back({x + bottomSide / 2, y - halfH});
    verts.push_back({x - bottomSide / 2, y - halfH});
    return verts;
}

double Trapezoid::getArea() const {
    return (topSide + bottomSide) * height / 2;
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure &other) const {
    const Trapezoid* t = dynamic_cast<const Trapezoid*>(&other);
    if (t) {
        return x == t->x && y == t->y && topSide == t->topSide && bottomSide == t->bottomSide && height == t->height;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Trapezoid &trap) {
    os << static_cast<const Figure&>(trap)
       << "\nTop side: " << trap.topSide
       << "\nBottom side: " << trap.bottomSide
       << "\nHeight: " << trap.height
       << "\nArea: " << trap.getArea()
       << "\nVertices:";
    auto verts = trap.getVertices();
    for (size_t i = 0; i < verts.size(); i++) {
        os << "\n  " << i+1 << ": (" << verts[i].first << ", " << verts[i].second << ")";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid &trap) {
    is >> static_cast<Figure&>(trap);
    std::cout << "Enter top side, bottom side and height: ";
    double top, bottom, h;
    is >> top >> bottom >> h;
    if (top < 0 || bottom < 0 || h < 0) {
        throw NegativeSideException();
    }
    trap.topSide = top;
    trap.bottomSide = bottom;
    trap.height = h;
    return is;
}
