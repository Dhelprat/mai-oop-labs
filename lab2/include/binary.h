#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

class Binary {
public:
    // Конструкторы
    Binary();
    Binary(size_t size, unsigned char value = 0);
    Binary(const std::initializer_list<unsigned char>& list);
    Binary(const std::vector<unsigned char>& data);
    Binary(const Binary& other);
    Binary(Binary&& other) noexcept;
    ~Binary() noexcept;

    // Операторы присваивания
    Binary& operator=(const Binary& other);
    Binary& operator=(Binary&& other) noexcept;

    // Арифметические операции
    Binary operator+(const Binary& other) const;
    Binary operator-(const Binary& other) const;
    Binary& operator+=(const Binary& other);
    Binary& operator-=(const Binary& other);

    // Операции сравнения
    bool operator==(const Binary& other) const;
    bool operator!=(const Binary& other) const;
    bool operator<(const Binary& other) const;
    bool operator>(const Binary& other) const;
    bool operator<=(const Binary& other) const;
    bool operator>=(const Binary& other) const;

    // Методы доступа
    size_t size() const;
    unsigned char at(size_t index) const;

    // Вывод
    friend std::ostream& operator<<(std::ostream& os, const Binary& binary);

private:
    std::vector<unsigned char> data;

    // Вспомогательные методы
    void resize(size_t newSize);
    void normalize();
};

#endif // BINARY_H