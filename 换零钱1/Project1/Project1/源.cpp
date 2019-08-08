#include<iostream>
#include<vector>

long long FindNum(int input);
long long FindNum(int input)
{
	int i = 4;
	int j = input;
	std::vector<std::vector<long long>> dp(i, std::vector<long, long>(j + 1));
}

int main()
{
	int input = 0;
	std::cin >> input;
	long long result = FindNum(input);
	std::cout << result << std::endl;
	return 0;
}