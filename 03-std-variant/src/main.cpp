#include <iostream>
#include <variant>

template< typename T, typename... Types>
constexpr const char* my_is_type(const std::variant< Types... >& v ) noexcept
{
    return std::holds_alternative< T >( v ) ? "True" : "False";
}

int main(int /*argc*/, char** /*argv*/)
{
    using namespace std;

    cout << "Examples of std::variant" << endl;

    // Case 1
    cout << endl << "Case 1 : int and float" << endl;
    variant< int, float > val1;
    val1 = 88;
    int i = get<int>( val1 );
    cout << " Variant val1<int> = " << i << endl;
    cout << " Variant val1<0>   = " << get<0>( val1 ) << endl;
    // cout << " Variant val1<double>   = " << get<double>( val1 ) << endl; // error compiling
    try
    {
        cout << " Variant val1<float> = " << get<float>( val1 ) << endl;
    }
    catch ( const std::bad_variant_access& ex )
    {
        // throw because val1 is now int, not float.
        cout << endl << " Variant val1<float> = throw bad_variant_access" << endl;
    }
    try
    {
        cout << " Variant val1<1>   = " << get<1>( val1 ) << endl;
    }
    catch ( const std::bad_variant_access& ex )
    {
        // throw because val1 is now int, not float.
        cout << endl << " Variant val1<1> = throw bad_variant_access" << endl;
    }
    cout << " Variant val1.index() = " << val1.index() << endl;

    variant< int, float > val2;
    val2 = 2.3f;
    cout << " Variant val2<float> = " << get<float>( val2 ) << endl;
    cout << " Variant val2<1>   = " << get<1>( val2 ) << endl;
    try
    {
        cout << get<int>( val2 );
    }
    catch ( const std::bad_variant_access& ex )
    {
        // throw because val2 is now float, not int
        cout << " Variant val2<int> = throw bad_variant_access" << endl;
    }
    try
    {
        cout << get<0>( val2 );
    }
    catch ( const std::bad_variant_access& ex )
    {
        // throw because val2 is now float, not int
        cout << " Variant val2<0> = throw bad_variant_access" << endl;
    }
    cout << " Variant val2.index() = " << val2.index() << endl;

    // Change from int to float and holds_alternative<>()
    // Template function my_is_type() is only for shorting function
    // std::holds_alternative< T >( const std::variant<>&) noexcept.
    // It is possible to use directly std::holds_alternative<>().
    variant< int, float > val3;
    val3 = 17;
    cout << " Variant val3<int> = " << get< int >( val3 ) << endl;
    cout << " val3 is int : " << my_is_type<int>(val3) << endl;
    cout << " val3 is float : " << my_is_type<float>(val3) << endl;
    val3 = 3.14f;
    cout << " Variant val3<float> = " << get< float >( val3 ) << endl;
    cout << " val3 is int : " << my_is_type<int>(val3) << endl;
    cout << " val3 is float : " << my_is_type<float>(val3) << endl;

    // Get ponter to value and get_if<>() and change
    variant< int, float > val4;
    val4 = 122;
    cout << " val4 is int and pointer is 0x" << hex << get_if< int >( &val4 ) << endl;
    cout << " val4 is int and pointer (when float) is 0x" << hex << get_if< float >( &val4 ) << endl;
    val4 = 6.123f;
    cout << " val4 is float and pointer is 0x" << hex << get_if< float >( &val4 ) << endl;
    cout << " val4 is float and pointer (when int) is 0x" << hex << get_if< int >( &val4 ) << endl;

    // C++11 decltype
    variant< int, float > val5;
    val5 = 8.76f;
    decltype( val5 ) val5bis; // this line is equal "variant< int, float > val5bis;"

    return 0;
}

