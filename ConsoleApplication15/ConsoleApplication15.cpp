// ConsoleApplication15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cassert>

using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:

	Fraction(int newNumerator, int newDenominator)
		: numerator{ newNumerator }, denominator{ newDenominator }
	{
		if (newDenominator == 0)
		{
			cout << "Error";
			exit(0);
		}
	}

	Fraction() : Fraction(1, 1) {}

	Fraction(const Fraction& cop)
		: numerator{ cop.numerator },
		denominator{ cop.denominator } {}

	friend Fraction operator+(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator *
		right.denominator +
		right.numerator *
		left.denominator,
		left.denominator *
		right.denominator };
	}

	friend Fraction operator-(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator * right.denominator -
		right.numerator * left.denominator,
		left.denominator * right.denominator };
	}

	friend Fraction operator*(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator *
		right.numerator, left.denominator *
		right.denominator };
	}

	friend Fraction operator/(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator * right.denominator,
		left.denominator * right.numerator };
	}

	void print()
	{
		cout << '(' << numerator << " / "
			<< denominator << ")";
	}

	~Fraction() {}
};

class Complex
{
private:
	double re, im;
public:


	Complex(double nRe, double nIm) :
		re{ nRe }, im{ nIm } {}
	Complex() : Complex(0.16, 0.26) {}


	Complex(const Complex& c)
	{
		re = c.re;
		im = c.im;
	}

	Complex operator+ (const Complex& c)
	{
		return Complex(re + c.re, im + c.im);
	}


	Complex operator- (const Complex& c)
	{
		return Complex(re - c.re, im - c.im);
	}


	Complex operator* (const Complex& c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	Complex operator/ (const Complex& c)
	{
		Complex t;

		double r = c.re * c.re + c.im * c.im;
		t.re = (re * c.re + im * c.im) / r;
		t.im = (im * c.re - re * c.im) / r;

		return t;
	}
	friend ostream& operator«(ostream&, const Complex&);
	friend istream& operator»(istream&, Complex&);

};

ostream& operator«(ostream& out, const Complex& c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

istream& operator»(istream& in, Complex& c)
{
	in >> c.re >> c.im;
	return in;
}

class Overcoat
{
	char* tipod;
	int cena;
public:
	Overcoat(const char* newTipod, int newCena) : tipod{ newTipod ? new char[strlen(newTipod) + 1] : nullptr }, cena{ newCena }
	{
		if (tipod)
		{
			strcpy_s(tipod, strlen(newTipod) + 1, newTipod);
		}
	}

	Overcoat() : Overcoat("Тип", 0) {}

	friend bool operator==(const Overcoat& x, const Overcoat& y);
	friend bool operator!=(const Overcoat& x, const Overcoat& y);
	friend bool operator>(const Overcoat& x, const Overcoat& y);
	friend bool operator<(const Overcoat& x, const Overcoat& y);
	friend istream& operator>>(istream& out, Overcoat& object);
	friend ostream& operator<<(ostream& out, const Overcoat& object);

	Overcoat& operator=(const Overcoat& object)
	{
		if (!(this == &object))
		{
			if (tipod != object.tipod)
			{
				delete[] tipod;
				tipod = object.tipod;
			}
			cena = object.cena;
		}
		return *this;
	}

};

bool operator==(const Overcoat& x, const Overcoat& y)
{
	return x.tipod == y.tipod;
}

bool operator!=(const Overcoat& x, const Overcoat& y)
{
	return !(x.tipod == y.tipod);
}

bool operator>(const Overcoat& x, const Overcoat& y)
{
	return x.cena > y.cena;
}

bool operator<(const Overcoat& x, const Overcoat& y)
{
	return x.cena < y.cena;
}

istream& operator>>(istream& out, Overcoat& object)
{
	out >> object.tipod >> object.cena;
	return out;
}

ostream& operator<<(ostream& out, const Overcoat& object)
{
	out << "Тип одежды: " << object.tipod << "\nЦена: " << object.cena;
	return out;
}

class Flat
{
	int cena;
	int S;
public:
	Flat(int newCena, int newS) : cena{ newCena }, S{ newS } {}

	Flat() : Flat(0, 0) {}

	Flat(const Flat& cop) : cena{ cop.cena } {}

	friend bool operator==(const Flat& lhs, const Flat& rhs)
	{
		return lhs.S == rhs.S;
	}

	friend bool operator!=(const Flat& lhs, const Flat& rhs)
	{
		return !(lhs.S == rhs.S);
	}

	friend bool operator>(const Flat& lhs, const Flat& rhs)
	{
		return lhs.cena > rhs.cena;
	}

	friend bool operator<(const Flat& lhs, const Flat& rhs)
	{
		return lhs.cena < rhs.cena;
	}

	Flat& operator=(const Flat& object)
	{
		if (!(this == &object))
		{
			cena = object.cena;
			S = object.S;
		}
		return *this;
	}

	void print() const
	{
		cout << "\nЦена: " << cena << "\nПлощадь: " << S;
	}

	~Flat() {}

};

class String
{
	char* str;
	int x;
public:
	String(int x) : str{ new char[x + 1] } {}

	String() : String(80) {}

	String(const String& object) : str{ new char[object.x + 1] } {}

	void add(const char* nStr) { str ? strcpy_s(str, strlen(str), nStr) : 0; }

	~String() { str = nullptr; }

	void print() const
	{
		cout << str;
	}
};

template <class T>

class MyArray
{
	size_t size;
	T* arr;
public:
	MyArray(size_t size)
	{
		this->size = size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 10;

	}

	MyArray(const MyArray& object) : size{ object.size }, arr{ object.arr } {}

	size_t getSize()
	{
		return size;
	}

	void push_back(T newItem)
	{
		T* newArr = new T[size + 1];
		for (auto i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		newArr[size] = newItem;
		arr = newArr;
		size++;
	}

	void print()
	{
		for (auto i = 0; i < size; i++)
		{
			cout « arr[i] « " ";
		}
	}

	void Append(MyArray otherArr)
	{
		for (auto i = 0; i < size; i++)
		{
			cout « arr[i] « " ";
		}
		for (auto i = 0; i < otherArr.size; i++)
		{
			cout « otherArr.arr[i] « " ";
		}
	}

};

class Date
{
	int den;
	int mec;
	int god;
	friend int operator-(Date& object1, Date& object2);
	friend int operator+(Date& object1, Date& object2);
public:
	Date(int nDen, int nMec, int nGod) : den{ nDen }, mec{ nMec }, god{ nGod } {}

	Date() : Date(0, 0, 0) {}

	void print()
	{
		cout << den << "." << mec << "." << god;
	}


};

int operator-(Date& object1, Date& object2)
{
	return (object1.den - object2.den) + (object1.mec - object2.mec) * 30 + (object1.god - object2.god) * 365;
}

int operator+(Date& object1, Date& object2)
{
	return object1.den + object2.den + (object1.mec + object2.mec) * 30 + (object1.god + object2.god) * 365;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

}
