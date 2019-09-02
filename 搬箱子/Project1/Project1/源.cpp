#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> pack;
	int tmp = n;
	while (tmp)
	{
		int input;
		std::cin >> input;
		pack.push_back(input);
		tmp--;
	}
	std::cout << *std::max_element(pack.begin(), pack.end());
}