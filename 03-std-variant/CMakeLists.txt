cmake_minimum_required(VERSION 3.10)

project(std-variant-examples VERSION 1.0)

# Target as executable
add_executable(app src/main.cpp)
target_compile_options(app PRIVATE -std=c++17 -Wpedantic -Wall -Wextra -Wconversion -Wshadow -Werror)

