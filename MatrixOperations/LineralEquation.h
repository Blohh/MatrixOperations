#pragma once
#include "Matrix.h"
#include "Vector.h"
namespace myMaths {
	static class LineralEquation
	{
		Matrix generateEquation(int a1, int a2, int a3, int N);
		Vector generateVector(int N, int f);
		Vector Jacobi(Matrix A, Vector b);
		Vector GaussSeidle(Matrix A, Vector b);
		Vector Gauss(Matrix A, Vector b);
	};
}


