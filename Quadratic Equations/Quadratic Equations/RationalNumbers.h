#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>
typedef unsigned int long_int;
namespace RATIONAL_NUMBERS
{
	class RatNum
	{
	protected:
		double numerator;
		double denumerator;

		RatNum& Reduction();
		
		double NOK(int, int) const; // наименьшее общее кратное
		double NOD(int, int) const; // наименьший общий делитель
	public:
		RatNum();
		RatNum(int, long_int);
		RatNum(const RatNum&);
		RatNum(double, double);
		~RatNum();
		
		operator double();
		operator long_int();

		inline double get_numerator()
		{
			return numerator;
		}
		inline double get_denumerator()
		{
			return denumerator;
		}

		RatNum operator+(const RatNum&) const;
		RatNum operator*(const RatNum&) const;
		RatNum operator-(const RatNum&) const;
		RatNum operator/(const RatNum&) const;
		RatNum& operator=(const RatNum&);

		friend std::ostream& operator<<(std::ostream&, const RatNum&);
	};
}
using namespace RATIONAL_NUMBERS;
#endif