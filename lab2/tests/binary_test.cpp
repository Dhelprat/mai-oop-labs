#include <gtest/gtest.h>
#include "../include/binary.h"

// Тест конструктора по умолчанию
TEST(BinaryTest, DefaultConstructor) {
Binary b;
EXPECT_EQ(b.size(), 1);
EXPECT_EQ(b.at(0), 0);
}

// Тест конструктора с размером и значением
TEST(BinaryTest, SizeValueConstructor) {
Binary b(4, 1);
EXPECT_EQ(b.size(), 4);
for (size_t i = 0; i < 4; ++i) {
EXPECT_EQ(b.at(i), 1);
}
}

// Тест конструктора с initializer_list
TEST(BinaryTest, InitializerListConstructor) {
Binary b{1, 0, 1, 1};
EXPECT_EQ(b.size(), 4);
EXPECT_EQ(b.at(0), 1);
EXPECT_EQ(b.at(1), 1);
EXPECT_EQ(b.at(2), 0);
EXPECT_EQ(b.at(3), 1);
}

// Тест копирующего конструктора
TEST(BinaryTest, CopyConstructor) {
Binary b1{1, 0, 1};
Binary b2(b1);
EXPECT_EQ(b2.size(), 3);
EXPECT_EQ(b2.at(0), 1);
EXPECT_EQ(b2.at(1), 0);
EXPECT_EQ(b2.at(2), 1);
}

// Тест оператора присваивания
TEST(BinaryTest, AssignmentOperator) {
Binary b1{1, 0, 1};
Binary b2;
b2 = b1;
EXPECT_EQ(b2.size(), 3);
EXPECT_EQ(b2.at(0), 1);
EXPECT_EQ(b2.at(1), 0);
EXPECT_EQ(b2.at(2), 1);
}

// Тест оператора сложения
TEST(BinaryTest, AdditionOperator) {
Binary b1{1, 0, 1}; // 5
Binary b2{1, 1, 0}; // 6
Binary b3 = b1 + b2; // 11
EXPECT_EQ(b3.size(), 4);
EXPECT_EQ(b3.at(0), 1);
EXPECT_EQ(b3.at(1), 1);
EXPECT_EQ(b3.at(2), 0);
EXPECT_EQ(b3.at(3), 1);
}

// Тест оператора вычитания
TEST(BinaryTest, SubtractionOperator) {
Binary b1{1, 0, 1, 1}; // 11
Binary b2{1, 0, 1};    // 5
Binary b3 = b1 - b2;   // 6
EXPECT_EQ(b3.size(), 3);
EXPECT_EQ(b3.at(0), 0);
EXPECT_EQ(b3.at(1), 1);
EXPECT_EQ(b3.at(2), 1);
}

// Тест оператора сравнения "равно"
TEST(BinaryTest, EqualityOperator) {
Binary b1{1, 0, 1};
Binary b2{1, 0, 1};
Binary b3{1, 1, 0};
EXPECT_TRUE(b1 == b2);
EXPECT_FALSE(b1 == b3);
}

// Тест оператора сравнения "не равно"
TEST(BinaryTest, InequalityOperator) {
Binary b1{1, 0, 1};
Binary b2{1, 0, 1};
Binary b3{1, 1, 0};
EXPECT_FALSE(b1 != b2);
EXPECT_TRUE(b1 != b3);
}

// Тест оператора сравнения "меньше"
TEST(BinaryTest, LessThanOperator) {
Binary b1{1, 0, 1}; // 5
Binary b2{1, 1, 0}; // 6
EXPECT_TRUE(b1 < b2);
EXPECT_FALSE(b2 < b1);
}

// Тест оператора сравнения "больше"
TEST(BinaryTest, GreaterThanOperator) {
Binary b1{1, 0, 1}; // 5
Binary b2{1, 1, 0}; // 6
EXPECT_FALSE(b1 > b2);
EXPECT_TRUE(b2 > b1);
}

// Тест оператора сравнения "меньше или равно"
TEST(BinaryTest, LessThanOrEqualOperator) {
Binary b1{1, 0, 1}; // 5
Binary b2{1, 1, 0}; // 6
EXPECT_TRUE(b1 <= b2);
EXPECT_TRUE(b1 <= b1);
}

// Тест оператора сравнения "больше или равно"
TEST(BinaryTest, GreaterThanOrEqualOperator) {
Binary b1{1, 0, 1}; // 5
Binary b2{1, 1, 0}; // 6
EXPECT_FALSE(b1 >= b2);
EXPECT_TRUE(b2 >= b1);
EXPECT_TRUE(b1 >= b1);
}