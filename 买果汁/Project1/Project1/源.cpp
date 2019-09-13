#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	int tmp = n;
	std::vector<int> v1;
	while (tmp)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		tmp--;
	}
	int count = 0;
	std::vector<int> num (n,0);
	for (auto it : v1)
	{
 		num[it] = num[it] + 1;
	}
	for (auto it : num)
	{
		if (it % 2 == 0)
		{
			count += (it / 2);
		}
		else
		{
			count += (it / 2) + 1;
		}
	}
	std::cout << count << std::endl;
	return 0;
}