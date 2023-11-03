/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Quaternion.h
Description : Calculation declarations
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

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
