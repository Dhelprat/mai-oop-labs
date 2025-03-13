#include "square.h"
#include "exceptions.h"
#include <cmath>
#include <vector>

Square::Square(double x, double y, double s) : Figure(x, y), side(s) {
    if (s < 0) {
        throw NegativeSideException();
    }
}

Square::~Square() {}

std::pair<double, double> Square::getCenter() const {
    return {x, y};
}

std::vector<std::pair<double, double>> Square::getVertices() const {
    std::vector<std::pair<double, double>> verts;
    double hs = side / 2;
    verts.push_back({x - hs, y + hs});
    verts.push_back({x + hs, y + hs});
    verts.push_back({x + hs, y - hs});
    verts.push_back({x - hs, y - hs});
    return verts;
}

double Square::getArea() const {
    return side * side;
}

Figure* Square::clone() const {
    return new Square(*this);
}

bool Square::operator==(const Figure &other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (s) {
        return x == s->x && y == s->y && side == s->side;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Square &sq) {
    os << static_cast<const Figure&>(sq)
       << "\nSide length: " << sq.side
       << "\nArea: " << sq.getArea()
       << "\nVertices:";
    auto verts = sq.getVertices();
    for (size_t i = 0; i < verts.size(); i++) {
        os << "\n  " << i+1 << ": (" << verts[i].first << ", " << verts[i].second << ")";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Square &sq) {
    is >> static_cast<Figure&>(sq);
    std::cout << "Enter side length: ";
    double s;
    is >> s;
    if (s < 0) {
        throw NegativeSideException();
    }
    sq.side = s;
    return is;
}
