#include "Vector.h"
#include <vector>
#include <exception>
myMaths::Vector::Vector(int size)
{
	this->vector.reserve(size);
}
myMaths::Vector::~Vector() {
	this->vector.~vector();
}
void myMaths::Vector::zeros() {
	for (int i = 0; i < this->vector.size; i++) vector[i] = 0;
}
void myMaths::Vector::ones() {
	for (int i = 0; i < this->vector.size; i++) vector[i] = 1;
}

myMaths::Vector myMaths::Vector::add(const myMaths::Vector& a, const myMaths::Vector& b) {
	Vector tmp = a;
	for (int i = 0; i < tmp.vector.size(); i++) {
		tmp[i] += b.vector[i];
	}
	return tmp;
}
myMaths::Vector myMaths::Vector::add(const myMaths::Vector& a, const double b) {
	Vector tmp = a;
	for (int i = 0; i < tmp.vector.size(); i++) {
		tmp[i] += b;
	}
	return tmp;
}
myMaths::Vector myMaths::Vector::sub(const myMaths::Vector& a, const myMaths::Vector& b) {
	Vector tmp = a;
	for (int i = 0; i < tmp.vector.size(); i++) {
		tmp[i] -= b.vector[i];
	}
	return tmp;
}
myMaths::Vector myMaths::Vector::sub(const myMaths::Vector& a, const double b) {
	Vector tmp = a;
	for (int i = 0; i < tmp.vector.size(); i++) {
		tmp[i] -= b;
	}
	return tmp;
}
myMaths::Vector myMaths::Vector::multiple(const myMaths::Vector& a, const double b) {
	Vector tmp = a;
	for (int i = 0; i < tmp.vector.size(); i++) {
		tmp[i] *= b;
	}
	return tmp;
}
myMaths::Vector& myMaths::Vector::operator=(const myMaths::Vector& copied)
{
	this->vector.resize(copied.vector.size());
	for (int i = 0; i < vector.size(); i++) this[i] = copied.vector[i];
	return *this;
}
myMaths::Vector& myMaths::Vector::operator+(const myMaths::Vector& added) throw()
{
	if (this->vector.size != added.vector.size) throw - 1;
	myMaths::Vector& tmp = *this;
	tmp = add(tmp, added);
	return tmp;
}
myMaths::Vector& myMaths::Vector::operator-(const myMaths::Vector& subbed) throw()
{
	if (this->vector.size != subbed.vector.size) throw - 1;
	myMaths::Vector& tmp = *this;
	tmp = sub(tmp, subbed);
	return tmp;
}
myMaths::Vector& myMaths::Vector::operator+(const double added) 
{
	myMaths::Vector& tmp = *this;
	tmp = add(tmp, added);
	return tmp;
}
myMaths::Vector& myMaths::Vector::operator-(const double subbed)
{
	myMaths::Vector& tmp = *this;
	tmp = sub(tmp, subbed);
	return tmp;
}
myMaths::Vector& myMaths::Vector::operator*(const double subbed)
{
	myMaths::Vector& tmp = *this;
	tmp = multiple(tmp, subbed);
	return tmp;
}
double& myMaths::Vector::operator[](const int i)
{
	return (this->vector[i]);
}
