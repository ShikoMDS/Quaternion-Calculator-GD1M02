#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Quaternion.h"

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
