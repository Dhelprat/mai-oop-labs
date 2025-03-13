#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class Array {
private:
    std::vector<T> elements;
public:
    Array() = default;

    void add(const T& element) {
        elements.push_back(element);
    }

    void remove(size_t index) {
        if(index >= elements.size())
            throw std::out_of_range("Index out of range");
        elements.erase(elements.begin() + index);
    }

    T at(size_t index) const {
        if(index >= elements.size())
            throw std::out_of_range("Index out of range");
        return elements[index];
    }

    double getTotalArea() const {
        double total = 0;
        for(const auto& el : elements) {
            total += el->getArea();
        }
        return total;
    }

    void printAll() const {
        for(size_t i = 0; i < elements.size(); i++) {
            std::cout << "Figure " << i << ":\n" << *elements[i] << "\n\n";
        }
    }
};
