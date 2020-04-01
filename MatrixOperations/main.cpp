#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>

int main() {
	try {
		myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, 5);
		myMaths::Vector vt = myMaths::LineralEquation::generateVector(5, 5);
		std::cout << mat << std::endl << vt << std::endl;
		myMaths::Vector x = myMaths::LineralEquation::Gauss(mat, vt);
		std::cout << x;
		std::cout << mat * x;
	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}