#include <gtest/gtest.h>
#include "../include/lab1.h"

// Тест для проверки чистого числа
TEST(CleanNumberTest, ValidCleanNumbers) {
    EXPECT_TRUE(isCleanNumber("12345"));
    EXPECT_TRUE(isCleanNumber("112233"));
    EXPECT_TRUE(isCleanNumber("11111"));
    EXPECT_TRUE(isCleanNumber("0"));
    EXPECT_TRUE(isCleanNumber("0123"));
}

// Тест для проверки нечистого числа
TEST(CleanNumberTest, InvalidCleanNumbers) {
    EXPECT_FALSE(isCleanNumber("12321"));
    EXPECT_FALSE(isCleanNumber("54321"));
    EXPECT_FALSE(isCleanNumber("1234567890"));
    EXPECT_FALSE(isCleanNumber("987654321"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}