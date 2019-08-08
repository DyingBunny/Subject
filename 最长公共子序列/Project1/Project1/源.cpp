#include<iostream>
#include<string>
#include<vector>

int findLCS(std::string A, int n, std::string B, int m);
int findLCS(std::string A, int n, std::string B, int m)
{
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i-1] == B[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}	
			else
			{
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}
	return dp[n][m];
}

int main()
{
	std::string A = "1A2C3D4B56";
	std::string B = "B1D23CA45B6A";
	int n = 10;
	int m = 12;
	int result = findLCS(A,n,B,m);
	std::cout << result << std::endl;
	return 0;
}