#include <iostream>
#include <conio.h>
#include "QuadEqua.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	QuadEqua c(1, -30, 225);
	cout << c;
	_getch();
	return 0;
}
