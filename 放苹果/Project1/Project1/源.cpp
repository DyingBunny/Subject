#include<iostream>
#include<vector>

int main()
{
	int n, m;//m个苹果，n个盘子
	while (std::cin >> m >> n)
	{
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
		dp[0][0] = 1;
	}
	return 0;
}