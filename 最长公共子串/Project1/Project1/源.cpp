//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//int findLongest(std::string A, int n, std::string B, int m);
//int findLongest(std::string A, int n, std::string B, int m)
//{
//	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (A[i-1] == B[j-1])
//			{
//				dp[i][j] += 1 + dp[i - 1][j - 1];
//			}
//		}
//	}
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (dp[i][j] > max)
//			{
//				max = dp[i][j];
//			}
//		}
//	}
//	return  max;
//}
//
//int main()
//{
//	std::string s1, s2;
//	std::cin >> s1;
//	std::cin >> s2;
//	int n = s1.size();
//	int m = s2.size();
//	int result = findLongest(s1,n,s2,m);
//	std::cout << result << std::endl;
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::string findLongest(std::string A, int n, std::string B, int m)
{
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] += 1 + dp[i - 1][j - 1];
			}
		}
	}
	int max = 0;
	std::string result;
	int x;
	int y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				x = i;
				y = j;
			}
		}
	}
	if (max == 0)
	{
		return NULL;
	}
	while (dp[x][y] > 0)
	{
		result += A[x-1];
		x--;
		y--;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	std::string s1, s2;
	std::cin >> s1;
	std::cin >> s2;
	int n = s1.size();
	int m = s2.size();
	std::string result = findLongest(s1, n, s2, m);
	std::cout << result << std::endl;
	return 0;
}