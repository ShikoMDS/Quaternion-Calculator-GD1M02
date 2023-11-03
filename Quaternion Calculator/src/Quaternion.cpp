/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Quaternion.cpp
Description : Implementations for quaternion calculator calculations
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#include "Quaternion.h"

// Constructors
Quaternion::Quaternion() : W(0), X(0), Y(0), Z(0)
{
}

Quaternion::Quaternion(const double W, const double X, const double Y, const double Z) : W(W), X(X), Y(Y), Z(Z)
{
}

// Destructor
Quaternion::~Quaternion() = default;

// Quaternion operations
Quaternion Quaternion::operator+(const Quaternion& Rhs) const
{
	return {W + Rhs.W, X + Rhs.X, Y + Rhs.Y, Z + Rhs.Z};
}

Quaternion Quaternion::operator-(const Quaternion& Rhs) const
{
	return {W - Rhs.W, X - Rhs.X, Y - Rhs.Y, Z - Rhs.Z};
}

Quaternion Quaternion::operator*(const Quaternion& Rhs) const
{
	return {
		W * Rhs.W - X * Rhs.X - Y * Rhs.Y - Z * Rhs.Z,
		W * Rhs.X + X * Rhs.W + Y * Rhs.Z - Z * Rhs.Y,
		W * Rhs.Y - X * Rhs.Z + Y * Rhs.W + Z * Rhs.X,
		W * Rhs.Z + X * Rhs.Y - Y * Rhs.X + Z * Rhs.W
	};
}

Quaternion Quaternion::conjugate() const
{
	return {W, -X, -Y, -Z};
}

Quaternion Quaternion::inverse() const
{
	const double NormSquare = W * W + X * X + Y * Y + Z * Z;
	if (NormSquare == 0.0)
	{
		std::cerr << "Error: Quaternion has zero norm.\n";
		return {};
	}
	const double InvNormSquare = 1.0 / NormSquare;
	const Quaternion ConjugateResult = this->conjugate();
	return
	{
		ConjugateResult.W * InvNormSquare,
		ConjugateResult.X * InvNormSquare,
		ConjugateResult.Y * InvNormSquare,
		ConjugateResult.Z * InvNormSquare
	};
}

double Quaternion::dotProduct(const Quaternion& Rhs) const
{
	return this->W * Rhs.W + this->X * Rhs.X + this->Y * Rhs.Y + this->Z * Rhs.Z;
}

Quaternion Quaternion::operator*(double Scalar) const
{
	return {this->W * Scalar, this->X * Scalar, this->Y * Scalar, this->Z * Scalar};
}

// Additional utility functions
std::ostream& operator<<(std::ostream& Os, const Quaternion& Quat)
{
	Os << Quat.W << " + " << Quat.X << "i + " << Quat.Y << "j + " << Quat.Z << "k";
	return Os;
}
