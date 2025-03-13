cmake_minimum_required(VERSION 3.11)
project(TemplateGeometryProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем заголовочные файлы
include_directories(${PROJECT_SOURCE_DIR}/include)

# Находим все исходные файлы в папке src
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
# Исключаем main.cpp из сборки тестового исполняемого файла
list(FILTER SRC_FILES EXCLUDE REGEX ".*main\\.cpp$")

# Создаем исполняемый файл для основной программы (включая main.cpp)
file(GLOB MAIN_SRC "${PROJECT_SOURCE_DIR}/src/main.cpp")
add_executable(program ${MAIN_SRC} ${SRC_FILES})

# --- Настройка тестов ---
enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include_directories(${gtest_SOURCE_DIR}/include)

# Находим все тестовые файлы в папке tests
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

# Создаем исполняемый файл для тестов, не включая main.cpp из src
add_executable(runTests ${TEST_FILES} ${SRC_FILES})
target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
