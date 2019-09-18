#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> v1;
	int input;
	while (std::cin >> input)
	{	
		v1.push_back(input);
	}
	std::vector<int> tmp(100, 0);
	for (auto it : v1)
	{
		tmp[it] += 1;
	}
	for (int i = 0; i < tmp.size();i++)
	{
		if (tmp[i] >= (v1.size()) / 2)
		{
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}