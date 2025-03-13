cmake_minimum_required(VERSION 3.10)
project(MemoryListProject LANGUAGES CXX)

# Используем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)

# Собираем исходные файлы из папки src в библиотеку
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(memory_list_lib ${SRC_FILES})

# Собираем главный исполняемый файл (main.cpp в корневой директории)
add_executable(main_exe main.cpp)
target_link_libraries(main_exe PRIVATE memory_list_lib)

# Включаем поддержку тестирования
enable_testing()

# Загружаем GoogleTest через FetchContent
set(DOWNLOAD_EXTRACT_TIMESTAMP ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Собираем тесты (файлы тестов находятся в директории tests)
file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(memory_list_tests ${TEST_FILES})
target_link_libraries(memory_list_tests PRIVATE memory_list_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(memory_list_tests)
