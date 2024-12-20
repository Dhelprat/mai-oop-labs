#include "../include/binary.h"

// Конструктор по умолчанию
Binary::Binary() : data(1, 0) {}

// Конструктор с размером и значением
Binary::Binary(size_t size, unsigned char value) : data(size, value) {
    if (value > 1) {
        throw std::invalid_argument("Value must be 0 or 1");
    }
}

// Конструктор с initializer_list
Binary::Binary(const std::initializer_list<unsigned char>& list) : data(list) {
    for (unsigned char val : list) {
        if (val > 1) {
            throw std::invalid_argument("Value must be 0 or 1");
        }
    }
}

// Конструктор с вектором
Binary::Binary(const std::vector<unsigned char>& data) : data(data) {
    for (unsigned char val : data) {
        if (val > 1) {
            throw std::invalid_argument("Value must be 0 or 1");
        }
    }
}

// Конструктор копирования
Binary::Binary(const Binary& other) : data(other.data) {}

// Конструктор перемещения
Binary::Binary(Binary&& other) noexcept : data(std::move(other.data)) {}

// Деструктор
Binary::~Binary() noexcept {}

// Оператор присваивания копированием
Binary& Binary::operator=(const Binary& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

// Оператор присваивания перемещением
Binary& Binary::operator=(Binary&& other) noexcept {
if (this != &other) {
data = std::move(other.data);
}
return *this;
}

Binary Binary::operator+(const Binary& other) const {
    Binary result;
    result.data.clear(); // Очищаем результат, чтобы начать с пустого массива

    size_t maxSize = std::max(data.size(), other.data.size());
    unsigned char carry = 0; // Перенос

    // Складываем биты
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0; // Если бит отсутствует, считаем его равным 0
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;

        unsigned char sum = a + b + carry; // Складываем биты и перенос
        result.data.push_back(sum % 2);   // Добавляем младший бит результата
        carry = sum / 2;                  // Обновляем перенос
    }

    // Если остался перенос, добавляем его в результат
    if (carry) {
        result.data.push_back(carry);
    }

    return result;
}

Binary& Binary::operator+=(const Binary& other) {
    size_t maxSize = std::max(data.size(), other.data.size());
    resize(maxSize);

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0;
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;
        unsigned char sum = a + b + carry;
        data[i] = sum % 2;
        carry = sum / 2;
    }

    if (carry) {
        data.push_back(carry);
    }

    normalize();
    return *this;
}

Binary Binary::operator-(const Binary& other) const {
    if (*this < other) {
        throw std::invalid_argument("Result would be negative.");
    }

    std::vector<unsigned char> result;
    size_t maxSize = std::max(data.size(), other.data.size());
    unsigned char borrow = 0; // Заём

    // Вычитаем биты
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0; // Если бит отсутствует, считаем его равным 0
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;

        int diff = a - b - borrow; // Вычитаем биты и заём
        if (diff < 0) {
            diff += 2; // Если результат отрицательный, добавляем 2 (заём)
            borrow = 1; // Устанавливаем заём для следующего бита
        } else {
            borrow = 0; // Сбрасываем заём, если не было заёма
        }

        result.push_back(diff); // Добавляем результат вычитания
    }

    // Удаляем ведущие нули
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return Binary(result);
}

Binary& Binary::operator-=(const Binary& other) {
    if (*this < other) {
        throw std::invalid_argument("Result would be negative");
    }

    size_t maxSize = std::max(data.size(), other.data.size());
    resize(maxSize);

    unsigned char borrow = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0;
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;
        unsigned char diff = a - b - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        data[i] = diff;
    }

    normalize();
    return *this;
}

bool Binary::operator==(const Binary& other) const {
    return data == other.data;
}

bool Binary::operator!=(const Binary& other) const {
    return !(*this == other);
}

bool Binary::operator<(const Binary& other) const {
    if (data.size() != other.data.size()) {
        return data.size() < other.data.size(); // Если размеры разные, сравниваем по длине
    }
    for (size_t i = data.size(); i > 0; --i) {
        if (data[i - 1] != other.data[i - 1]) {
            return data[i - 1] < other.data[i - 1]; // Сравниваем биты, начиная со старшего
        }
    }
    return false;
}

bool Binary::operator>(const Binary& other) const {
    return !(*this <= other);
}

bool Binary::operator<=(const Binary& other) const {
    return (*this < other) || (*this == other);
}

bool Binary::operator>=(const Binary& other) const {
    return !(*this < other);
}

// Размер
size_t Binary::size() const {
    return data.size();
}

// Доступ по индексу
unsigned char Binary::at(size_t index) const {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Вывод
std::ostream& operator<<(std::ostream& os, const Binary& binary) {
    for (size_t i = binary.data.size(); i > 0; --i) {
        os << static_cast<int>(binary.data[i - 1]);
    }
    return os;
}

// Изменение размера
void Binary::resize(size_t newSize) {
    if (newSize > data.size()) {
        data.resize(newSize, 0);
    }
}

// Нормализация (удаление ведущих нулей)
void Binary::normalize() {
    size_t i = data.size();
    while (i > 1 && data[i - 1] == 0) {
        --i;
    }
    data.resize(i);
}