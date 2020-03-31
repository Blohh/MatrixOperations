#include "Vector.h"
#include <iostream>

int main() {
	myMaths::Vector a = myMaths::Vector(10);
	a.ones();
	std::cout << a;
	return 0;
}