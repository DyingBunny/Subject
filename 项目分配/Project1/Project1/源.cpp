#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int input_n = 0;
	int input_m = 0;
	std::cin >> input_n >> input_m;
	std::vector<std::vector<int>> dp(input_m, std::vector<int>(input_n, 0));
	//´æ·Å
	for (int row = 0; row < input_m; row++)
	{
		for (int col = 0; col < input_n; col++)
		{
			int input = 0;
			std::cin >> input;
			dp[row][col] = input;
		}
	}
	return 0;
}