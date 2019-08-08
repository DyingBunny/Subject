class GoUpstairs {
public:
	int countWays(int n)
	{
		// write code here
		int dp[100] = { 0, 0, 1, 2 };
		for (int i = 4; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		}
		return dp[n];
	}
};