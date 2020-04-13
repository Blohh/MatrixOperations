#include "LineralEquation.h"
#include <vector>
unsigned int myMaths::LineralEquation::GaussSeidleIterations;
unsigned int myMaths::LineralEquation::JacobiIterations;
myMaths::Matrix myMaths::LineralEquation::generateEquation(int a1, int a2, int a3, int N)
{
	std::vector<std::vector<double>> v1;
	v1.resize(N);
	for (int i = 0; i < N; i++) {
		v1[i].resize(N);
		for (int j = 0; j < N;  j++) {
			if (i == j) v1[i][j] = a1;
			else if (j == i + 1 || j == i - 1) v1[i][j] = a2;
			else if (j == i + 2 || j == i - 2) v1[i][j] = a3;
			else v1[i][j] = 0;
		}
	}
	Matrix mat = v1;
	return mat;
}

myMaths::Vector myMaths::LineralEquation::generateVector(int N, int f)
{
	std::vector<double> v;
	v.resize(N);
	for (int i = 0; i < N; i++) v[i] = sin(i * (f + 1));
	Vector vt = v;
	return vt;
}

myMaths::Vector myMaths::LineralEquation::Jacobi(Matrix A, Vector b)
{
	JacobiIterations = 0;
	Vector x_prev = b.copy(), res = b.copy(), x_next = x_prev.copy();
	x_prev.ones();
	res.ones();
	res = A * x_prev - b;
	while (res.norm() > 1e-9) {
		JacobiIterations++;
		for (int i = 0; i < A.getRows(); i++) {
			x_next.vector[i] = b.vector[i];
			for (int j = 0; j < i; j++) {
				 x_next.vector[i] -= A.matrix[i][j] * x_prev.vector[j];
			}
			for (int j = i+1; j < A.getRows(); j++) {
				x_next.vector[i] -= A.matrix[i][j] * x_prev.vector[j];
			}
			x_next.vector[i] /= A.matrix[i][i];
		}
		x_prev = x_next.copy();
		res = A * x_prev - b;
	}
	return x_prev;
}

myMaths::Vector myMaths::LineralEquation::GaussSeidle(Matrix A, Vector b)
{
	GaussSeidleIterations = 0;
	Vector x_prev = b.copy(), res = b.copy(), x_next = x_prev.copy();
	x_prev.ones();
	res.ones();
	res = A * x_prev - b;
	while (res.norm() > 1e-9) {
		GaussSeidleIterations++;
		for (int i = 0; i < A.getRows(); i++) {
			x_next.vector[i] = b.vector[i];
			for (int j = 0; j < i; j++) {
				x_next.vector[i] -= A.matrix[i][j] * x_next.vector[j];
			}
			for (int j = i + 1; j < A.getRows(); j++) {
				x_next.vector[i] -= A.matrix[i][j] * x_prev.vector[j];
			}
			x_next.vector[i] /= A.matrix[i][i];
		}
		x_prev = x_next.copy();
		res = A * x_prev - b;
	}
	return x_prev;
}

myMaths::Vector myMaths::LineralEquation::Gauss(Matrix A, Vector b)
{
	Matrix mat = A;
	Vector vt = b, v = b;
	for (int i = 0; i < mat.getRows() - 1; i++) {
		for (int j = i + 1; j < mat.getRows(); j++) {
			double alpha = mat.matrix[j][i] / mat.matrix[i][i];
			for (int k = 0; k < mat.getCols(); k++) {
				mat.matrix[j][k] -= mat.matrix[i][k] * alpha;
			}
			vt.vector[j] -= alpha * vt.vector[i];
		}
	}
	v.vector[mat.getRows() - 1] = vt.vector[mat.getRows() - 1] / mat.matrix[mat.getRows() - 1][mat.getRows() - 1];
	for (int i = mat.getRows() - 2; i >= 0; i--) {
		double sum = vt.vector[i];
		for (int j = mat.getRows() - 1; j >= i + 1; j--) {
			sum -= mat.matrix[i][j] * v.vector[j];
		}
		v.vector[i] = sum / mat.matrix[i][i];
	}
		
	return v;
}

unsigned int myMaths::LineralEquation::getJacobiIterations()
{
	return JacobiIterations;
}

unsigned int myMaths::LineralEquation::getGaussSeidleIterations()
{
	return GaussSeidleIterations;
}
