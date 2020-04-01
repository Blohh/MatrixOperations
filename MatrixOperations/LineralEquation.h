#pragma once
#include "Matrix.h"
#include "Vector.h"
namespace myMaths {
	static class LineralEquation
	{
	public:
		static Matrix generateEquation(int a1, int a2, int a3, int N);
		static Vector generateVector(int N, int f);
		static Vector Jacobi(Matrix A, Vector b);
		static Vector GaussSeidle(Matrix A, Vector b);
		static Vector Gauss(Matrix A, Vector b);
	};
}


