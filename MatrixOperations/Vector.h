#pragma once
#include <vector>
namespace myMaths {
	class Vector
	{
	public:
		Vector(int size);
		~Vector();
		void zeros();
		void ones();

	private:
		std::vector<double> vector;
		Vector multiple(Vector a, Vector b);
		Vector multiple(Vector a, double b);
		Vector add(Vector a, Vector b);
		Vector add(Vector a, double b);
		Vector sub(Vector a, Vector b);
		Vector sub(Vector a, double b);
	};
}

