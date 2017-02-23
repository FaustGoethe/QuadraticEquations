#include <iostream>
#include <conio.h>

double Invert(double x)
{
	if (x > 0)
		return x*-1;
	if (x < 0)
		return std::abs(x);
}

int D(double a, double b, double c)
{
	int descriminant = b*b - 4*a*c;
	return descriminant;
}

double X1(double a, double b, double c)
{
	double numerator = Invert(b) - sqrt(D(a,b,c));
	double denumerator = 2 * a;
	return numerator/denumerator;
}

double X2(double a, double b, double c)
{
	double numerator = Invert(b) + sqrt( D(a,b,c) );
	double denumerator = 2 * a;
	return numerator / denumerator;
}

void F(double a, double b, double c)
{
	if (D(a,b,c) > 0)
	{
		std::cout << "X1 = " << X1(a,b,c) << ", X2 = " << X2(a,b,c) << std::endl;
	}
	else if (D(a,b,c) == 0)
	{
		std::cout << "X = " << X1(a,b,c) << std::endl;
	}
	else 
		std::cout << "Дискриминант меньше нуля, корней нет." << std::endl;
}

double check_input(char name)
{
	double x;
	std::cout << "Enter " << name << ":" ;
	while (!(std::cin >> x) || x == 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Enter " << name << ": ";
	}
	return x;
}

void cout_eq(double a, double b, double c)
{
	system("cls");
	if(a == 1)
		std::cout << "x^2";
	else if(a != 1)
		std::cout << a << "x^2";

	if (b > 0)
		std::cout << "+";
	else if(b < 0)
		std::cout << b << "x";

	if (c > 0)
		std::cout << "+" << c << "=0" << std::endl;
	else if (c < 0)
		std::cout << c << "=0" << std::endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	double a = check_input('a');
	double b = check_input('b');
	double c = check_input('c');
	cout_eq(a, b, c);
	F(a, b, c);
	_getch();
	return 0;
}