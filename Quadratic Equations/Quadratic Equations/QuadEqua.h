#pragma once
#ifndef _QUAD_EQUA_H
#define _QUAD_EQUA_H

#include <iostream>
#include <conio.h>
#include "RationalNumbers.h"

namespace Math
{
	class QuadEqua : protected RatNum
	{
	private:
		double a; // Коэффициент перед x^2
		double b; // Коэффициент перед x
		double c; // Свободный член 

		double Invert(double) const; // Возвращает обратное значение
		inline double Discriminant() const {
			return b*b - 4*a*c;
		}
		double check_input(void) const; // Соответсвует ли введенная переменная заданным параметрам
	public:
		QuadEqua(double, double, double);
		QuadEqua(std::istream&);
		QuadEqua(const QuadEqua&);

		RatNum X1() const; // Первый корень(рациональная дробь)
		RatNum X2() const; // Второй корень(рациональная дробь)

		friend std::ostream& operator<<(std::ostream&,  QuadEqua&);
	};
}
using namespace Math;
#endif