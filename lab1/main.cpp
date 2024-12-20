#include <iostream>
#include "./include/lab1.h"

int main() {
    std::string number;
    std::cout << "Введите число: ";
    std::cin >> number;

    if (isCleanNumber(number)) {
        std::cout << "Число является чистым." << std::endl;
    } else {
        std::cout << "Число не является чистым." << std::endl;
    }

    return 0;
}