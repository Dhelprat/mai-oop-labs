cmake_minimum_required(VERSION 3.10)
project(GeometryProgram)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем заголовочные файлы
include_directories(${PROJECT_SOURCE_DIR}/include)

# Находим все исходные файлы программы
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Создаем исполняемый файл для основной программы
add_executable(program ${SRC_FILES})

# Добавляем поддержку тестов
enable_testing()

# Путь к GoogleTest (убедитесь, что GoogleTest установлен на вашей системе)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Находим все тестовые файлы в папке tests
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

# Создаем исполняемый файл для тестов
add_executable(runTests ${TEST_FILES} ${SRC_FILES})

# Линкуем тесты с GoogleTest и pthread (на Linux)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Регистрируем тесты
add_test(NAME runTests COMMAND runTests)
