#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> origin;
	int num = 0;
	std::cin >> num;
	int tmp = num;
	while (tmp)
	{
		int input = 0;
		std::cin >> input;
		origin.push_back(input);
		tmp--;
	}
	std::vector<std::vector<int>> dp(num, std::vector<int>(num, 0));
	for (int i = 0; i < num; i++)
	{
		int flag = 1;
		for (int j = 0; j < num; j++)
		{
			if (j + 1+i <= num - 1)
			{
				if (flag == 1)
				{
					dp[i][j + 1 + i] = origin[i] + origin[j + 1+i];
					flag = 0;
				}
				else
				{
					dp[i][j + 1 + i] =origin[j+1+i]+dp[i][j+i];
				}
			}
		}
	}
	int max = -999;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (j + i + 1 <= num-1)
			{
				max = (dp[i][j + i + 1]>max) ? dp[i][j + i + 1] : max;
			}
		}
	}
	if (max < *std::max_element(origin.begin(), origin.end()))
	{
		max = *std::max_element(origin.begin(), origin.end());
	}
	std::cout << max << std::endl;
	return 0;
}