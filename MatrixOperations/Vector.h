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
		void multiple(const double b);
		Vector& operator=(const Vector& copied);
		myMaths::Vector operator+(const myMaths::Vector& copied) throw();
		myMaths::Vector operator-(const myMaths::Vector& copied) throw();
		myMaths::Vector operator+(const double added);
		myMaths::Vector operator-(const double subbed);
		myMaths::Vector operator*(const double subbed);
		friend std::ostream& operator<<(std::ostream& stream, const Vector& vt);
	private:
		std::vector<double> vector;
		void add(const myMaths::Vector& b);

		void add(const double b);

		void sub(const myMaths::Vector& b);

		void sub(const double b);

	};
}

