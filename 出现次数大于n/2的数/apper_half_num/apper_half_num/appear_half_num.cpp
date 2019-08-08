#include<iostream>
#include<vector>

int main()
{
	int num = 0;
	int input = 0;
	std::vector<int> v1;
	while (std::cin >> input)
	{
		v1.push_back(input);
		num++;
	}
	std::vector<int> result(100, 0 );
	for (auto it : v1)
	{
		result[it] += 1;
	}
	for (int i = 0; i < v1.size();i++)
	{
		if (result[i] >= (num / 2))
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}