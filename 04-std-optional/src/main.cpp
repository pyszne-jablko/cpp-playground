#include <iostream>
#include <optional>
#include <string>

std::optional< std::string > create_optional_string( bool b )
{
    if ( b )
    {
        return "Lorem ipsum";
    }
    else
    {
        return {};
    }
}

int main(int /*argc*/, char** /*argv*/)
{
    using namespace std;

    cout << "Examples of std::optional" << endl << endl;

    // Case 1
    auto one_a = create_optional_string( true );
    auto one_b = create_optional_string( false );
    cout << "create optional value with value, returns "
         << one_a.value_or( "empty" ) << endl;
    cout << "create optional value without value, returns "
         << one_b.value_or( "empty" ) << endl;

    // Case 1B
    cout << "Object one_a is ";
    if ( one_a )
    {
        cout << "set and value is " << *one_a << endl;
    }
    else
    {
        cout << "empty" << endl;
    }
    cout << "Object one_b is ";
    if ( one_b.has_value() )
    {
        cout << "set and value is " << one_b.value() << endl;
    }
    else
    {
        cout << "empty" << endl;
    }

    // Case 2, object without value can throw std::bad_optional_access
    auto two_a = std::optional< const char* >{};
    try {
        cout << two_a.value();
    }
    catch ( std::bad_optional_access& e )
    {
        cout << "Object two_a do not have value, " << e.what() << endl;
    }

    // Case 3, std::optional<> can be swap and/or reset
    cout << endl << "Swap and reset" << endl;
    auto tree_a = std::optional< long long >(
                                          static_cast< long long >( 123456 ) );
    auto tree_b = std::optional< long long >(
                                          static_cast< long long >( 789000 ) );
    cout << "Before swap()" << endl;
    cout << "tree_a is " << tree_a.value() << endl;
    cout << "tree_b is " << tree_b.value() << endl;
    tree_a.swap( tree_b );
    cout << "After swap()" << endl;
    cout << "tree_a is " << tree_a.value() << endl;
    cout << "tree_b is " << tree_b.value() << endl;
    tree_b.reset();
    cout << "After reset() object tree_b" << endl;
    cout << "tree_a is " << tree_a.value_or( -1 ) << endl;
    cout << "tree_b is " << tree_b.value_or( -1 ) << endl;
    tree_b.swap( tree_a );
    cout << "After another swap()" << endl;
    cout << "tree_a is " << tree_a.value_or( -1 ) << endl;
    cout << "tree_b is " << tree_b.value_or( -1 ) << endl;

    // Case 4, make_optional
    cout << endl << "make_optional" << endl;
    std::string s { "Lorem ipsum" };
    auto s2 = std::make_optional( s );
    cout << "Object s2 is " << s2.value_or( "empty" ) << endl;
    s2.reset();
    cout << "Object s2 after reset() is " << s2.value_or( "empty" ) << endl;

    return 0;
}

