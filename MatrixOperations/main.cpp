#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>
#include <fstream>
const int c = 5, d = 7, f = 5;
const int N = 9 * c * d;
void exAB();
void exC();
void exD();
void exE();
int main() {
	try {
		exAB();
		exC();
		exD();
		/*exE();*/
	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}
void exAB() {
	/* Ex A */
	std::cout << "Ex B" << std::endl;
	myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, N);
	myMaths::Vector vt = myMaths::LineralEquation::generateVector(N, f);
	/* Ex B */
	myMaths::Vector x1 = myMaths::LineralEquation::Jacobi(mat, vt);
	std::cout << "norm(A * x - b) (Jacobi) " << (mat * x1 - vt).norm() << std::endl;
	std::cout << "Iterations (Jacobi): " << myMaths::LineralEquation::getJacobiIterations() << std::endl;
	std::cout << "Time (Jacobi): " << myMaths::LineralEquation::getJacobiTime() << " s." << std::endl << std::endl;
	myMaths::Vector x2 = myMaths::LineralEquation::GaussSeidle(mat, vt);
	std::cout << "norm(A * x - b) (Gauss-Seidle) " << (mat * x2 - vt).norm() << std::endl;
	std::cout << "Iterations (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleIterations() << std::endl;
	std::cout << "Time (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleTime() << " s." << std::endl << std::endl;
}
void exC() {
	std::cout << "\n\n\nEx C" << std::endl;
	myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(3, -1, -1, N);
	myMaths::Vector vt = myMaths::LineralEquation::generateVector(N, f);
	myMaths::Vector x1 = myMaths::LineralEquation::Jacobi(mat, vt);
	std::cout << "norm(A * x - b) (Jacobi) " << (mat * x1 - vt).norm() << std::endl;
	std::cout << "Iterations (Jacobi): " << myMaths::LineralEquation::getJacobiIterations() << std::endl;
	std::cout << "Time (Jacobi): " << myMaths::LineralEquation::getJacobiTime() << " s." << std::endl << std::endl;
	myMaths::Vector x2 = myMaths::LineralEquation::GaussSeidle(mat, vt);
	std::cout << "norm(A * x - b) (Gauss-Seidle) " << (mat * x2 - vt).norm() << std::endl;
	std::cout << "Iterations (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleIterations() << std::endl;
	std::cout << "Time (Gauss-Seidle): " << myMaths::LineralEquation::getGaussSeidleTime() << " s." << std::endl << std::endl;
}
void exD() {
	std::cout << "\n\n\nEx D" << std::endl;
	myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(3, -1, -1, N);
	myMaths::Vector vt = myMaths::LineralEquation::generateVector(N, f);
	myMaths::Vector x = myMaths::LineralEquation::LUFactorization(mat, vt);
	std::cout << "norm(A * x - b) (LU factorization) " << (mat * x - vt).norm() << std::endl;
}
void exE() {
	std::vector<double>N = { 100,500,1000,2000,3000 };
	std::vector<double>timeJacobi(N.size()), timeGaussSeidle(N.size()), timeLU(N.size());

	std::ofstream file;
	file.open("exE.txt");
	if (!file.good() ){
		return;
	}
	std::cout << "Jacobi calculating... \n i=";
	for (int i = 0; i < N.size(); i++) {
		std::cout << i << "...";
		myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, N[i]);
		myMaths::Vector vt = myMaths::LineralEquation::generateVector(N[i], f);

		myMaths::Vector x1 = myMaths::LineralEquation::Jacobi(mat, vt);
		timeJacobi[i]= myMaths::LineralEquation::getJacobiTime();
	}
	std::cout << "\nJacobi: \n [ ";
	for (int i = 0; i < N.size(); i++) {
		std::cout << timeJacobi[i] << ", ";
		file << timeJacobi[i] << " ";
	}
	std::cout << " ]\n";
	file << std::endl;
	std::cout << "Gauss-Seidle calculating... \n i=";
	for (int i = 0; i < N.size(); i++) {
		std::cout << i << "...";
		myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, N[i]);
		myMaths::Vector vt = myMaths::LineralEquation::generateVector(N[i], f);


		myMaths::Vector x2 = myMaths::LineralEquation::GaussSeidle(mat, vt);
		timeGaussSeidle[i] = myMaths::LineralEquation::getGaussSeidleTime();

	}
	std::cout << "\nGauss-Seidle: \n [ ";
	for (int i = 0; i < N.size(); i++) {
		std::cout << timeGaussSeidle[i] << ", ";
		file << timeGaussSeidle[i] << " ";
	}
	std::cout << " ]\n";
	file << std::endl;
	std::cout << "LU calculating... \n i=";
	for (int i = 0; i < N.size(); i++) {
		std::cout << i << "...";
		myMaths::Matrix mat = myMaths::LineralEquation::generateEquation(12, -1, -1, N[i]);
		myMaths::Vector vt = myMaths::LineralEquation::generateVector(N[i], f);

		myMaths::Vector x3 = myMaths::LineralEquation::LUFactorization(mat, vt);
		timeLU[i] = myMaths::LineralEquation::getLUTime();
	}
	std::cout << "\nLU: \n [ ";
	for (int i = 0; i < N.size(); i++) {
		std::cout << timeLU[i] << ", ";
		file << timeLU[i] << " ";
	}
	std::cout << " ]\n";
	file << std::endl;

}