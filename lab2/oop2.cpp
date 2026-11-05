#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <iomanip>


std::vector<double> ReadNumbers()
{
    std::cout << "Enter amount of numbers\n";
    int n;

    if (!(std::cin >> n) || n < 1)
    {
        std::cout << "Wrong argument type or invalid size\n";
        return {};
    }

    std::vector<double> nums(n);
    std::cout << "Enter numbers\n";

    for (int i = 0; i < n; i++)
    {       
        if (!(std::cin >> nums[i]))
        {
            std::cout << "Wrong argument type\n";
            return {};
        }
    }
    return nums;
}

void PrintSortedNumbers(std::vector<double> nums)
{
    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << ' ';
    }
}

std::vector<double> ProcessNumbers(std::vector<double> nums)
{
    std::pair<double, int> pair = {0, 0};
    auto sum = std::accumulate(nums.begin(), nums.end(), pair, [](std::pair<double, int > acc, double num) {if (num > 0) { acc.first += num; acc.second++;} return acc;});
    double ar = (sum.second > 0) ? (sum.first / sum.second) : 0;
    std::for_each(nums.begin(), nums.end(), [ar](double& num) {num += ar; });
    std::sort(nums.begin(), nums.end());
    return nums;
}

int main()
{
    PrintSortedNumbers(ProcessNumbers(ReadNumbers()));
    return 0;
}
