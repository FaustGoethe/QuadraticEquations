#pragma once
#ifndef _QUAD_EQUA_H
#define _QUAD_EQUA_H

#include <iostream>
#include <conio.h>
#include "Rational number.h"
#include "Rational number.cpp"

namespace Math
{
	template<typename T = int>
	class QuadEqua
	{
	private:
		T a; // Коэффициент перед x^2
		T b; // Коэффициент перед x
		T c; // Свободный член 

		T Invert(T value) const {
			return value > 0 ? value*-1 : std::abs(value);
			
			throw std::runtime_error("По каким-то неведанным ранее причинам, программа дошла до выполнения этого кода. Вероятно, вам удалось сломать её!");
		}
		inline int Discriminant() const {
			return b*b - 4*a*c;
		}
		
	public:
		QuadEqua() 
			:a(1), 
			b(1), 
			c(1) {};
		QuadEqua(T aa, T bb, T cc) {
			if (aa == 0 || bb == 0 || cc == 0) {
				aa = bb = cc = 1;
				throw std::runtime_error("Уравнение, составленное по введенными вами данными, не является квадатным и этой программой не решается!\a");
			}
			a = aa;
			b = bb;
			c = cc;

			if (a < 0) { 
				a = Invert(a);
				b = Invert(b);
				c = Invert(c);
			}
		}
		QuadEqua(const QuadEqua& cp) {
			a = cp.a;
			b = cp.b;
			c = cp.c;
		}

		RTNUM::RatNum<T> X1() const {
			return { T(Invert(b) - sqrt(Discriminant())), 2 * a };
		}
		RTNUM::RatNum<T> X2() const {
			return { T(Invert(b) + sqrt(Discriminant())), 2 * a };
		}

		friend std::ostream& operator<<(std::ostream& os, QuadEqua& value) {

			system("cls");
			os << "\t\t\t\t";
			if (value.a == 1) {
				os << "x^2";
			}
			else {
				os << value.a << "x^2";
			}

			if (value.b > 0) {
				os << " + ";
			}
			os << value.b << "x";

			if (value.c > 0) {
				os << "+";
			}
			os << value.c << "=0" << std::endl;

			os.setf(std::ios_base::fixed, std::ios_base::floatfield);
			os.precision(0);

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
					os << "X1 = " << value.X1() << " = " << value.X1() << std::endl;
				}

				if (value.X2().get_denominator() == 1) {
					os << "X2 = " << value.X2().get_numerator() << std::endl;
				}
				else if (value.X2().get_denominator() == value.X2().get_numerator()) {
					os << "X2 = " << 1 << std::endl;
				}
				else {
					os << "X2 = " << value.X2() << " = " << value.X2() << std::endl;
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
					os << "X = " << value.X1() << " = " << value.X1() << std::endl;
				}
			}

			else {
				os << "Так как D < 0, у уравнения нет действительных корней." << std::endl;
			}
			return os;
		}
	};
}
using namespace Math;
#endif