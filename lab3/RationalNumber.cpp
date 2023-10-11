#include "RationalNumber.h"
#include <cmath>

int RationalNumber::NOD(int a, int b) 
{
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void RationalNumber::leadToAnIrreducible()
{
    int nod = NOD(a, b);

    while (nod != 1) {

        a /= nod;
        b /= nod;

        nod = NOD(a, b);
    }
}

RationalNumber::RationalNumber()
{
    a = 0;
    b = 1;
}

RationalNumber::RationalNumber(const int& a)
{
    this->a = a;
    b = 1;
}

RationalNumber::RationalNumber(const int& a, const int& b)
{
    this->a = a;
    this->b = (b == 0) ? 1 : b;

    leadToAnIrreducible();

    if (this->b < 0) {
        this->a *= -1;
        this->b *= -1;
    }

}

RationalNumber::RationalNumber(const RationalNumber& otherNumber)
{
    this->a = otherNumber.a;
    this->b = otherNumber.b;
}

RationalNumber RationalNumber::operator+(const RationalNumber& otherNumber)
{
    RationalNumber newNumber = RationalNumber(this->a * otherNumber.b + otherNumber.a * this->b, this->b * otherNumber.b);

    return newNumber;
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& otherNumber)
{

    RationalNumber tmp = *this + otherNumber;

    this->a = tmp.a;
    this->b = tmp.b;

    return *this;
}

RationalNumber RationalNumber::operator-(const RationalNumber& otherNumber)
{
    RationalNumber newNumber = RationalNumber(this->a * otherNumber.b - otherNumber.a * this->b, this->b * otherNumber.b);

    return newNumber;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& otherNumber)
{
    RationalNumber tmp = *this - otherNumber;

    this->a = tmp.a;
    this->b = tmp.b;

    return *this;
}

RationalNumber RationalNumber::operator*(const RationalNumber& otherNumber)
{
    RationalNumber newNumber = RationalNumber(
        this->a * otherNumber.a, this->b * otherNumber.b
    );

    return newNumber;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& otherNumber)
{
    RationalNumber tmp = *this * otherNumber;

    this->a = tmp.a;
    this->b = tmp.b;

    return *this;
}

RationalNumber RationalNumber::operator/(const RationalNumber& otherNumber)
{
    RationalNumber newNumber = RationalNumber(
        this->a * otherNumber.b, this->b * otherNumber.a
    );

    return newNumber;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& otherNumber)
{
    RationalNumber tmp = *this / otherNumber;

    this->a = tmp.a;
    this->b = tmp.b;

    return *this;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& otherNumber)
{
    this->a = otherNumber.a;
    this->b = otherNumber.b;

    return *this;
}

RationalNumber& RationalNumber::operator=(const int& a)
{
    this->a = a;
    this->b = 1;

    return *this;
}

RationalNumber RationalNumber::operator*(const int& a)
{
    RationalNumber newNumber(this->a * a, this->b);

    return newNumber;
}

bool RationalNumber::operator==(const RationalNumber& otherNumber)
{
    return this->a == otherNumber.a && this->b == otherNumber.b;
}

bool RationalNumber::operator==(const int& number)
{
    return this->b == 1 && this->a == number;
}

bool RationalNumber::operator!=(const RationalNumber& otherNumber)
{
    return !(*this == otherNumber);
}

bool RationalNumber::operator!=(const int& number)
{
    return !(*this == number);
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& number)
{
    if (number.a * number.b < 0) os << "-";

    os << abs(number.a) << " / " << abs(number.b);

    return os;
}

QString& operator<<(QString& os, const RationalNumber& number)
{

    os += QString().setNum((number.a));

    if (number.a != 0) {
        os += " / ";
        os += QString().setNum((number.b));
    }
  
    return os;
}
