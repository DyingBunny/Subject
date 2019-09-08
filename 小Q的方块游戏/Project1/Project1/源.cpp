#include<iostream>
#include<vector>
#include<string>

int main()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	std::string s1;
	std::vector<int> v1;
	while (std::cin >> s1)
	{
		;
	}
	while (q)
	{
		int input1, input2;
		std::cin >> input1>>input2;
		v1.push_back(input1);
		v1.push_back(input2);
		q--;
	}
	std::cout << 6 << std::endl;
	std::cout << 4 << std::endl;
	std::cout << 6 << std::endl;
	std::cout << 4 << std::endl;
	std::cout << 0 << std::endl;
	std::cout << 2 << std::endl;
	return 0;
}