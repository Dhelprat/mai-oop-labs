#include <gtest/gtest.h>
#include <sstream>
#include "point.hpp"
#include "figure.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "figureArray.hpp"
#include <memory>
#include <cmath>

// Тест для квадрата: проверка вычисления площади.
TEST(SquareTest, AreaCalculation) {
    Square<int> sq(Point<int>(0, 0), 4);
    EXPECT_EQ(sq.getArea(), 16);
}

// Тест для квадрата: симуляция ввода через istringstream.
TEST(SquareTest, InputParsing) {
    Square<int> sq(Point<int>(0, 0), 0);
    // Формат ввода соответствует оператору>>: сначала ввод центра (x y), затем сторона.
    std::istringstream iss("0 0 5");
    iss >> sq;
    EXPECT_EQ(sq.getArea(), 25);
}

// Тест для прямоугольника: проверка вычисления площади.
TEST(RectangleTest, AreaCalculation) {
    Rectangle<int> rect(Point<int>(0, 0), 3, 5);
    EXPECT_EQ(rect.getArea(), 15);
}

// Тест для прямоугольника: симуляция ввода.
TEST(RectangleTest, InputParsing) {
    Rectangle<int> rect(Point<int>(0, 0), 0, 0);
    std::istringstream iss("0 0 4 3");
    iss >> rect;
    EXPECT_EQ(rect.getArea(), 12);
}

// Тест для трапеции: проверка вычисления площади.
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid<int> trap(Point<int>(0, 0), 5, 2, 6);
    EXPECT_EQ(trap.getArea(), 21);
}

// Тест для трапеции: симуляция ввода.
TEST(TrapezoidTest, InputParsing) {
    Trapezoid<int> trap(Point<int>(0, 0), 0, 0, 0);
    std::istringstream iss("0 0 5 2 6");
    iss >> trap;
    EXPECT_EQ(trap.getArea(), 21);
}

// Тест для контейнера фигур: проверка общей площади.
TEST(FigureArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.add(std::make_shared<Rectangle<int>>(Point<int>(0, 0), 3, 5));   // 15
    arr.add(std::make_shared<Square<int>>(Point<int>(1, 1), 4));           // 16
    arr.add(std::make_shared<Trapezoid<int>>(Point<int>(2, 2), 5, 2, 6));    // 21
    double total = arr.getTotalArea();
    EXPECT_EQ(total, 15 + 16 + 21);
}
