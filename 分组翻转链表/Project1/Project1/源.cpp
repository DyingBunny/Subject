#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

int main()
{
	int k;
	std::cin >> k;
	std::vector<int> v1;
	int input;
	while (std::cin >> input)
	{
		v1.push_back(input);
	}
	
	for (int i = 0; i < v1.size(); i += k)
	{
		if (i + k - 1 < v1.size())
		{
			std::stack<int> s1;
			for (int j = i; j <= i + k - 1; j++)
			{
				s1.push(v1[j]);
			}
			for (int j = i; j <= i + k - 1; j++)
			{
				v1[j] = s1.top();
				s1.pop();
			}
		}
	}
	for (auto it : v1)
	{
		std::cout << it << std::endl;
	}
	return 0;
}