#include <iostream>
#include "./include/binary.h"

int main() {
    try {
        Binary a{1, 1, 0, 1}; // 11 в двоичной системе ======== ЧИСЛА ВВОДЯТСЯ РЕКУРСИВНО! ========
        Binary b{1, 0, 1};    // 5 в двоичной системе ======== ЧИСЛА ВВОДЯТСЯ РЕКУРСИВНО! ========

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;

        Binary c = a + b;
        std::cout << "a + b: " << c << std::endl;

        Binary d = a - b;
        std::cout << "a - b: " << d << std::endl;

        std::cout << "a == b: " << (a == b) << std::endl;
        std::cout << "a < b: " << (a < b) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}