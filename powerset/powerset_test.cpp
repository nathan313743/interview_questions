#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "powerset.cpp"
#include <vector>

TEST_CASE( "Sum is correct up to 1,000", "[sum1000]" ) {
    Powerset p1 = Powerset();
    vector<char> *list = new vector<char>();
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    
    std::vector<int> factors;
    factors.push_back(3);
    factors.push_back(5);
    REQUIRE( p1.get_sum(factors, 1000) == 233168);
}

TEST_CASE( "Sum is correct up to 10", "[sum10]" ) {
    Problem1 p1 = Problem1();
    std::vector<int> factors;
    factors.push_back(3);
    factors.push_back(5);
    REQUIRE( p1.get_sum(factors, 10) == 23);
}