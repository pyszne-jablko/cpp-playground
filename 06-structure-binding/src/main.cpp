#include <iostream>
#include <string>
#include <tuple>
#include <utility> // for std::pair<>

struct case_3_struct
{
    double height;
    int id;
    std::string name;
};

int main(int /*argc*/, char** /*argv*/)
{
    std::cout << "Examples of structure binding"
              << std::endl << std::endl;

    // Case 1, bind an array
    int a[2] = { 8, 9 };
    auto [ a_one, a_two ] = a; // this is structure bind an array, creates
                               // copies of data
    auto& [ a_one_bis, a_two_bis ] = a; // this is structure bind an array,
                                        // creates refs to data
    std::cout << "Case 1, bind an array" << std::endl;
    std::cout << "  a[0] = " << a[0] << std::endl;
    std::cout << "  a[1] = " << a[1] << std::endl;
    std::cout << "  a_one = " << a_one << std::endl;
    std::cout << "  a_two = " << a_two << std::endl;
    std::cout << "  a_one_bis = " << a_one_bis << std::endl;
    std::cout << "  a_two_bis = " << a_two_bis << std::endl;
    std::cout << "  modify a_one and display" << std::endl;
    a_one += 10;
    std::cout << "  a[0] = " << a[0] << std::endl;
    std::cout << "  a_one = " << a_one << std::endl;
    std::cout << "  a_one_bis = " << a_one_bis << std::endl;
    std::cout << "  modify a_one_bis and display" << std::endl;
    a_one_bis += 100;
    std::cout << "  a[0] = " << a[0] << std::endl;
    std::cout << "  a_one = " << a_one << std::endl;
    std::cout << "  a_one_bis = " << a_one_bis << std::endl;

    // Case 2, binding a tuple-like type
    std::tuple< double, double, std::string, int > tuple_2 { 1.3,
                                                             -4.25,
                                                             "Honda",
                                                             8 };
    const auto& [ x2, y2, name2, id2 ] = tuple_2;
    std::cout << std::endl << "Case 2, binding a tuple-like type" << std::endl;
    std::cout << "  x2 equal " << x2 << std::endl;
    std::cout << "  y2 equal " << y2 << std::endl;
    std::cout << "  name2 equal " << name2 << std::endl;
    std::cout << "  id2 equal " << id2 << std::endl;

    double some_lvalue_double { 3.14 };
    double some_lvalue_double2 { 25.4 };
    std::string some_lvalue_string { "Lorem ipsum" };
    std::tuple< double&&, std::string&, double > tuple_2_2 { std::move( some_lvalue_double ),
                                                             some_lvalue_string,
                                                             some_lvalue_double2 };
    const auto& [ x3, name3, y3 ] = tuple_2_2;
    std::cout << "  Using another tuple" << std::endl;
    std::cout << "  x3 equal " << x3 << std::endl;
    std::cout << "  name3 equal " << name3 << std::endl;
    std::cout << "  y3 equal " << y3 << std::endl;

    // Case 3, binding to data members
    auto fun = []() {
         return case_3_struct { 9.9, 0, "House" };
    };
    const auto [ height, id, name ] = fun();
    std::cout << std::endl << "Case 3, binding to data members" << std::endl;
    std::cout << "  height = " << height << std::endl;
    std::cout << "  id = " << id << std::endl;
    std::cout << "  name = " << name << std::endl;

    // const auto [ height_only ] = fun(); // Error, you have to use all fields
                                           // from struct.

    return 0;
}

