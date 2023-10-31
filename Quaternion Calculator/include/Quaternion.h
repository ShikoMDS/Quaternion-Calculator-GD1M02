#pragma once

#include <iostream>

class Quaternion
{
public:
	// Constructors
	Quaternion();
	Quaternion(double W, double X, double Y, double Z);

	// Destructor
	~Quaternion();

	//// Getters
	//[[nodiscard]] double getW() const;
	//[[nodiscard]] double getX() const;
	//[[nodiscard]] double getY() const;
	//[[nodiscard]] double getZ() const;
	//
	//// Setters
	//void setW(double W);
	//void setX(double X);
	//void setY(double Y);
	//void setZ(double Z);

	// Quaternion operations
	Quaternion operator+(const Quaternion& Rhs) const;
	Quaternion operator-(const Quaternion& Rhs) const;
	Quaternion operator*(const Quaternion& Rhs) const;
	[[nodiscard]] Quaternion conjugate() const;
	[[nodiscard]] Quaternion inverse() const;
	[[nodiscard]] double dotProduct(const Quaternion& Rhs) const;

	Quaternion operator*(double Scalar) const;

	double W, X, Y, Z;
};

// Additional utility functions
std::ostream& operator<<(std::ostream& Os, const Quaternion& Quat);
