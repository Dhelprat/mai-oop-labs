#include "rectangle.h"
#include "exceptions.h"
#include <cmath>
#include <vector>

Rectangle::Rectangle(double x, double y, double w, double h) : Figure(x, y), width(w), height(h) {
    if (w < 0 || h < 0) {
        throw NegativeSideException();
    }
}

Rectangle::~Rectangle() {}

std::pair<double, double> Rectangle::getCenter() const {
    return {x, y};
}

std::vector<std::pair<double, double>> Rectangle::getVertices() const {
    std::vector<std::pair<double, double>> verts;
    double hw = width / 2;
    double hh = height / 2;
    verts.push_back({x - hw, y + hh});
    verts.push_back({x + hw, y + hh});
    verts.push_back({x + hw, y - hh});
    verts.push_back({x - hw, y - hh});
    return verts;
}

double Rectangle::getArea() const {
    return width * height;
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure &other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(&other);
    if (r) {
        return x == r->x && y == r->y && width == r->width && height == r->height;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Rectangle &rect) {
    os << static_cast<const Figure&>(rect)
       << "\nWidth: " << rect.width
       << "\nHeight: " << rect.height
       << "\nArea: " << rect.getArea()
       << "\nVertices:";
    auto verts = rect.getVertices();
    for (size_t i = 0; i < verts.size(); i++) {
        os << "\n  " << i+1 << ": (" << verts[i].first << ", " << verts[i].second << ")";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle &rect) {
    is >> static_cast<Figure&>(rect);
    std::cout << "Enter width and height: ";
    double w, h;
    is >> w >> h;
    if (w < 0 || h < 0) {
        throw NegativeSideException();
    }
    rect.width = w;
    rect.height = h;
    return is;
}
