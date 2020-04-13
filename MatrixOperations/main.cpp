#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>

int main() {
	try {
		/* Ex A */
		myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, 5);
		myMaths::Vector vt = myMaths::LineralEquation::generateVector(5, 5);
		std::cout << "Matrix\n" << mat << std::endl << "Vector: \n" << vt << std::endl;
		myMaths::Vector x = myMaths::LineralEquation::Gauss(mat, vt);
		/* Ex B */
		std::cout << "Answer (Gauss): "<< x << std::endl;
		std::cout << "A*x - b " << mat * x - vt << std::endl;
		myMaths::Vector x2 = myMaths::LineralEquation::Jacobi(mat, vt);
		std::cout << "Answer (Jacobi): " << x2 << std::endl;
		std::cout << "A * x - b " <<  mat * x2 - vt << std::endl;
		std::cout << "Iterations (Jacobi): " << myMaths::LineralEquation::getJacobiIterations() << std::endl;
		myMaths::Vector x3 = myMaths::LineralEquation::GaussSeidle(mat, vt);
		std::cout << "Answer (Gauss-Seidle): " << x3 << std::endl;
		std::cout << "A * x - b " << mat * x3 - vt << std::endl;
		std::cout << "Iterations (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleIterations() << std::endl;
	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}