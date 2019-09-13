#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int input;
	std::cin >> input;
	int num = input * 2;
	std::vector<int> v1;
	while (num)
	{
		int a;
		std::cin >> a;
		v1.push_back(a);
		num--;
	}
	int result = 0;
	for (auto it : v1)
	{
		if (it > 0)
		{
			result += it;
		}
	}
	std::cout << result <<  std::endl;
	return 0;
}