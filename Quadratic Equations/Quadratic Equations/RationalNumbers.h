#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>

namespace RATIONAL_NUMBERS{
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
		RatNum(int, size_t);
		RatNum(const RatNum&);
		RatNum(double, double);
		
		operator double() const; // Возврат дроби в в виде десятичной дроби(numerator / denumerator) 
		operator int() const; // Возврат дроби в в виде десятичной дроби(numerator / denumerator)

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