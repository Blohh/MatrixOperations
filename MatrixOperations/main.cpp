#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>
int c = 5, d = 7, f = 5;
int N = 9 * c * d;
void exAB();
void exC();
int main() {
	try {
		exAB();
		exC();

	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}
void exAB() {
	/* Ex A */
	myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, N);
	myMaths::Vector vt = myMaths::LineralEquation::generateVector(N, f);
	/* Ex B */
	myMaths::Vector x1 = myMaths::LineralEquation::Jacobi(mat, vt);
	std::cout << "norm(A * x - b) (Jacobi) " << (mat * x1 - vt).norm() << std::endl;
	std::cout << "Iterations (Jacobi): " << myMaths::LineralEquation::getJacobiIterations() << std::endl;
	std::cout << "Time (Jacobi): " << myMaths::LineralEquation::getJacobiTime() << std::endl << std::endl;
	myMaths::Vector x2 = myMaths::LineralEquation::GaussSeidle(mat, vt);
	std::cout << "norm(A * x - b) (Gauss-Seidle) " << (mat * x2 - vt).norm() << std::endl;
	std::cout << "Iterations (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleIterations() << std::endl;
	std::cout << "Time (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleTime() << std::endl << std::endl;
}
void exC() {

	myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(3, -1, -1, N);
	myMaths::Vector vt = myMaths::LineralEquation::generateVector(N, f);
	myMaths::Vector x1 = myMaths::LineralEquation::Jacobi(mat, vt);
	std::cout << "norm(A * x - b) (Jacobi) " << (mat * x1 - vt).norm() << std::endl;
	std::cout << "Iterations (Jacobi): " << myMaths::LineralEquation::getJacobiIterations() << std::endl;
	std::cout << "Time (Jacobi): " << myMaths::LineralEquation::getJacobiTime() << std::endl << std::endl;
	myMaths::Vector x2 = myMaths::LineralEquation::GaussSeidle(mat, vt);
	std::cout << "norm(A * x - b) (Gauss-Seidle) " << (mat * x2 - vt).norm() << std::endl;
	std::cout << "Iterations (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleIterations() << std::endl;
	std::cout << "Time (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleTime() << std::endl << std::endl;
}
