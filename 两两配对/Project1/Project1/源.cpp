#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n;
	std::cin >> n;
	int count = n;
	std::vector<int> v1;
	while (n)
	{
		int a, b;
		std::cin >> a >> b;
		while (a)
		{
			v1.push_back(b);
			a--;
		}
		n--;
	}
	//≈‰∂‘
	int max = 0;
	while (!v1.empty())
	{
		int big = *std::max_element(v1.begin(), v1.end());
		int small = *std::min_element(v1.begin(), v1.end());
		if (max < (big + small))
		{
			max = big + small;
		}
		v1.erase(std::max_element(v1.begin(), v1.end()));
		if (v1.empty())
		{
			break;
		}
		v1.erase(std::min_element(v1.begin(), v1.end()));
	}
	std::cout << max << std::endl;
	return 0;
}