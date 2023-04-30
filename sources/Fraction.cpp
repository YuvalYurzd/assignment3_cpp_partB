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
    if(x == y)
        gcd = x;
    else{
        gcd = calcgcd(x,y);
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

int Fraction::calcgcd(int num1, int num2) {
    if (num2 == 0) return num1;
    return calcgcd(num2, num1 % num2);
}

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
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

float rounded(const float num)
{
    float rounded = std::round(num * 1000.0) / 1000.0;
    return rounded;
}

ostream &operator<<(ostream &ost, const Fraction &frac)
{
    int n = frac.getNumerator();
    int d = frac.getDenominator();
    if (n < 0 || d < 0) 
    {
        n = abs(n); 
        d = abs(d); 
        ost << "-"; 
    }
    ost << n << "/" << d;
    return ost;
}

istream &operator>>(istream &ist, Fraction &frac)
{
    int num, den;
    ist >> num >> den;
    if (ist && den != 0)
    {
        frac.setNumerator(num);
        frac.setDenominator(den);
    }
    else
    {
        throw runtime_error("Bad input");
    }
    return ist;
}

Fraction Fraction::operator+(const Fraction &other)
{
    int common_denominator = this->denominator * other.denominator;
    int new_numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int n1 = numerator * other.denominator;
    int n2 = other.numerator * denominator;
    int n;
    if (__builtin_add_overflow(n1, n2, &n)) {
        throw std::overflow_error("Overflow error: result of addition is too large");
    }
    Fraction new_frac(new_numerator, common_denominator);
    new_frac.reduce();
    return (new_frac);
}

Fraction Fraction::operator+(float number)
{
    int n = (int)(number * 1000);
    Fraction f(n, 1000);
    return *this + f;
}

Fraction Fraction::operator-(const Fraction &other)
{
    int common_denominator = this->denominator * other.denominator;
    int new_numerator = this->numerator * other.denominator - other.numerator * this->denominator;
     int n1 = numerator * other.denominator;
    int n2 = other.numerator * denominator;
    int n;
    if (__builtin_sub_overflow(n1, n2, &n)) {
        throw std::overflow_error("Overflow error: result of addition is too large");
    }
    Fraction new_frac(new_numerator, common_denominator);
    new_frac.reduce();
    return (new_frac);
}

Fraction Fraction::operator-(float number)
{
    int n = (int)(number * 1000);
    Fraction f(n, 1000);
    return *this - f;
}

Fraction Fraction::operator/(const Fraction &other)
{
    if (other.numerator == 0)
    {
        throw std::runtime_error("cannot divide by 0");
    }
    int new_numerator = this->numerator * other.denominator;
    int new_denominator = this->denominator * other.numerator;
    int n;
    if (__builtin_mul_overflow(numerator, other.denominator, &n))
    {
        throw std::overflow_error("Overflow error: result of multiplication is too large");
    }
    int d;
    if (__builtin_mul_overflow(denominator, other.numerator, &d))
    {
        throw std::overflow_error("Overflow error: result of multiplication is too large");
    }
    Fraction new_frac(new_numerator, new_denominator);
    new_frac.reduce();
    return new_frac;
}

Fraction Fraction::operator/(float number)
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
    int n;
    if (__builtin_mul_overflow(numerator, other.numerator, &n))
    {
        throw std::overflow_error("Overflow error");
    }
    int d;
    if (__builtin_mul_overflow(denominator, other.denominator, &d))
    {
        throw std::overflow_error("Overflow error");
    }
    Fraction new_frac(new_numerator, new_denominator);
    new_frac.reduce();
    return new_frac;
}

bool Fraction::operator>=(float number) const
{
    float x = number * this->denominator;
    return (this->numerator >= x);
}

Fraction operator*(float number, const Fraction &frac)
{
    return Fraction(number) * frac;
}

Fraction operator-(float number, const Fraction &frac)
{
    return Fraction(number) - frac;
}

Fraction operator+(float number, const Fraction &frac)
{
    return Fraction(number) + frac;
}

Fraction operator/(float number, const Fraction &frac)
{
    return Fraction(number) / frac;
}

Fraction Fraction::operator*(float number)
{
    return *this * Fraction(number);
}

bool Fraction::operator==(const Fraction &other) const
{
    if (this->numerator == 0 && other.numerator == 0)
        return true;
    float n1 = rounded((float)this->numerator / this->denominator);
    float n2 = rounded((float)other.numerator / other.denominator);
    return (n1 == n2);
}

bool Fraction::operator==(float number) const
{
    return (number == *this);
}

bool Fraction::operator<(const Fraction &other) const
{
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = this->denominator * other.numerator;
    return (this_numerator < other_numerator);
}

bool Fraction::operator<(float number) const
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

bool Fraction::operator<=(float number) const
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

bool Fraction::operator>(float number) const
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

bool operator<(float num, const Fraction &other)
{
    return Fraction(num) < other;
}

bool operator>(float num, const Fraction &other)
{
    return Fraction(num) > other;
}

bool operator<=(float num, const Fraction &other)
{
    return (Fraction(num) <= other);
}

bool operator>=(float num, const Fraction &other)
{
    return (Fraction(num) >= other);
}

bool operator==(float num, const Fraction &other)
{
    float num_rounded = rounded(num);
    float this_rounded = rounded((float)other.getNumerator() / other.getDenominator());
    return num_rounded == this_rounded;
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