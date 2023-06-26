cmake_minimum_required(VERSION 3.10)

project(cmake_advanced_proj VERSION 1.0)

# Add library
add_subdirectory(lib)

# Target as executable
add_executable(app src/main.cpp)
target_compile_options(app PRIVATE -std=c++17 -Wpedantic -Wall -Wextra -Wconversion -Wshadow -Werror)
target_link_libraries(app PRIVATE cmake_library)
