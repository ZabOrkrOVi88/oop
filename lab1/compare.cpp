#include <iostream>
#include <fstream>

int OpenStatus(std::ifstream& file, const std::string name)
{
	if (!file.is_open())
	{
		std::cout << "Failed to open " << name << " for reading\n";
		return 1;
	}
}

int main(int argc, char * argv[])
{	
	if (argc != 3)
	{
		std::cout << "Invalid amount of arguments\n";
		std::cout << "Usage: compare.exe <first file> <second file>\n";
		return 1;
	}

	std::ifstream firstFile(argv[1]);
	
	if (OpenStatus(firstFile, argv[1]) == 1)
	{
		return 1;
	}

	std::ifstream secondFile(argv[2]);

	if (OpenStatus(secondFile, argv[2]) == 1)
	{
		return 1;
	}

	char ch1, ch2;

	int counter = 1;

	bool flag1 = false;

	bool flag2 = false;
	
	while (true)
	{
		if (firstFile.get(ch1))
		{
			flag1 = true;
		}
		else
		{
			flag1 = false;
		}

		if (secondFile.get(ch2))
		{
			flag2 = true;
		}
		else
		{
			flag2 = false;
		}

		if (flag1 and flag2)
		{
			if (ch1 != ch2)
			{
				std::cout << "Files are different. Line number is " << counter << "\n";
				return 1;
			}

			if (ch1 == '\n')
			{
				counter++;
			}

		}
		else if (!flag1 and !flag2)
		{
			std::cout << "Files are equal\n";
			return 0;
		}
		else if (flag1 or flag2)
		{
			std::cout << "Files are different. Line number is " << counter << "\n";
			return 1;
		}
	}
}
