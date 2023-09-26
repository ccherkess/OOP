#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	a = 0;
	b = 0;
}

ComplexNumber::ComplexNumber(const double& a)
{
	this->a = a;
	this->b = 0;
}

ComplexNumber::ComplexNumber(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
}

ComplexNumber::ComplexNumber(const ComplexNumber& otherNumber)
{
	this->a = otherNumber.a;
	this->b = otherNumber.b;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& otherNumber)
{
	ComplexNumber newNumber(this->a + otherNumber.a, this->b + otherNumber.b);

	return  newNumber;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& otherNumber)
{
	*this = *this + otherNumber;

	return *this;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& otherNumber)
{
	ComplexNumber newNumber(this->a - otherNumber.a, this->b - otherNumber.b);

	return  newNumber;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& otherNumber)
{
	*this = *this - otherNumber;

	return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& otherNumber)
{
	ComplexNumber newNumber;

	newNumber.a = (this->a * otherNumber.a - this->b * otherNumber.b);
	newNumber.b = (this->a * otherNumber.b + this->b * otherNumber.a);

	return  newNumber;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& otherNumber)
{
	*this = *this * otherNumber;

	return *this;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& otherNumber)
{
	ComplexNumber newNumber;
	
	newNumber.a = ((this->a * otherNumber.a + this->b * otherNumber.b)
		/ (otherNumber.a * otherNumber.a + otherNumber.b * otherNumber.b));
	
	newNumber.b = ((this->b * otherNumber.a - this->a * otherNumber.b)
			/ (otherNumber.a * otherNumber.a + otherNumber.b * otherNumber.b));

	return  newNumber;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& otherNumber)
{
	*this = *this / otherNumber;

	return *this;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& otherNumber)
{
	this->a = otherNumber.a;
	this->b = otherNumber.b;

	return  *this;
}

ComplexNumber& ComplexNumber::operator=(const double& real)
{
	this->a = real;
	this->b = 0;

	return  *this;
}

bool ComplexNumber::operator==(const ComplexNumber& otherNumber)
{
	return this->a == otherNumber.a && this->b == otherNumber.b;
}

bool ComplexNumber::operator==(const double& number)
{
	return this->a == number;
}

bool ComplexNumber::operator!=(const ComplexNumber& otherNumber)
{
	return !(*this == otherNumber);
}

bool ComplexNumber::operator!=(const double& number)
{
	return this->a != number;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number)
{
	os << number.a << " + i(" << number.b << ")";

	return os;
}

std::istream& operator>>(std::istream& os, ComplexNumber& number)
{
	os >> number.a;
	os >> number.b;

	return os;
}