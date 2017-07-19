#include "QuadEqua.h"

namespace Math
{
	QuadEqua::QuadEqua(int a1, int b1, int c1){
		if (a1 == 0 || b1 == 0 || c1 == 0) {
			a1 = b1 = c1 = 1;
			throw std::runtime_error("���������, ������������ �� ���������� ���� �������, �� �������� ��������� � ���� ���������� �� ��������!\a");
		}
		a = a1;
		b = b1;
		c = c1;

		if (a < 0){ // �� ��, ��� � ��������� ��������� �� -1
			a = Invert(a);
			b = Invert(b);
			c = Invert(c);
		}
	}
	QuadEqua::QuadEqua(const QuadEqua& copy_value){
		a = copy_value.a;
		b = copy_value.b;
		c = copy_value.c;

		if (a < 0) { // �� ��, ��� � ��������� ��������� �� -1
			a = Invert(a);
			b = Invert(b);
			c = Invert(c);
		}
	}
	QuadEqua::QuadEqua(std::istream& is) {
		std::cout << "Enter �: ";
		a = check_input();
		std::cout << "Enter b: ";
		b = check_input();
		std::cout << "Enter c: ";
		c = check_input();
		if (a < 0){ // �� ��, ��� � ��������� ��������� �� -1
			a = Invert(a);
			b = Invert(b);
			c = Invert(c);
		}
	}

	int QuadEqua::Invert(int value) const { // ���������� �������� ��������
		if (value > 0)
			return value*-1;
		else if (value < 0)
			return std::abs(value);

		throw std::runtime_error("�� �����-�� ���������� ����� ��������, ��������� ����� �� ���������� ����� ����. ��������, ��� ������� ������� �!");
	}
	RatNum QuadEqua::X1() const {
		return RatNum(Invert(b) - sqrt(Discriminant()), 2 * a);
	}
	RatNum QuadEqua::X2() const {
		return RatNum(Invert(b) + sqrt(Discriminant()), 2 * a);
	}

	int QuadEqua::check_input(void) const { // ������������ �� ��������� ���������� �������� ����������
		int return_value;
		while (!(std::cin >> return_value) || return_value == 0) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "���� �� ������. ��������� �������: ";
		}
		return return_value;
	}
	std::ostream& operator<<(std::ostream& os, QuadEqua& value){
		system("cls");
		os << "\t\t\t\t";
		if (value.a == 1) {
			os << "x^2";
		}
		else {
			os << value.a << "x^2";
		}

		if (value.b > 0) {
			os << " + ";
		}
		os << value.b << "x";

		if (value.c > 0) {
			os << " + ";
		}
		os << value.c << " = 0" << std::endl;

		os.setf(std::ios_base::fixed, std::ios_base::floatfield);
		os.precision(0);

		os << "D = b*b - 4ac = " << value.Discriminant() << " = " << sqrt(value.Discriminant()) << std::endl;

		if (value.Discriminant() > 0) {
			os << "��� ��� D > 0, � ��������� 2 �������������� �����:" << std::endl;
	
			if (value.X1().get_denumerator() == 1) {
				
				os << "X1 = " << (int)value.X1().get_numerator() << std::endl;
			}
			else if (value.X1().get_denumerator() == value.X1().get_numerator()) {
				os << "X1 = " << 1 << std::endl;
			}
			else {
				os << "X1 = " << (int)value.X1() << " = " << int(value.X1()) << std::endl;
			}

			if (value.X2().get_denumerator() == 1) {
				os << "X2 = " << (int)value.X2().get_numerator() << std::endl;
			}
			else if (value.X2().get_denumerator() == value.X2().get_numerator()) {
				os << "X2 = " << 1 << std::endl;
			}
			else {
				os << "X2 = " << (int)value.X2() << " = " << int(value.X2()) << std::endl;
			}

		}
		else if (value.Discriminant() == 0) {

			os << "��� ��� D = 0, � ��������� 1 �������������� ������:" << std::endl;
			if (value.X1().get_denumerator() == 1) {
				os << "X = " << (int)value.X1().get_numerator() << std::endl;
			}
			else if (value.X1().get_denumerator() == value.X1().get_numerator()) {
				os << "X = " << 1 << std::endl;
			}
			else {
				os << "X = " << (int)value.X1() << " = " << int(value.X1()) << std::endl;
			}
		}

		else {
			os << "��� ��� D < 0, � ��������� ��� �������������� ������." << std::endl;
		}
		return os;
	}
}