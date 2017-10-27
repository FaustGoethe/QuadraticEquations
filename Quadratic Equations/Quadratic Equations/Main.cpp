#include <iostream>
#include <conio.h>
#include "QuadEqua.h"

int main(int argc, char* argv[]){
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	std::cin >> a >> b >> c;

	try{
		QuadEqua<int> eq(a, b, c);
		std::cout << eq;
	}
	catch (const std::runtime_error& a){
		std::cout << a.what();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
	_getch();
	return 0;
}
