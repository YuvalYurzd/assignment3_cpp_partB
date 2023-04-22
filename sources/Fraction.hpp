#ifndef header
#define header
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

namespace ariel
{

}
class Fraction
{
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(float value);

    int getNumerator();

    int getDenominator();

    void setNumerator(int Numerator);

    void setDenominator(int Denominator);

    void reduce();

    Fraction operator+(const Fraction &other);
    Fraction operator+(const float number);
    Fraction operator-(const Fraction &other);
    Fraction operator-(const float number);
    Fraction operator/(const Fraction &other);
    Fraction operator/(const float number);
    Fraction operator*(const Fraction &other);
    Fraction operator*(const float number);

    bool operator==(const Fraction &other) const;
    bool operator==(const float number) const;
    bool operator<(const Fraction &other) const;
    bool operator<(const float number) const;
    bool operator<=(const Fraction &other) const;
    bool operator<=(const float number) const;
    bool operator>(const Fraction &other) const;
    bool operator>(const float number) const;
    bool operator>=(const Fraction &other) const;
    bool operator>=(const float number) const;

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);
    friend std::istream &operator>>(std::istream &is,Fraction &frac);
};

bool operator<=(const float &num, const Fraction &other);
bool operator>=(const float &num, const Fraction &other);
bool operator<(const float &num, const Fraction &other);
bool operator>(const float &num, const Fraction &other);
bool operator==(const float &num, const Fraction &other);

Fraction operator*(const float num, Fraction &frac);
Fraction operator-(const float num, Fraction &frac);
Fraction operator+(const float num, Fraction &frac);
Fraction operator/(const float num, Fraction &frac);

#endif