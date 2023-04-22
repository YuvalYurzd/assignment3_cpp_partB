#include "Fraction.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Fraction::Fraction()
{
}

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("denominator must not be 0");
    }
    this->numerator = numerator;
    this->denominator = denominator;
    this->reduce();
}

Fraction::Fraction(float number)
{
    int power = 1;
    while (number != (int)number && power < 1000)
    {
        number *= 10;
        power *= 10;
    }

    numerator = number;
    denominator = power;

    reduce();
}

void Fraction::reduce()
{
    int x = this->numerator;
    int y = this->denominator;
    int k = 1;
    int gcd = 1;
    while (k <= abs(x) && k <= abs(y))
    {
        if (x % k == 0 && y % k == 0)
            gcd = k;
        k++;
    }
    this->numerator = x / gcd;
    this->denominator = y / gcd;
    if(this->numerator < 0 && this->denominator < 0)
    {
        this->numerator = abs(this->numerator);
        this->denominator = abs(this->denominator);
    }
    if(this->numerator > 0 && this->denominator < 0)
    {
        this->numerator = this->numerator * -1;
        this->denominator = abs(this->denominator);
    }
}

int Fraction::getNumerator()
{
    return this->numerator;
}

int Fraction::getDenominator()
{
    return this->denominator;
}

void Fraction::setNumerator(int Numerator)
{
    this->numerator = Numerator;
}

void Fraction::setDenominator(int Denominator)
{
    this->denominator = Denominator;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &frac)
{
    int numerator, denominator;
    char slash;
    is >> numerator >> slash >> denominator;

    if (slash != '/')
        throw invalid_argument("Invalid input");

    frac = Fraction(numerator, denominator);
    return is;
}

Fraction Fraction::operator+(const Fraction &other)
{
    int common_denominator = this->denominator * other.denominator;
    int new_numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    Fraction new_frac(new_numerator, common_denominator);
    new_frac.reduce();
    return (new_frac);
}

Fraction Fraction::operator+(const float number)
{
    return *this + Fraction(number);
}

Fraction Fraction::operator-(const Fraction &other)
{
    int common_denominator = this->denominator * other.denominator;
    int new_numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    Fraction new_frac(new_numerator, common_denominator);
    new_frac.reduce();
    return (new_frac);
}

Fraction Fraction::operator-(const float number)
{
    return *this - Fraction(number);
}

Fraction Fraction::operator/(const Fraction &other)
{
    int new_numerator = this->numerator * other.denominator;
    int new_denominator = this->denominator * other.numerator;
    Fraction new_frac(new_numerator, new_denominator);
    new_frac.reduce();
    return new_frac;
}

Fraction Fraction::operator/(const float number)
{
    if (number == 0)
    {
        throw runtime_error("cannot devide by 0");
    }
    return *this / Fraction(number);
}

Fraction Fraction::operator*(const Fraction &other)
{
    int new_numerator = this->numerator * other.numerator;
    int new_denominator = this->denominator * other.denominator;
    Fraction new_frac(new_numerator, new_denominator);
    new_frac.reduce();
    return new_frac;
}

bool Fraction::operator>=(const float number) const
{
    float x = number * this->denominator;
    return (this->numerator >= x);
}

Fraction operator*(const float number, Fraction &frac)
{
    return Fraction(number) * frac;
}

Fraction operator-(const float number, Fraction &frac)
{
    return Fraction(number) - frac;
}

Fraction operator+(const float number, Fraction &frac)
{
    return Fraction(number) + frac;
}

Fraction operator/(const float number, Fraction &frac)
{
    return Fraction(number) / frac;
}

Fraction Fraction::operator*(const float number)
{
    return *this * Fraction(number);
}

bool Fraction::operator==(const Fraction &other) const
{
    return (this->numerator == other.numerator && this->denominator == other.denominator);
}

bool Fraction::operator==(const float number) const
{
    float x = number * this->denominator;
    return (this->numerator == x);
}

bool Fraction::operator<(const Fraction &other) const
{
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = this->denominator * other.numerator;
    return (this_numerator < other_numerator);
}

bool Fraction::operator<(const float number) const
{
    float x = number * this->denominator;
    return (this->numerator < x);
}

bool Fraction::operator<=(const Fraction &other) const
{
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = this->denominator * other.numerator;
    return (this_numerator <= other_numerator);
}

bool Fraction::operator<=(const float number) const
{
    float x = number * this->denominator;
    return (this->numerator <= x);
}

bool Fraction::operator>(const Fraction &other) const
{
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = this->denominator * other.numerator;
    return (this_numerator > other_numerator);
}

bool Fraction::operator>(const float number) const
{
    float x = number * this->denominator;
    return (this->numerator > x);
}

bool Fraction::operator>=(const Fraction &other) const
{
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = this->denominator * other.numerator;
    return (this_numerator >= other_numerator);
}

bool operator<(const float &num, const Fraction &other)
{
    return Fraction(num) < other;
}

bool operator>(const float &num, const Fraction &other)
{
    return Fraction(num) > other;
}

bool operator<=(const float &num, const Fraction &other)
{
    return (Fraction(num) <= other);
}

bool operator>=(const float &num, const Fraction &other)
{
    return (Fraction(num) >= other);
}

bool operator==(const float &num, const Fraction &other)
{
    return Fraction(num) == other;
}

Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    this->reduce();
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction new_frac(*this);
    this->numerator += this->denominator;
    this->reduce();
    return new_frac;
}

Fraction &Fraction::operator--()
{
    this->numerator -= this->denominator;
    this->reduce();
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction new_frac(*this);
    this->numerator -= this->denominator;
    this->reduce();
    return new_frac;
}