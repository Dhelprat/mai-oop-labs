#include <iostream>
#include "./include/lab1.h"

int main() {
    std::string number;
    std::cout << "Введите число: ";
    std::cin >> number;

    for (char ch : number) {
        if (!isdigit(ch)) {
            std::cerr << "Введите число!" << std::endl;
            return 1;
        }
    }

    if (isCleanNumber(number)) {
        std::cout << "Число является чистым." << std::endl;
    } else {
        std::cout << "Число не является чистым." << std::endl;
    }

    return 0;
}