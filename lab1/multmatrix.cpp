#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

int OpenStatus(std::ifstream& file, const std::string name)
{
	if (file.is_open())
	{
		return 0;
	}
	else
	{
		std::cout << "Failed to open " << name << " for reading\n";
		return 1;
	}
}

std::array<float, 9> MatrixReader(std::istream& file)
{
	std::array<float, 9> array;
	std::string string, buffer;
	int counter, index = 0;
	
	while (std::getline(file, string))
	{
		if (index > 8)
		{
			std::cout << "Too many arguments in matrix" << '\n';
			exit(0);
		}

		std::stringstream stringstream(string);

		counter = 0;

		while (stringstream >> buffer)
		{
			counter++;

			if (counter > 3)
			{
				std::cout << "Too many arguments in matrix" << '\n';
				exit(0);
			}

			try
			{
				array[index] = std::stof(buffer);
			}
			catch (const std::exception& e)
			{
				std::cout << "Wrong argument type" << '\n';
				exit(0);
			}

			index++;
		}

		if (counter < 3)
		{
			std::cout << "Not enough arguments in matrix" << '\n';
			exit(0);
		}
	}

	if (index == 0)
	{
		std::cout << "File is empty" << '\n';
		exit(0);
	}

	return array;
}

std::array<float, 9> ConsoleReader(std::string name)
{
	std::array<float, 9> array;
	std::fstream tempFile(name, std::ios::in | std::ios::out | std::ios::trunc);

	if (!tempFile.is_open())
	{
		std::cout << "Failed to open " << name << "\n";
		exit(0);
	}

	for (int i = 0; i < 3; i++)
	{
		std::getline(std::cin, name);
		tempFile << name << "\n";
	}

	tempFile.seekg(0, std::ios::beg);

	array = MatrixReader(tempFile);
	
	tempFile.close();

	return array;
}

int main(int argc, char* argv[])
{
	std::array<float, 9> first;
	std::array<float, 9> second;

	std::string skip;

	if (!(argc == 1 || argc == 3))
	{
		std::cout << "Invalid amount of arguments\n";
		std::cout << "Usage: multmatrix.exe <first file> <second file> || Usage: multmatrix.exe <first matrix> <second matrix>\n";
		return 0;
	}

	if (argc == 1)
	{
		first = ConsoleReader("TempFile.txt");

		std::getline(std::cin, skip);
		if (!skip.empty())
		{
			std::cout << "Line between matrices must be empty\n";
			return 0;
		}

		second = ConsoleReader("TempFile.txt");
	}

	if (argc == 3)
	{
		std::ifstream firstFile(argv[1]);

		if (OpenStatus(firstFile, argv[1]) == 1)
		{
			return 0;
		}

		first = MatrixReader(firstFile);

		std::ifstream secondFile(argv[2]);

		if (OpenStatus(secondFile, argv[2]) == 1)
		{
			return 0;
		}

		second = MatrixReader(secondFile);
	}

	std::cout << std::fixed << std::setprecision(3);

	for (int i = 0; i < 9; i = i + 3)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << first[i] * second[j] + first[i + 1] * second[j + 3] + first[i + 2] * second[j + 6];

			if (j < 2)
			{
				std::cout << " ";
			}
		}

		std::cout << '\n';
	}

	return 0;
}