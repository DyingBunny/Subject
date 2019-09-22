#include<iostream>
#include<vector>
#include<stack>

int main()
{
	int input;
	std::cin >> input;
	std::vector<int> s1;
	int tmp;
	while (input)
	{
		tmp = input % 10;
		input = input / 10;
		s1.push_back(tmp);
	}
	int result = 0;
	for (int i = 0; i < s1.size();i++)
	{
		result += s1[i];
		if (i != s1.size() - 1)
		{
			result *= 10;
		}
	}
	std::cout << result << std::endl;
	return 0;
}