#include <iostream>
#include <conio.h>
#include "QuadEqua.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	QuadEqua c(std::cin);
	try
	{
		cout << c;
	}
	catch (std::runtime_error a)
	{
		cout << a.what();
	}
	
	_getch();
	return 0;
}
