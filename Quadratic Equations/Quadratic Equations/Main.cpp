#include <iostream>
#include <conio.h>
#include "QuadEqua.h"

int main(int argc, char* argv[]){
	setlocale(LC_ALL, "Russian");
	QuadEqua<int> c(1,-26,120);
	
	//std::cout << double(c.X2());
	try{
		std::cout << c;
	}
	catch (std::runtime_error a){
		std::cout << a.what();
	}
	_getch();
	return 0;
}
