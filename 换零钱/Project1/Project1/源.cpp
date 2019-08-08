#include<iostream>
#include<vector>

int countWays(std::vector<int> changes, int n, int x);

int countWays(std::vector<int> changes, int n, int x)
{
	int dp[16];
	int i, j;
	for (i = 1; i <= x; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = changes[i]; j <= x; j++)
		{
			dp[j] += dp[j - changes[i]];
		}
	}
	return dp[x];
}

int main()
{
	std::vector<int> v1{ 5, 10, 25, 1 };
	int n = 4;
	int x = 15;
	int result = countWays(v1, n, x);
	return 0;
}