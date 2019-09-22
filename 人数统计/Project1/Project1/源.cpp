#include<iostream>
#include<vector>
#include<iostream>

int main()
{
	int n, m;
	std::vector<int> v1, v2;
	std::cin >> n >> m;
	while (n)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		n--;
	}
	while (m)
	{
		int input;
		std::cin >> input;
		v2.push_back(input);
		m--;
	}
	for (auto it : v2)
	{
		int count = 0;
		for (auto it1 : v1)
		{
			if (it == it1)
			{
				count++;
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}