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
		int a; // ����������� ����� x^2
		int b; // ����������� ����� x
		int c; // ��������� ���� 

		int Invert(int) const; // ���������� �������� ��������
		inline int Discriminant() const {
			return b*b - 4*a*c;
		}
		int check_input(void) const; // ������������ �� ��������� ���������� �������� ����������
	public:
		QuadEqua(int, int, int);
		QuadEqua(std::istream&);
		QuadEqua(const QuadEqua&);

		RatNum X1() const; // ������ ������(������������ �����)
		RatNum X2() const; // ������ ������(������������ �����)

		friend std::ostream& operator<<(std::ostream&,  QuadEqua&);
	};
}
using namespace Math;
#endif