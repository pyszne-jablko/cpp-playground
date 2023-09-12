cmake_minimum_required(VERSION 3.20)

project(gtest-examples VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

# Target as executable
# add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
# target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -std=c++17 -Wpedantic -Wall -Wextra -Wconversion -Wshadow -Werror)
# target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE pthread)

# Add tests
enable_testing()
add_executable(hello_test src/main.cpp)
target_link_libraries(hello_test GTest::gtest_main)

add_executable(hello_mock src/main-gmock.cpp)
target_link_libraries(hello_mock GTest::gmock_main)
