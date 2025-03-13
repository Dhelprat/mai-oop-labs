#include <iostream>
#include "figureArray.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

void printDivider() {
    std::cout << "\n----------------------------------------\n";
}

int main() {
    int count = 0;
    std::cout << "Сколько фигур вы хотите добавить? ";
    std::cin >> count;

    // Создаем массив фигур
    FigureArray array;

    for (int i = 0; i < count; i++) {
        std::cout << "\nВыберите тип фигуры для добавления:\n";
        std::cout << "1. Triangle\n";
        std::cout << "2. Square\n";
        std::cout << "3. Rectangle\n";
        std::cout << "4. Trapezoid\n";
        std::cout << "Ваш выбор: ";

        int choice = 0;
        std::cin >> choice;

        Figure *fig = nullptr;
        switch (choice) {
            case 1: {
                // Создаем треугольник с дефолтными параметрами и читаем параметры с клавиатуры
                Triangle *t = new Triangle();
                std::cin >> *t;
                fig = t;
                break;
            }
            case 2: {
                Square *s = new Square();
                std::cin >> *s;
                fig = s;
                break;
            }
            case 3: {
                Rectangle *r = new Rectangle();
                std::cin >> *r;
                fig = r;
                break;
            }
            case 4: {
                Trapezoid *tr = new Trapezoid();
                std::cin >> *tr;
                fig = tr;
                break;
            }
            default: {
                std::cout << "Неверный выбор. Фигура не будет добавлена.\n";
                break;
            }
        }

        if (fig != nullptr) {
            array.add(fig);
        }
    }

    printDivider();
    std::cout << "\nВывод всех фигур:\n";
    array.printAll();

    printDivider();
    std::cout << "\nОбщая площадь фигур: " << array.getTotalArea() << "\n";

    return 0;
}
