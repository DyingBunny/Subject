#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s2.size(); j++)
			{
				if (s1[i] == s2[j])
				{
					if (i > 0 && j > 0&&dp[i-1][j]!=s2.size())
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
					else
					{
						dp[i][j] = 1;
					}
				}
			}
		}
		int result = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s2.size(); j++)
			{
				if (dp[i][j] == s2.size())
				{
					result++;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}