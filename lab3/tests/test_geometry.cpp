#include <gtest/gtest.h>
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "figureArray.h"
#include "exceptions.h"
#include <cmath>

// Тест вычисления площади для треугольника.
// Формула: area = side² * sqrt(3) / 4.
TEST(TriangleTest, AreaCalculation) {
double side = 6;
Triangle t(0, 0, side);
double expected = (side * side * std::sqrt(3)) / 4;
EXPECT_NEAR(t.getArea(), expected, 0.001);
}

// Тест вычисления площади для квадрата.
TEST(SquareTest, AreaCalculation) {
double side = 4;
Square s(2, 2, side);
double expected = side * side;
EXPECT_DOUBLE_EQ(s.getArea(), expected);
}

// Тест вычисления площади для прямоугольника.
TEST(RectangleTest, AreaCalculation) {
double width = 3, height = 5;
Rectangle r(1, 1, width, height);
double expected = width * height;
EXPECT_DOUBLE_EQ(r.getArea(), expected);
}

// Тест вычисления площади для трапеции.
TEST(TrapezoidTest, AreaCalculation) {
double top = 5, bottom = 2, h = 6;
Trapezoid tr(0, 0, top, bottom, h);
double expected = (top + bottom) * h / 2;
EXPECT_DOUBLE_EQ(tr.getArea(), expected);
}

// Тест клонирования и оператора сравнения для треугольника.
TEST(TriangleTest, CloneAndEquality) {
Triangle t1(0, 0, 6);
Figure* clone = t1.clone();
Triangle* t2 = dynamic_cast<Triangle*>(clone);
ASSERT_NE(t2, nullptr);
EXPECT_TRUE(t1 == *t2);
delete t2;
}

// Тест работы массива фигур: добавление и вычисление общей площади.
TEST(FigureArrayTest, AddAndTotalArea) {
FigureArray arr;
arr.add(new Triangle(0, 0, 6));   // Площадь: ~15.59
arr.add(new Square(2, 2, 4));      // Площадь: 16
arr.add(new Rectangle(1, 1, 3, 5)); // Площадь: 15
arr.add(new Trapezoid(0, 0, 5, 2, 6)); // Площадь: 21
double total = arr.getTotalArea();
double expected = 15.59 + 16 + 15 + 21; // ~67.59
EXPECT_NEAR(total, expected, 0.1);
}
