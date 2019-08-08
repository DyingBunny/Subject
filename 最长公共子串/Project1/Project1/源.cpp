#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int findLongest(std::string A, int n, std::string B, int m);
int findLongest(std::string A, int n, std::string B, int m)
{
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i-1] == B[j-1])
			{
				dp[i][j] += 1 + dp[i - 1][j - 1];
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] > max)
			{
				max = dp[i][j];
			}
		}
	}
	return  max;
}

int main()
{
	std::string s1, s2;
	s1 = "cacccca";
	s2 = "aaacca";
	int n = 7;
	int m = 6;
	int result = findLongest(s1,n,s2,m);
	std::cout << result << std::endl;
	return 0;
}