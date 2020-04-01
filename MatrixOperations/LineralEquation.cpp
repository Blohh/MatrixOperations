#include "LineralEquation.h"
#include <vector>
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
	Matrix L = A.lowerTriangle(), U = A.upperTriangle(), D = A.diag();
	Vector r = b.copy(), res = b.copy();
	r.ones();
	do {
		r = (D + L) * (-1) / (U * r) + (D + L) / b;
		res = A * r - b;
	} while (res.norm() > 1e-9);
	return r;
}

myMaths::Vector myMaths::LineralEquation::GaussSeidle(Matrix A, Vector b)
{
	Matrix L = A.lowerTriangle(), U = A.upperTriangle(), D = A.diag();
	Vector r = b.copy(), res = b.copy();
	r.ones();
	do {
		r = (D * (-1)) / ((L + U) * r) + D / b;
		res = A * r - b;
	} while (res.norm() > 1e-9);
	return r;
}

myMaths::Vector myMaths::LineralEquation::Gauss(Matrix A, Vector b)
{
	Vector v = (A/b);
	return v;
}
