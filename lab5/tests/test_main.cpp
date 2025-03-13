#include <gtest/gtest.h>
#include "memory_container.h"
#include <vector>
#include <string>

// Структура для тестирования сложного типа
struct TestComplex {
    int a;
    double b;
    std::string s;

    bool operator==(const TestComplex &other) const {
        return a == other.a && b == other.b && s == other.s;
    }
};

TEST(SinglyLinkedListTest, IntTest) {
    fixed_memory_resource mem_res(1024);
    singly_linked_list<int> list(&mem_res);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::vector<int> values;
    for (const auto& v : list) {
        values.push_back(v);
    }

    EXPECT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 10);
    EXPECT_EQ(values[1], 20);
    EXPECT_EQ(values[2], 30);
}

TEST(SinglyLinkedListTest, ComplexTest) {
    fixed_memory_resource mem_res(1024);
    singly_linked_list<TestComplex> list(&mem_res);

    list.push_back({1, 1.1, "one"});
    list.push_back({2, 2.2, "two"});

    std::vector<TestComplex> values;
    for (const auto& v : list) {
        values.push_back(v);
    }

    EXPECT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], (TestComplex{1, 1.1, "one"}));
    EXPECT_EQ(values[1], (TestComplex{2, 2.2, "two"}));
}
