#pragma once
#include "figure.hpp"
#include <stdexcept>
#include <vector>

template <typename T>
class Rectangle : public Figure<T> {
private:
    T width, height;
public:
    Rectangle(const Point<T>& c = Point<T>(), T w = T(), T h = T())
            : Figure<T>(c), width(w), height(h) {
        if(w < T() || h < T())
            throw std::invalid_argument("Width and height must be non-negative");
    }

    virtual ~Rectangle() = default;

    virtual T getArea() const override {
        return width * height;
    }

    virtual std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Rectangle<T>>(*this);
    }

    virtual std::vector<Point<T>> getVertices() const override {
        std::vector<Point<T>> verts;
        T halfW = width / static_cast<T>(2);
        T halfH = height / static_cast<T>(2);
        verts.push_back(Point<T>(this->center.x - halfW, this->center.y + halfH));
        verts.push_back(Point<T>(this->center.x + halfW, this->center.y + halfH));
        verts.push_back(Point<T>(this->center.x + halfW, this->center.y - halfH));
        verts.push_back(Point<T>(this->center.x - halfW, this->center.y - halfH));
        return verts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle<T>& rect) {
        os << static_cast<const Figure<T>&>(rect)
           << "\nWidth: " << rect.width
           << "\nHeight: " << rect.height
           << "\nArea: " << rect.getArea()
           << "\nVertices:";
        auto verts = rect.getVertices();
        for (size_t i = 0; i < verts.size(); i++) {
            os << "\n  " << i+1 << ": " << verts[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rectangle<T>& rect) {
        std::cout << "Enter center (x y): ";
        is >> rect.center;
        std::cout << "Enter width and height: ";
        is >> rect.width >> rect.height;
        if(rect.width < T() || rect.height < T())
            throw std::invalid_argument("Width and height must be non-negative");
        return is;
    }
};
