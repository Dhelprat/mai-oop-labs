#include "../include/lab1.h"

bool isCleanNumber(const std::string& number) {
    for (size_t i = 1; i < number.size(); ++i) {
        if (number[i] < number[i - 1]) {
            return false;
        }
    }
    return true;
}