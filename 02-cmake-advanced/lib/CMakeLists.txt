cmake_minimum_required(VERSION 3.10)

add_library(cmake_library STATIC src/cmake_library.cpp)
target_compile_options(cmake_library PRIVATE -std=c++17 -Wpedantic -Wall -Wextra -Wconversion -Wshadow -Werror)
target_include_directories(cmake_library
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
