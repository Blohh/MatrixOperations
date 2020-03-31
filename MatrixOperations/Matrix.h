#pragma once
#include <vector>
#include "Vector.h"
namespace myMaths {
	class Matrix
	{
		Matrix(int rows, int cols);
		~Matrix();
	private:
		std::vector<std::vector<double>> matrix;
		Matrix multiple(Matrix A, Matrix B);
		Matrix multiple(Matrix A, Vector b);
		Matrix multiple(Matrix A, double b);
		Matrix add(Matrix A, Matrix b);
		Matrix fowardSubstitution();

	public:
		Matrix diag();
		Matrix upperTriangle();
		Matrix lowerTriangle();
		void zeros();
		void ones();
		
	};
}


