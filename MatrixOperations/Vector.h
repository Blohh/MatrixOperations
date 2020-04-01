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
		Vector operator+(const Vector& copied) throw();
		Vector operator-(const Vector& copied) throw();
		Vector operator+(const double added);
		Vector operator-(const double subbed);
		Vector operator*(const double subbed);
		friend std::ostream& operator<<(std::ostream& stream, const Vector& vt);
	private:
		std::vector<double> vector;
		void add(const Vector& b);
		void add(const double b);
		void sub(const Vector& b);
		void multiple(const double b);
		void sub(const double b);

	};
}

