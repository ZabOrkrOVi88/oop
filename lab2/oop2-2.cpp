#include <iostream>
#include <algorithm>
#include <string>

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string  const& replace)
{
    std::string str = subject;
    auto cur = str.begin();

    while (true)
    {
        auto it = std::search(cur, str.end(), search.begin(), search.end());

        if (it == str.end())
        {
            break;
        }
        
        int index = std::distance(str.begin(), it);
        cur = str.begin() + index + replace.length();
        str.replace(index, search.length(), replace);
    }
    return str;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments number \n";
        return 1;
    }

    std::string str, substr, replace, buf;

    substr = argv[1];
    replace = argv[2];

    while (std::getline(std::cin, buf))
    {
        str = str + buf + '\n';
    }
    std::cout << str;
    str = FindAndReplace(str, substr, replace);
    std::cout << str;
}
