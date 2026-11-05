#include <iostream>
#include <bitset>
#include <string>
#include <limits>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: flipbyte.exe <byte>\n";
        return 0;
    }
    
    int byte;

    try
    {
        byte = std::stoi(argv[1]);
    }
    catch(const std::exception & e)
    {
        std::cout << "Wrong argument type\n";
        return 0;
    }

    if (byte < 0 || byte > std::numeric_limits<uint8_t>::max())
    {
        std::cout << "Argument is out of range\n";
        return 0;
    }

    int num = 0;

    for (int i = 0; i <= 3; i++)
    {
        if ((byte & (1 << i)) > 0)
        {
            num += pow(2, (7 - i));
        }

        if ((byte & (128 >> i)) > 0)
        {
            num += pow(2, i);
        }
    }

    std::cout << num << "\n";

    return 0;
}