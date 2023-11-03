/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Program.h
Description : Declarations for calculator instance
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#pragma once

#include "Quaternion.h"

#include <fstream>
#include <string>
#include <sstream>

class Program
{
public:
	Program();
	~Program();

	void run();

	void loadQuaternionsAndScalar(const std::string& Filename);
	void displayQuaternions() const;
	void performOperations() const;

private:
	double Scalar{};
	Quaternion QuaternionA;
	Quaternion QuaternionB;

	void readQuaternionFromFile(std::ifstream& File, Quaternion& Quat) const;
	void skipEmptyLine(std::ifstream& File) const;
};
