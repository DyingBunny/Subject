#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	int t;
	std::cin >> t;
	std::vector<std::string> result;
	while (t)
	{
		int n, m;
		std::cin >> n >> m;
		int tmp = n;
		int sum = 0;
		while (tmp)
		{
			int input;
			std::cin >> input;
			sum += input;
			tmp--;
		}
		//chuli
		int sum1 = 0;
		for (int i = 0; i < n; i++)
		{
			sum1 += i;
		}
		if (sum1 <= (sum + m))
		{
			result.push_back("YES");
		}
		else
		{
			result.push_back("NO");
		}
		t--;
	}
	for (auto it : result)
	{
		std::cout << it << std::endl;
	}
	return 0;
}