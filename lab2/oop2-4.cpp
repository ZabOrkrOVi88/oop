#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

int main()
{
    std::set <std::string> bad;
    std::string buf, result;
    std::getline(std::cin, buf, '\n');
    std::stringstream stream(buf);

    while (stream >> buf)
    {
        bad.insert(buf);
    }

    while (std::getline(std::cin, buf))
    {
        stream.str(buf);
        stream.clear();

        while (stream >> buf)
        {
            if (!bad.contains(buf))
            {
                result += buf;
                result += ' ';
            }
        }
        result += '\n';
    }

    std::cout << '\n' << result;
    return 0;
}
