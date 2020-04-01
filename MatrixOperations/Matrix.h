#pragma once
#include <vector>
#include <exception>
#include <iostream>
#include "Vector.h"
namespace myMaths {
	class Matrix
	{
	public:
		Matrix(int rows, int cols);
		Matrix(std::vector<std::vector<double>> mat);
		~Matrix();
		int getRows() const;
		int getCols() const;
		Matrix diag();
		Matrix upperTriangle();
		Matrix lowerTriangle();
		void zeros();
		void ones();
		Matrix& operator=(const Matrix& copied);
		Matrix& operator=(const std::vector<std::vector<double>> mat);
		Matrix operator+(const Matrix& added) throw();
		Matrix operator-(const Matrix& subbed) throw();
		Matrix operator+(const double added);
		Matrix operator-(const double subbed) throw();
		Matrix operator*(const double multication);
		Vector operator*(const Vector& miltiplied) throw();
		Vector operator/(const Vector& substitution) throw();
		friend std::ostream& operator<<(std::ostream& stream, const Matrix& mat);
	private:
		std::vector<std::vector<double>> matrix;
		int rows, cols;
		void add(const Matrix& B);
		void add(const double b);
		void sub(const Matrix& B);
		void sub(const double b);
		void multiple(const double b);
		Matrix copy();
	};
}