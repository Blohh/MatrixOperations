#pragma once
#include "Matrix.h"
#include "Vector.h"
namespace myMaths {
	static class LineralEquation
	{
		static unsigned int GaussSeidleIterations;
		static unsigned int JacobiIterations;
		static double GaussSeidleTime;
		static double JacobiTime;
	public:
		static Matrix generateEquation(int a1, int a2, int a3, int N);
		static Vector generateVector(int N, int f);
		static Vector Jacobi(Matrix A, Vector b);
		static Vector GaussSeidle(Matrix A, Vector b);
		static Vector Gauss(Matrix A, Vector b);
		static unsigned int getJacobiIterations();
		static unsigned int getGaussSeidleIterations();
		static double getGaussSeidleTime();
		static double getJacobiTime();
		static void getLUMatrixes(const Matrix& A, Matrix& L, Matrix& U);
		static Vector LUFactorization(Matrix A, Vector b);
	};
}


