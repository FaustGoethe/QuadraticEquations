#include "QuadEqua.h"

namespace Math
{
	QuadEqua::QuadEqua(double a1, double b1, double c1){
		if (a1 == 0 || b1 == 0 || c1 == 0) {
			a1 = b1 = c1 = 1;
			throw std::runtime_error("���������, ������������ �� ���������� ���� �������, �� �������� ��������� � ���� ���������� �� ��������!\a");
		}
		a = a1;
		b = b1;
		c = c1;

		if (a < 0){ // ����, ��� � ��������� ��������� �� -1
			a = Invert(a);
			b = Invert(b);
			c = Invert(c);
		}
	}
	QuadEqua::QuadEqua(const QuadEqua& copy_value){
		a = copy_value.a;
		b = copy_value.b;
c = copy_value.c;

if (a < 0) { // ����, ��� � ��������� ��������� �� -1
	a = Invert(a);
	b = Invert(b);
	c = Invert(c);
}
	}
	QuadEqua::QuadEqua(std::istream& is) {

		cout << "������� �: ";
		a = check_input();
		cout << "������� b: ";
		b = check_input();
		cout << "������� c: ";
		c = check_input();
		if (a < 0) // ����, ��� � ��������� ��������� �� -1
		{
			a = Invert(a);
			b = Invert(b);
			c = Invert(c);
		}
	}

	double QuadEqua::Invert(double value) const { // ���������� �������� ��������
		if (value > 0)
			return value*-1;
		else if (value < 0)
			return std::abs(value);

		throw std::runtime_error("�� �����-�� ���������� ����� ��������, ���������� ����� �� ���������� ����� ����. ��������, ��� ������� ������� ��� ���������!");
	}
	RatNum QuadEqua::X1() const {
		return RatNum(Invert(b) - sqrt(Discriminant()), 2 * a);
	}
	RatNum QuadEqua::X2() const {
		return RatNum(Invert(b) + sqrt(Discriminant()), 2 * a);
	}

	double QuadEqua::check_input(void) const { // ������������ �� ��������� ���������� �������� ����������
		double x;
		while (!(cin >> x) || x == double(0)) {

			cin.clear();
			while (cin.get() != '\n');
			cout << "���� �� ������. ��������� �������: ";
		}
		return x;
	}
	std::ostream& operator<<(std::ostream& os, QuadEqua& value)
	{
		/*if (value.Discriminant() > 0) {
			if ((double(value.X1()) + double(value.X2())) * value.a != value.Invert(value.b) || double(value.X1()) * double(value.X2()) * value.a != value.c) {
				cout << "���������� ������������� ��������� ����� �������� � �������. ������ ����������(y/n)?" << endl;
				char c = (char)_getch();
				if (c != 'y' || c != 'Y' || c != '�' || c != '�')
					throw std::runtime_error("����� ��������� �� ����� �������!");
			}

		}*/
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
		os << "D = b*b - 4ac = " << value.Discriminant() << " = " << sqrt(value.Discriminant()) << endl;
		if (value.Discriminant() > 0) {

			os << "��� ��� D > 0, � ��������� 2 �������������� �����:" << endl;

			if (value.X1().get_denumerator() == 1)
				os << "X1 = " << value.X1().get_numerator() << endl;
			else if (value.X1().get_denumerator() == value.X1().get_numerator())
				os << "X1 = " << 1 << endl;
			else
				os << "X1 = " << value.X1() << " = " << double(value.X1()) << endl;


			if (value.X2().get_denumerator() == 1)
				os << "X2 = " << value.X2().get_numerator() << endl;
			else if (value.X2().get_denumerator() == value.X2().get_numerator())
				os << "X2 = " << 1 << endl;
			else
				os << "X2 = " << value.X2() << " = " << double(value.X2()) << endl;


		}
		else if (value.Discriminant() == 0) {

			os << "��� ��� D = 0, � ��������� 1 �������������� ������:" << endl;
			if (value.X1().get_denumerator() == 1)
				os << "X = " << value.X1().get_numerator() << endl;
			else if (value.X1().get_denumerator() == value.X1().get_numerator())
				os << "X = " << 1 << endl;
			else
				os << "X = " << value.X1() << " = " << double(value.X1()) <<  endl;
		}

		else
			os << "��� ��� D < 0, � ��������� ��� �������������� ������." << endl;
		return os;
	}
}