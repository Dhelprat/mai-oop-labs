#include "triangle.h"
#include "exceptions.h"
#include <cmath>
#include <vector>

Triangle::Triangle(double x, double y, double s) : Figure(x, y), side(s) {
    if (s < 0) {
        throw NegativeSideException();
    }
}

Triangle::~Triangle() {}

std::pair<double, double> Triangle::getCenter() const {
    return {x, y};
}

std::vector<std::pair<double, double>> Triangle::getVertices() const {
    std::vector<std::pair<double, double>> verts;
    double r = side / (2 * std::sqrt(3));
    verts.push_back({x, y + r * std::sqrt(3)});
    verts.push_back({x - side / 2, y - r});
    verts.push_back({x + side / 2, y - r});
    return verts;
}

double Triangle::getArea() const {
    double h = side * std::sqrt(3) / 2;
    return 0.5 * side * h;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}

bool Triangle::operator==(const Figure &other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(&other);
    if (t) {
        return x == t->x && y == t->y && side == t->side;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Triangle &tr) {
    os << static_cast<const Figure&>(tr)
       << "\nSide: " << tr.side
       << "\nArea: " << tr.getArea()
       << "\nVertices:";
    auto verts = tr.getVertices();
    for (size_t i = 0; i < verts.size(); i++) {
        os << "\n  " << i+1 << ": (" << verts[i].first << ", " << verts[i].second << ")";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Triangle &tr) {
    is >> static_cast<Figure&>(tr);
    std::cout << "Enter side length: ";
    double s;
    is >> s;
    if (s < 0) {
        throw NegativeSideException();
    }
    tr.side = s;
    return is;
}
