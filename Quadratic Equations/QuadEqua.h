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

		std::ostream& PrintEquation() const {
			std::cout << "\t\t\t\t";
			if (a == 1) {
				std::cout << "x^2";
			}
			else {
				std::cout << a << "x^2";
			}

			if (b > 0) {
				std::cout << "+";
			}
			std::cout << b << "x";

			if (c > 0) {
				std::cout << "+";
			}
			std::cout << c << "=0" << std::endl;
			return std::cout;
		}

		friend std::ostream& operator<<(std::ostream& os, const QuadEqua& value) {
			system("cls");
			value.PrintEquation();

			auto D = value.Discriminant();
			os << "D = b*b - 4ac = sqrt(" 
				<< D << ") = " 
				<< sqrt(D) << std::endl;

			if (D > 0) {
				os << "D > 0, equation have 2 rational roots:" << std::endl;

				os << "X1 = " << value.X1() << std::endl;
				os << "X2 = " << value.X2() << std::endl;
			}
			else if (D == 0) {
				os << "D = 0, equation have 1 raional root:" << std::endl;

				os << "X = " << value.X1() << std::endl;
			}

			else {
				os << "D < 0, equation have not rational roots." << std::endl;
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