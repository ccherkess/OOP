#pragma once

#include <iostream>
#include <QString>

class RationalNumber
{
public:

	RationalNumber();

	RationalNumber(const int& a);

	RationalNumber(const int& a, const int& b);

	RationalNumber(const RationalNumber& otherNumber);

	RationalNumber operator + (const RationalNumber& otherNumber);

	RationalNumber& operator += (const RationalNumber& otherNumber);

	RationalNumber operator - (const RationalNumber& otherNumber);

	RationalNumber& operator -= (const RationalNumber& otherNumber);

	RationalNumber operator * (const RationalNumber& otherNumber);

	RationalNumber& operator *= (const RationalNumber& otherNumber);

	RationalNumber operator / (const RationalNumber& otherNumber);

	RationalNumber& operator /= (const RationalNumber& otherNumber);

	RationalNumber& operator = (const RationalNumber& otherNumber);

	RationalNumber& operator = (const int& a);

	RationalNumber operator * (const int& a);

	bool operator == (const RationalNumber& otherNumber);

	bool operator == (const int& number);

	bool operator != (const RationalNumber& otherNumber);

	bool operator != (const int& number);

	friend std::ostream& operator << (std::ostream& os, const RationalNumber& number);

	friend QString& operator << (QString& os, const RationalNumber& number);


private:

	int a; //numerator
	int b; //denominator

	int NOD(int a, int b);

	void leadToAnIrreducible();

};

