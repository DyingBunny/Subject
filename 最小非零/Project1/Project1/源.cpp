#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v1;
	int tmp = n;
	while (tmp)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		tmp--;
	}
	while (k)
	{
		for (auto it = v1.begin(); it != v1.end();)
		{
			if (*it == 0)
			{
				v1.erase(it);
				it = v1.begin();
			}
			else
			{
				it++;
			}
		}
		int min = 1000;
		if (v1.empty())
		{
			std::cout << 0 << std::endl;
		}
		else
		{
			for (int i = 0; i < v1.size(); i++)
			{
				if (v1[i] < min&&v1[i] != 0)
				{
					min = v1[i];
				}
			}
			std::cout << min << std::endl;
		}
		for (auto &it : v1)
		{
			if (it <= min)
			{
				it = 0;
			}
			else
			{
				it -= min;
			}
		}
		k--;
	}
	return 0;
}