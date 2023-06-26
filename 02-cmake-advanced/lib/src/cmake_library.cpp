#include <iostream>

#include <cmake_library.hpp>
#include <cmake_library_priv.hpp>

namespace tut::cmake {
    void print_some_value()
    {
        std::cout << "tut::cmake::print_some_value() : " << value_to_print << std::endl;
    }
}
