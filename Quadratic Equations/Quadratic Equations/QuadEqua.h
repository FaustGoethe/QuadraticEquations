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
		int a; // Коэффициент перед x^2
		int b; // Коэффициент перед x
		int c; // Свободный член 

		int Invert(int) const; // Возвращает обратное значение
		inline int Discriminant() const {
			return b*b - 4*a*c;
		}
		int check_input(void) const; // Соответсвует ли введенная переменная заданным параметрам
	public:
		QuadEqua(int, int, int);
		QuadEqua(std::istream&);
		QuadEqua(const QuadEqua&);

		RatNum X1() const; // Первый корень(рациональная дробь)
		RatNum X2() const; // Второй корень(рациональная дробь)

		friend std::ostream& operator<<(std::ostream&,  QuadEqua&);
	};
}
using namespace Math;
#endif