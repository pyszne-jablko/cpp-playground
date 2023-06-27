#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <utility> // for std::pair<>

struct gps_point
{
    double longitude { 0.0 };
    double latitude { 0.0 };
    std::string name { "" };
};

bool operator== ( const gps_point& lhs, const gps_point& rhs )
{
    // Overload operator== is requied as 3rd argument to std::unordered_set
    // bool operator== ( const gps_point& rhs )
    // {
        if ( lhs.longitude != rhs.longitude )
        {
            return false;
        }
        if ( lhs.latitude != rhs.latitude )
        {
            return false;
        }
        if ( lhs.name != rhs.name )
        {
            return false;
        }
        return true;
    // }
};

// Hash function is required as 2nd argument to std::unordered_set
struct gps_point_hash
{
    size_t operator() ( const gps_point& gpspt ) const
    {
        size_t s { 0 };
        s += static_cast< size_t >( gpspt.longitude * 1000.0 );
        s = s << 32;
        s += static_cast< size_t >( gpspt.latitude * 1000.0 );
        s = s << 8;
        s += gpspt.name.length();
        return s;
    }
};

int main(int /*argc*/, char** /*argv*/)
{
    std::cout << "Examples of std::unordered_set and std::unordered_map"
              << std::endl << std::endl;

    // Case 1, unordered_set and unordered_map int trivial types.
    std::unordered_set< int > uset_1 { 1, 2, 3, 4, 5 };
    std::unordered_map< std::string, std::string > umap_1 {
        { "red", "Ferrari" },
        { "green", "Kawasaki" },
        { "blue", "Ford" }
    };
    std::cout << std::endl
              << "unordered_set and unordered_map with trivial types"
              << std::endl;
    for ( const auto& el : uset_1 )
    {
        std::cout << "  set " << el << std::endl;
    }
    std::cout << std::endl;
    for ( const std::pair< const std::string, std::string >& it : umap_1 )
    {
        const auto& key = it.first;
        const auto& value = it.second;
        std::cout << "  map, key=" << key << ", value=" << value << std::endl;
    }

    // Case 2, unordered_set and unordered_map with custom class
    // todo : do this example
    std::unordered_set< gps_point, gps_point_hash > uset_2 {};
    uset_2.insert( { 24.0, 52.0, "Poland?" } );
    std::cout << "using custom struct/class as a key" << std::endl;
    for ( const auto& el : uset_2 )
    {
        std::cout << "  " << el.longitude << ", " << el.latitude << ", "
                  << el.name << std::endl;
    }
    
    return 0;
}

