#pragma once
#include <iostream>
#include <QString>
#include <QByteArray>

class ComplexNumber
{
public:

	ComplexNumber();

	ComplexNumber(const double& a);

	ComplexNumber(const double& a, const double& b);

	ComplexNumber(const ComplexNumber& otherNumber);

	ComplexNumber(const QByteArray& arr);

	ComplexNumber operator + (const ComplexNumber& otherNumber);

	ComplexNumber& operator += (const ComplexNumber& otherNumber);
	
	ComplexNumber operator - (const ComplexNumber& otherNumber);

	ComplexNumber& operator -= (const ComplexNumber& otherNumber);

	ComplexNumber operator * (const ComplexNumber& otherNumber);

	ComplexNumber& operator *= (const ComplexNumber& otherNumber);

	ComplexNumber operator / (const ComplexNumber& otherNumber);

	ComplexNumber& operator /= (const ComplexNumber& otherNumber);

	ComplexNumber& operator = (const ComplexNumber& otherNumber);

	ComplexNumber& operator = (const double& real);

	bool operator == (const ComplexNumber& otherNumber);

	bool operator == (const double& number);

	bool operator != (const ComplexNumber& otherNumber);

	bool operator != (const double& number);

	friend std::ostream& operator << (std::ostream& os, const ComplexNumber& number);

	friend std::istream& operator >> (std::istream& os, ComplexNumber& number);

	friend QString& operator<<(QString& os, const ComplexNumber& number);

	friend QByteArray& operator>>(QByteArray& arr, ComplexNumber& number);

private:

	double a; //real part
	double b; //image part

	static QChar SEPARATOR;

};

