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

    int getNumerator() const;

    int getDenominator() const;

    void setNumerator(int Numerator);

    void setDenominator(int Denominator);

    void reduce();

    int calcgcd(int num1, int num2);

    Fraction operator+(const Fraction &other);
    Fraction operator+(float number);
    Fraction operator-(const Fraction &other);
    Fraction operator-(float number);
    Fraction operator/(const Fraction &other);
    Fraction operator/(float number);
    Fraction operator*(const Fraction &other);
    Fraction operator*(float number);

    bool operator==(const Fraction &other) const;
    bool operator==(float number) const;
    bool operator<(const Fraction &other) const;
    bool operator<(float number) const;
    bool operator<=(const Fraction &other) const;
    bool operator<=(float number) const;
    bool operator>(const Fraction &other) const;
    bool operator>(float number) const;
    bool operator>=(const Fraction &other) const;
    bool operator>=(float number) const;

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    friend std::ostream &operator<<(std::ostream &outs, const Fraction &frac);
    friend std::istream &operator>>(std::istream &ist, Fraction &frac);
};

bool operator<=(float num, const Fraction &other);
bool operator>=(float num, const Fraction &other);
bool operator<(float num, const Fraction &other);
bool operator>(float num, const Fraction &other);
bool operator==(float num, const Fraction &other);

Fraction operator*(float num, const Fraction &frac);
Fraction operator-(float num, const Fraction &frac);
Fraction operator+(float num, const Fraction &frac);
Fraction operator/(float num, const Fraction &frac);

#endif