#pragma once
#ifndef _QUAD_EQUA_H
#define _QUAD_EQUA_H
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace Math
{
	class QuadEqua
	{
	private:
		int a;
		int b;
		int c;

		int Invert(int) const;
	public:
		QuadEqua(int,int,int);
		QuadEqua(const QuadEqua&);

		inline int Discriminant() const{
			return b*b - 4 * a*c;
		}
		double X1() const;
		double X2() const;

		friend int check_input(void);
		friend std::ostream& operator<<(std::ostream&, const QuadEqua&);
	};
}
using namespace Math;
#endif