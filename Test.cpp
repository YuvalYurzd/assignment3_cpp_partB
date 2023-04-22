#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Fraction constructors")
{
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_NOTHROW(Fraction());
    CHECK_THROWS(Fraction(5,0));
}

TEST_CASE("Fraction operators and making sure they are working on both sides of the fraction")
{
    Fraction n1(2,3);
    Fraction n2(1,2);
    float x = 2.5;
    CHECK(n1 + n2 == Fraction(7,6));
    CHECK(n1 - n2 == Fraction(1,6));
    CHECK(n1 * n2 == Fraction(1,3));
    CHECK(n1 / n2 == Fraction(4,3));
    CHECK(n2 + x == Fraction(3,1));
    CHECK(n2 - x == Fraction(-2,1));
    CHECK(n2 * x == Fraction(5,4));
    CHECK(n2 / x == Fraction(1,5));
    CHECK(x + n2 == Fraction(3,1));
    CHECK(x - n2 == Fraction(2,1));
    CHECK(x * n2 == Fraction(5,4));
    CHECK(x / n2 == Fraction(5,1));
    Fraction n3(1,1);
    CHECK(n2 + n3 == 1.5);
    CHECK(n2 - n3 == -0.5);
    CHECK(n2 * n3 == 0.5);
    CHECK(n2 / n3 == 0.5);
    CHECK(n3 * Fraction(0,5) == 0.0);
    CHECK_THROWS(n2 / 0.0);
}

TEST_CASE("Comparison operators")
{
    Fraction n1(1,2);
    Fraction n2(1,3);
    CHECK(n1 > n2);
    CHECK(n1 >= n2);
    CHECK(n1 >= 0.5);
    CHECK(n1 == 0.5);
    CHECK(0.5 == n1);
    CHECK(n2 < n1);
    CHECK(n2 <= n1);
    CHECK(n1 > 0.1);
    CHECK(0.1 <= n1);
    CHECK(0.1 < n1);
    CHECK(n1 >= 0.2);
    CHECK(n1 < 1.5);
    CHECK(1.5 >= n1);
    CHECK(n1 <= 0.8);
    CHECK(0.8 > n1);
    CHECK(!(n1 == n2));

}

TEST_CASE("Increase and decrease - pre and post fix forms") {
    Fraction f1(1, 2);
    
    // Test prefix form of ++
    Fraction f2 = ++f1;
    CHECK(f1 == Fraction(3, 2)); 
    CHECK(f2 == Fraction(3, 2)); 
    
    // Test postfix form of ++
    Fraction f3 = f1++;
    CHECK(f1 == Fraction(5, 2)); 
    CHECK(f3 == Fraction(3, 2)); 
    
    // Test prefix form of --
    Fraction f4 = --f1;
    CHECK(f1 == Fraction(3, 2)); 
    CHECK(f4 == Fraction(3, 2)); 
    
    // Test postfix form of --
    Fraction f5 = f1--;
    CHECK(f1 == Fraction(1, 2)); 
    CHECK(f5 == Fraction(3, 2)); 
}

TEST_CASE("Fraction output stream operator - reduced and non-reduced form") {
    Fraction n(1,2);
    std::stringstream ss;
    ss << n;
    CHECK(ss.str() == "1/2");

    Fraction n1(10, 25);
    std::stringstream ss1;
    ss1 << n1;
    CHECK(ss1.str() == "2/5"); 

    Fraction n2(4, 4);
    std::stringstream ss2;
    ss2 << n2;
    CHECK(ss2.str() == "1/1");
}

TEST_CASE("Fraction input stream operator - reduced and non-reduced form") {
    Fraction n1;
    std::stringstream ss1("1/2");
    ss1 >> n1;
    CHECK(n1 == Fraction(1,2));

    Fraction n2;
    std::stringstream ss2("4/6");
    ss2 >> n2;
    CHECK(n2 == Fraction(2,3));
}

