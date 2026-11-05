#include <iostream>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, int> freq{};
	std::string buf;

	while (true) 
	{
		if (std::cin >> buf)
		{
			auto ins = freq.insert({ buf, 1 });
			if (!ins.second)
			{
				freq[buf] += 1;
			}
		}
		else
		{
			break;
		}
	}

	for (const auto& [word, num] : freq)
	{
		std::cout << "\n" << word << " -> " << num;
	}
	return 0;
}
