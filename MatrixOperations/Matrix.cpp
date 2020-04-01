#include "Matrix.h"

myMaths::Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for (int i = 0; i < rows; i++) this->matrix[i].resize(cols);
}

myMaths::Matrix::~Matrix()
{
	for (int i = 0; i < this->rows; i++) this->matrix[i].~vector;
	this->matrix.~vector;
}
int myMaths::Matrix::getRows() const
{
	return this->rows;
}

int myMaths::Matrix::getCols() const
{
	return this->cols;
}
myMaths::Matrix myMaths::Matrix::copy() {
	Matrix mat = Matrix(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) mat.matrix[i][j] = this->matrix[i][j];
	}
	return mat;
}
myMaths::Matrix myMaths::Matrix::diag()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j <this->cols; j++) if(i != j) mat.matrix[i][j] = 0;
	}
	return mat;
}

myMaths::Matrix myMaths::Matrix::upperTriangle()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++)  if (j - i - 1 <= 0) mat.matrix[i][j] = 0;
	}
	return mat;
}

myMaths::Matrix myMaths::Matrix::lowerTriangle()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++)  if (j - i - 1 >= 0) mat.matrix[i][j] = 0;
	}
	return mat;
}

void myMaths::Matrix::zeros()
{
	for (int i = 0; i < this->rows; i++) 
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = 0;
}

void myMaths::Matrix::ones()
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = 1;
}

myMaths::Matrix& myMaths::Matrix::operator=(const myMaths::Matrix& copied)
{
	this->matrix.resize(copied.getCols());
	for (int i = 0; i < copied.getRows(); i++) {
		this->matrix[i].resize(copied.getCols());
		for (int j = 0; j < copied.getCols(); j++) this->matrix[i][j] = copied.matrix[i][j];
	}
	return *this;
}

myMaths::Matrix myMaths::Matrix::operator+(const Matrix& added) throw()
{
	if (this->rows != added.getRows() || this->cols != added.getCols) throw - 1;
	Matrix mt = this->copy();
	mt.add(added);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator-(const Matrix& subbed) throw()
{
	if (this->rows != subbed.getRows() || this->cols != subbed.getCols) throw - 1;
	Matrix mt = this->copy();
	mt.sub(subbed);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator+(const double added)
{
	Matrix mt = this->copy();
	mt.add(added);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator-(const double subbed) throw()
{
	Matrix mt = this->copy();
	mt.sub(subbed);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator*(const double multication)
{
	Matrix mt = this->copy();
	mt.multiple(multication);
	return mt;
}

myMaths::Vector myMaths::Matrix::operator*(const Vector& multiplied) throw()
{
	if (this->cols != multiplied.getSize()) throw - 1;
	Vector vt = Vector(multiplied.getSize());
	vt.zeros();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++) 
			vt.vector[i] += this->matrix[i][j] * multiplied.vector[j];
	}
	return vt;
}

myMaths::Vector myMaths::Matrix::operator/(const Vector& multiplied) throw()
{
	if (this->cols != multiplied.getSize()) throw - 1;
	Vector vt = Vector(multiplied.getSize());
	vt.zeros();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			vt.vector[i] += 1/this->matrix[i][j] * multiplied.vector[j];
	}
	return vt;
}



void myMaths::Matrix::add(const Matrix& B)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] += B.matrix[i][j];
}

void myMaths::Matrix::add(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] += b;
}

void myMaths::Matrix::sub(const Matrix& B)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] -= B.matrix[i][j];
}

void myMaths::Matrix::sub(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] -= b;
}

void myMaths::Matrix::multiple(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] *= b;
}

std::ostream& myMaths::operator<<(std::ostream& stream, const Matrix& mat)
{
	int j = 0;
	for (int i=0; i < mat.getRows(); i++) {
		stream << "[ ";
		for (j = 0; j < mat.getCols() - 1; j++) stream << mat.matrix[i][j] << ", ";
		stream << mat.matrix[i][j] << " ]\n";
	}
	return stream;
}
