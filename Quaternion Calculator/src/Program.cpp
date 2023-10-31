#include "Program.h"

Program::Program() = default;

Program::~Program() = default;

void Program::run()
{
	loadQuaternionsAndScalar("Quaternion.txt");
	displayQuaternions();
	performOperations();
}

void Program::loadQuaternionsAndScalar(const std::string& Filename)
{
	std::ifstream File(Filename);
	if (!File.is_open())
	{
		std::cerr << "Error opening file: " << Filename << std::endl;
		exit(EXIT_FAILURE);
	}

	// Read quaternion a (line 1)
	readQuaternionFromFile(File, QuaternionA);

	// Skip empty line (line 2)
	skipEmptyLine(File);

	// Read quaternion b (line 3)
	readQuaternionFromFile(File, QuaternionB);

	// Skip empty line (line 4)
	skipEmptyLine(File);

	// Read scalar value (line 5)
	File >> Scalar;

	// Close the file
	File.close();
}

void Program::displayQuaternions() const
{
	std::cout << "Quaternion A: " << QuaternionA.W << " + " << QuaternionA.X << "i + " << QuaternionA.Y << "j + " <<
		QuaternionA.Z << "k" << std::endl;
	std::cout << "Quaternion B: " << QuaternionB.W << " + " << QuaternionB.X << "i + " << QuaternionB.Y << "j + " <<
		QuaternionB.Z << "k" << std::endl;
	std::cout << "Scalar: " << Scalar << std::endl;
}

void Program::performOperations() const
{
	// Perform calculations and display results
	// 1) a + b
	// 2) a – b
	// 3) b – a
	// 4) ab
	// 5) ba
	// 6) a.b(Dot product of a and b)
	// 7) a *
	// 8) a - 1
	// 9) ta

	Quaternion Result;

	// Perform quaternion operations
	Result = QuaternionA + QuaternionB;
	std::cout << "a + b: " << Result << '\n';

	Result = QuaternionA - QuaternionB;
	std::cout << "a - b: " << Result << '\n';

	Result = QuaternionB - QuaternionA;
	std::cout << "b - a: " << Result << '\n';

	Result = QuaternionA * QuaternionB;
	std::cout << "ab: " << Result << '\n';

	Result = QuaternionB * QuaternionA;
	std::cout << "ba: " << Result << '\n';

	const double DotProductValue = QuaternionA.dotProduct(QuaternionB);
	std::cout << "a.b (Dot product of a and b): " << DotProductValue << '\n';

	Result = QuaternionA.conjugate();
	std::cout << "a*: " << Result << '\n';

	Result = QuaternionA.inverse();
	std::cout << "a^-1: " << Result << '\n';

	Result = QuaternionA * Scalar;
	std::cout << "ta: " << Result << '\n';
}

void Program::readQuaternionFromFile(std::ifstream& File, Quaternion& Quat) const
{
    std::string Line;
    std::getline(File, Line);

    // Format is "w +/- xi +/- yj +/- zk"
    std::istringstream Iss(Line);
    char Dummy; // to temporarily store '+'/'-' and 'i', 'j', 'k'

    // Read the real part
    if (!(Iss >> Quat.W))
    {
        Quat.W = 1; // If no real part specified, set to 1
        Iss.clear();
    }

    // Loop to read 'i', 'j', 'k' parts
    for (const char Part : {'i', 'j', 'k'})
    {
        if (Iss >> Dummy)
        {
            double& CurrentPart = (Part == 'i') ? Quat.X : (Part == 'j') ? Quat.Y : Quat.Z;

            if (Dummy == '+')
            {
                if (!(Iss >> CurrentPart && Iss >> Dummy && Dummy == Part))
                {
                    CurrentPart = 1; // If the part is alone, set to 1
                }
            }
            else if (Dummy == '-')
            {
                if (!(Iss >> CurrentPart && Iss >> Dummy && Dummy == Part))
                {
                    CurrentPart = -1; // If the part is alone, set to -1
                }
                else
                {
                    CurrentPart = -CurrentPart;
                }
            }
        }
    }
}


void Program::skipEmptyLine(std::ifstream& File) const
{
	std::string Line;
	std::getline(File, Line);
	// Add additional checks if needed
}
