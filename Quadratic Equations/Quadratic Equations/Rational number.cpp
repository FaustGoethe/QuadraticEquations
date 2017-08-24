#include "Rational number.h"

namespace RATIONAL_NUMBERS {

	template<typename T> RatNum<T>::RatNum()
		: numerator(1),
		  denominator(1){};
	template<typename T> RatNum<T>::RatNum(T num, T denom) {
		if (denom != 0) {
			numerator = num;
			denominator = denom;
			Reduction();
		}
		else {
			numerator = denominator = 1;
		}
	}
	template<typename T> RatNum<T>::RatNum(const RatNum<T>& vv) {
		numerator = vv.numerator;
		denominator = vv.denominator;
		Reduction();
	}

	template<typename T> RatNum<T> RatNum<T>::operator+(const RatNum& vv) const {
		if (denominator == vv.denominator) {
			return { numerator + vv.numerator, denominator };
		}

		auto lcm = NOK(denominator, vv.denominator);
		auto x = lcm / denominator;
		auto y = lcm / vv.denominator;

		return { numerator*x + vv.numerator*y, lcm };
	}
	template<typename T> RatNum<T> RatNum<T>::operator-(const RatNum& vv) const {
		return { numerator, denominator } +{-vv.numerator, vv.denominator};
	}
	template<typename T> RatNum<T> RatNum<T>::operator*(const RatNum& vv) const {
		return { numerator * vv.numerator, denominator * vv.denominator };
	}
	template<typename T> RatNum<T> RatNum<T>::operator/(const RatNum& vv) const {
		return { numerator * vv.denominator, denominator * vv.numerator };
	}
	template<typename T> RatNum<T>& RatNum<T>::operator=(const RatNum& vv) {
		numerator = vv.numerator;
		denominator = vv.denominator;
		return *this;
	}

	template<typename T> RatNum<T>::operator double()const {
		return (double)numerator / (double)denominator;
	}
	template<typename T> RatNum<T>::operator int() const {
		return (int)numerator / (int)denominator;
	}
}