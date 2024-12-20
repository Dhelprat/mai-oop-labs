cmake_minimum_required(VERSION 3.10)
project(OOP_labs)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)

# Скачивание Google Test (если архив еще не скачан)
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.12.1.zip")
    file(DOWNLOAD
            https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.12.1.zip
    )
endif()

# Распаковка Google Test
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.12.1")
    execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.12.1.zip
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
    )
endif()

# Добавление Google Test как подпроекта
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.12.1 ${CMAKE_BINARY_DIR}/googletest)

# Указание путей к заголовочным файлам
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Добавление исполняемого файла (main.cpp)
add_executable(lab1_exe ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/lab1.cpp)

# Добавление теста
add_executable(lab1_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_lab1.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/lab1.cpp)
target_link_libraries(lab1_tests gtest_main)

# Добавление цели для запуска тестов
add_test(NAME RunTests COMMAND lab1_tests)