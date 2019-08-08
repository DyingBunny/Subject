#include<iostream>
#include<vector>
#include<list>

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	std::reverse(v1.begin(), v1.begin() + 3);
	for (const auto&it : v1)
	{
		std::cout << it << std::endl;
	}
	return 0;
}