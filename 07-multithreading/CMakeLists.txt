cmake_minimum_required(VERSION 3.10)

project(multithreading VERSION 1.0)

# Target as executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -std=c++17 -Wpedantic -Wall -Wextra -Wconversion -Wshadow -Werror)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE pthread)

