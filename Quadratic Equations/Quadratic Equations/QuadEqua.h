#pragma once
#ifndef _QUAD_EQUA_H
#define _QUAD_EQUA_H

#include <iostream>
#include <conio.h>
#include <string>
#include "Rational number.h"
#include "Rational number.cpp"

namespace Math
{
	template<typename T = double>
	class QuadEqua
	{
	private:
		T a; // Коэффициент перед x^2
		T b; // Коэффициент перед x
		T c; // Свободный член 

		inline T Discriminant() const noexcept{
			return b*b - 4*a*c;
		}
	public:
		QuadEqua() {
			a = b = c = 1;
		}
		QuadEqua(T _a, T _b, T _c) {
			if (_a == 0 || _b == 0 || _c == 0) {
				_a = _b = _c = 1;
				std::cerr << "The equation compiled by the data you have given is not quadratic and the proposed one is not solved!\a" << std::endl;
			}
			a = _a;
			b = _b;
			c = _c;

			if (a < 0) { 
				a = -a;
				b = -b;
				c = -c;
			}
		}
		QuadEqua(const QuadEqua& cp) {
			a = cp.a;
			b = cp.b;
			c = cp.c;
		}

		RTNUM::RatNum<T> X1() const {
			return { T(-b - sqrt(Discriminant())), 2 * a };
		}
		RTNUM::RatNum<T> X2() const {
			return { T(-b + sqrt(Discriminant())), 2 * a };
		}

		std::string get_typename()const noexcept{
			return typeid(T).name();
		}

		friend std::ostream& operator<<(std::ostream& os, const QuadEqua& value) {
			system("cls");
			os << "\t\t\t\t";
			if (value.a == 1) {
				os << "x^2";
			}
			else {
				os << value.a << "x^2";
			}

			if (value.b > 0) {
				os << "+";
			}
			os << value.b << "x";

			if (value.c > 0) {
				os << "+";
			}
			os << value.c << "=0" << std::endl;

			if (std::string(typeid(T).name()) == "double") {
				os.setf(std::ios_base::fixed, std::ios_base::floatfield);
				os.precision(1);
			}
			os << "D = b*b - 4ac = sqrt(" << value.Discriminant() << ") = " << sqrt(value.Discriminant()) << std::endl;

			if (value.Discriminant() > 0) {
				os << "Так как D > 0, у уравнения 2 действительных корня:" << std::endl;

				if (value.X1().get_denominator() == 1) {
					os << "X1 = " << value.X1().get_numerator() << std::endl;
				}
				else if (value.X1().get_denominator() == value.X1().get_numerator()) {
					os << "X1 = " << 1 << std::endl;
				}
				else {
					os << "X1 = " << value.X1() << " = " << double(value.X1()) << std::endl;
				}

				if (value.X2().get_denominator() == 1) {
					os << "X2 = " << value.X2().get_numerator() << std::endl;
				}
				else if (value.X2().get_denominator() == value.X2().get_numerator()) {
					os << "X2 = " << 1 << std::endl;
				}
				else {
					os << "X2 = " << value.X2() << " = " << double(value.X2()) << std::endl;
				}

			}
			else if (value.Discriminant() == 0) {

				os << "Так как D = 0, у уравнения 1 действительный корень:" << std::endl;
				if (value.X1().get_denominator() == 1) {
					os << "X = " << value.X1().get_numerator() << std::endl;
				}
				else if (value.X1().get_denominator() == value.X1().get_numerator()) {
					os << "X = " << 1 << std::endl;
				}
				else {
					os << "X = " << value.X1() << " = " << (T)value.X1() << std::endl;
				}
			}

			else {
				os << "Так как D < 0, у уравнения нет действительных корней." << std::endl;
			}
			return os;
		}
		friend std::istream& operator>>(std::istream& is, QuadEqua<T>& value) {
			std::cout << "Enter a, b, c: ";
			while (!(is >> value.a >> value.b >> value.c) || value.a == 0 || value.b == 0 || value.c == 0) {
				is.clear();
				while (is.get() != '\n');
				std::cerr << "Invalid value\a" << std::endl;
			}
			if(value.a < 0){
				value.a = -value.a;
				value.b = -value.b;
				value.c = -value.c;
			}

			return is;
		}
	};
}
using namespace Math;
#endif