#pragma once
#ifndef _QUAD_EQUA_H
#define _QUAD_EQUA_H
#include <iostream>
#include <conio.h>
#include"RationalNumbers.h"

using std::cin;
using std::cout;
using std::endl;

namespace Math
{
	class QuadEqua : private RatNum
	{
	private:
		double a;
		double b;
		double c;

		double Invert(double) const; // ���������� �������� ��������
		inline double Discriminant() const {
			return b*b - 4*a*c;
		}
		double check_input(void) const; // ������������ �� ��������� ���������� �������� ����������
	public:
		QuadEqua(double, double, double);
		QuadEqua(std::istream&);
		QuadEqua(const QuadEqua&);

		RatNum X1() const; // ������ ������(������������ �����)
		RatNum X2() const; // ������ ������(������������ �����)

		friend std::ostream& operator<<(std::ostream&,  QuadEqua&);
	};
}
using namespace Math;
#endif