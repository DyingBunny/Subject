#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> input;
	int num;
	cin >> num;
	int tmp = num;
	while (tmp != 0)
	{
		int a;
		cin >> a;
		input.push_back(a);
		tmp--;
	}
	vector<vector<int>> dp (num, vector<int>(num, 0));
	vector<int> mx(num,0);
	int i = 0;
	int j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (i == 0 || j == 0)
			{
				if (input[j] - input[i]>0)
				{
					dp[i][j] += input[j] - input[i];
					mx[j] += 1;
				}
			}
			int max = 0;
			for (int x = 0; x < i - 1; x++)
			{
				for (int y = 0; y < j - 1; y++)
				{
					if (dp[x][y]>max)
					{
						max = dp[x][y];
					}
				}
			}
			dp[i][j] += max;
		}
	}
	int count = 0;
	int max = 0;
	for (int m = 0; m < num; m++)
	{
		if (dp[m][num - 1]>max)
		{
			max = dp[m][num - 1];
			count = mx[m] * 2;
		}
	}
	cout << max <<endl;
	cout << count << endl;
	return 0;
}