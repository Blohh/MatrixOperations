#pragma once
#include <vector>
#include <exception>
#include <iostream>
namespace myMaths {
	class Vector
	{
	public:
		Vector(int size);
		~Vector();
		void zeros();
		void ones();
		Vector& operator=(const Vector& copied);
		myMaths::Vector& operator+(const myMaths::Vector& copied) throw();
		myMaths::Vector& operator-(const myMaths::Vector& copied) throw();
		myMaths::Vector& operator+(const double added);
		myMaths::Vector& operator-(const double subbed);
		myMaths::Vector& operator*(const double subbed);
		double& operator[](const int i);
		friend std::ostream& operator<<(std::ostream& stream, const Vector& vt);
	private:
		std::vector<double> vector;
		static Vector multiple(const Vector& a, const double b);
		static Vector add(const Vector& a, const Vector& b);
		static Vector add(const Vector& a, const double b);
		static Vector sub(const Vector& a, const Vector& b);
		static Vector sub(const Vector& a, const double b);
	};
}

