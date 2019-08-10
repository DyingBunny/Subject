#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int num;
	std::cin >> num;
	int tmp = num;
	std::vector<long long> v;
	while (tmp)
	{
		long long input;
		std::cin >> input;
		v.push_back(input);
		tmp--;
	}
	std::vector<long long> result;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] - v[i + 1] < 0)
		{
			result.push_back(v[i + 1] - v[i]);
		}
		else
		{
			result.push_back(v[i] - v[i + 1]);
		}
	}
	long long min = *(std::min_element(result.begin(), result.end()));
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == min)
		{
			std::cout << v[i]<<v[i+1];
			return 0;
		}
	}
}