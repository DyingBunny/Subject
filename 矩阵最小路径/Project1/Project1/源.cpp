#include<iostream>
#include<algorithm>
#include<cstring>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int arr[n][m];
	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][j];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1] + arr[i][j]);
		}
	}
	std::cout << dp[n - 1][m - 1] << std::endl;
	return 0;
}