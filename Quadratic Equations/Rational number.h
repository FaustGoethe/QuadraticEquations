#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>

namespace RATIONAL_NUMBERS
{
	template<typename T>
	class RatNum
	{
	protected:
		T numerator;
		T denominator;

		RatNum& Reduction() {
			T nod = NOD(numerator, denominator);
			numerator /= nod;
			denominator /= nod;

			return *this;
		}

		T NOD(T lhs, T rhs) const {
			int a = lhs;
			int b = rhs;

			if (a < 0) {
				a *= -1;
			}
			while (b){
				a %= b;
				std::swap(a, b);
			}
			return a;
		} 
		T NOK(T lhs, T rhs) const {
			auto a = lhs;
			auto b = rhs;

			return a*b / NOD(a, b);
		}
	public:
		RatNum();
		RatNum(T, T);
		RatNum(const RatNum&);

		RatNum operator+(const RatNum& vv) const;
		RatNum operator-(const RatNum& vv) const;
		RatNum operator*(const RatNum& vv) const;
		RatNum operator/(const RatNum& vv) const;
		RatNum& operator=(const RatNum& vv);

		operator double() const;
		operator int() const;

		inline T get_numerator() const {
			return numerator;
		}
		inline T get_denominator() const {
			return denominator;
		}

		friend std::ostream& operator<<(std::ostream& os, const RatNum<T>& vv) {
			if (vv.numerator == vv.denominator) {
				return os << 1;
			}
			if (vv.denominator == 1) {
				return os << vv.numerator;
			}
			if (typeid(T).name() == "double") {
				os.setf(std::ios_base::fixed, std::ios_base::floatfield);
				os.precision(1);
			}
			return os << vv.numerator << "/" << vv.denominator << 
				" = " << T(vv.numerator / vv.denominator);
		}
	};
}
namespace RTNUM = RATIONAL_NUMBERS;
#endif