#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>

namespace RATIONAL_NUMBERS
{
	typedef unsigned int long_int;

	class RatNum
	{
	protected:
		double numerator; // Числитель
		double denumerator; // Знаменатель

		RatNum& Reduction(); // Сокращение
		
		double NOK(int, int) const; // наименьшее общее кратное
		double NOD(int, int) const; // наименьший общий делитель
	public:
		RatNum();
		RatNum(int, long_int);
		RatNum(const RatNum&);
		RatNum(double, double);
		~RatNum();
		
		operator double(); // Возврат дроби в в виде десятичной дроби(numerator / denumerator) 
		operator long_int(); // Возврат дроби в в виде десятичной дроби(numerator / denumerator)

		inline double get_numerator(){
			return numerator;
		}
		inline double get_denumerator(){
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