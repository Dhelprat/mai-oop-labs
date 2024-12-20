cmake_minimum_required(VERSION 3.10)
project(BinaryProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Добавляем основной исполняемый файл
add_executable(main
        main.cpp
        src/binary.cpp
)
target_include_directories(main PRIVATE include)

# Добавляем тесты
add_executable(binary_test
        tests/binary_test.cpp
        src/binary.cpp
)
target_include_directories(binary_test PRIVATE include ${googletest_SOURCE_DIR}/include)
target_link_libraries(binary_test gtest_main)

# Добавляем команду для запуска тестов
add_test(NAME binary_test COMMAND binary_test)