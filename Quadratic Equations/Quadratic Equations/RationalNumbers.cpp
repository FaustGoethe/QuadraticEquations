#include "RationalNumbers.h"

namespace RATIONAL_NUMBERS{
	RatNum::RatNum() :numerator(1.0), denumerator(1.0){};
	RatNum::RatNum(const RatNum& v) :numerator(v.numerator), denumerator(v.denumerator){};
	RatNum::RatNum(int n, size_t d){
		if (d != 0)
		{
			numerator = n;
			denumerator = d;
			Reduction();
		}
		else {
			std::cout << "Error: denumerator can't be negative number!";
			 denumerator = 1;
		}
	}
	RatNum::RatNum(double n, double d){
		if (d != 0.0)
		{
			numerator = n;
			denumerator = d;
			Reduction();
		}
		else {
			std::cout << "Error: denumerator can't be negative number!";
			denumerator = 1;
		}
	}

	double RatNum::NOD(int a, int b) const{
		if (a < 0)
			a *= -1;
		 while (b)
		 {
			 a %= b;
			 std::swap(a, b);
		 }
		return a; 
	}
	double RatNum::NOK(int a, int b) const{
		return a*b / NOD(a, b);
	}

	RatNum::operator double() const{
		return (double)numerator / (double)denumerator;
	}
	RatNum::operator int() const {
		return (int)numerator / int(denumerator);
	}
	RatNum& RatNum::Reduction(){
		double nod = NOD(numerator, denumerator);
		numerator /= nod;
		denumerator /= nod;
		return *this;
	}

	RatNum RatNum::operator+(const RatNum& v) const{
		RatNum result;
		if (denumerator == v.denumerator)
		{
			result.denumerator = denumerator;
			result.numerator = numerator + v.numerator;
			result.Reduction();
			return result;
		}
		double lcm = NOK(denumerator, v.denumerator);
		double x = lcm / denumerator;
		double y = lcm / v.denumerator;
		result.denumerator = lcm;
		result.numerator = numerator*x + v.numerator*y;
		result.Reduction();
		return result;
	}
	RatNum RatNum::operator-(const RatNum& v) const{
		return RatNum(numerator, denumerator) + RatNum(-v.numerator, v.denumerator);
	}
	RatNum RatNum::operator*(const RatNum& v) const{
		return RatNum(numerator*v.numerator,denumerator*v.denumerator);
	}
	RatNum RatNum::operator/(const RatNum& v) const{
		return RatNum(numerator*v.denumerator, denumerator*v.numerator);
	}
	RatNum& RatNum::operator=(const RatNum& v){
		numerator = v.numerator;
		denumerator = v.denumerator;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const RatNum& Value){
		os.precision(3);
		os << Value.numerator << "/" << Value.denumerator;
		return os;
	}
}