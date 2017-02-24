#include "QuadEqua.h"

namespace Math
{
	QuadEqua::QuadEqua(int a1, int b1, int c1){
		a = a1;
		b = b1;
		c = c1;
	}
	QuadEqua::QuadEqua(const QuadEqua &copy_value){
		a = copy_value.a;
		b = copy_value.b;
		c = copy_value.c;
	}

	int QuadEqua::Invert(int x) const{
		if (x > 0)
			return x*-1;
		else if (x < 0)
			return std::abs(x);

		cout << "Поздравляю, вы сломали мою программу";
		return 0;
	}
	double QuadEqua::X1() const {
		double numerator = Invert(b) - sqrt(Discriminant());
		double denumerator = 2 * a;
		return numerator / denumerator;
	}
	double QuadEqua::X2() const {
		double numerator = Invert(b) + sqrt(Discriminant());
		double denumerator = 2 * a;
		return numerator / denumerator;
	}

	int check_input(void)
	{
		int x;
		while (!(cin >> x) || x == 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ввод не удался. Повторите попытку: ";
		}

		return x;
	}
	std::ostream& operator<<(std::ostream & os, const QuadEqua &value)
	{
		system("cls");
		os << "\t\t\t\t";
		if (value.a == 1)
			os << "x^2";
		else
			os << value.a << "x^2";

		if (value.b > 0)
			os << "+";
		os << value.b << "x";

		if (value.c > 0)
			os << "+";
		os << value.c << "=0" << endl;
		os << "D = b*b - 4ac = " << value.b*value.b << "-" << "4*" << value.a << "*" << value.c << " = " << value.b*value.b << "-" << 4*value.a*value.c << "=" << value.Discriminant() << endl;
		if (value.Discriminant() > 0)
		{
			os << "Так как D > 0, у уравнения 2 действительных корня:" << endl;
			os << "X1 = " << value.X1() << endl;
			os << "X2 = " << value.X2() << endl;
		}
		else if (value.Discriminant() == 0)
		{
			os << "Так как D = 0, у уравнения 1 действительный корень:" << endl;
			os << "X = " << value.X1() << endl;
		}
		else
			os << "Так как D < 0, у уравнения нет действительных корней." << endl;
		return os;
	}
}