#include<iostream>
#include<vector>

int main()
{
	int row=4, col=5;
	std::vector<std::vector<int>> v1(row, std::vector<int>(col, 0));
	for (int i = 0;; i < row; i++)
	{
		int tmp = 0;
		if (i > 0)
		{
			tmp=v1
		}
	}
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			std::cout << v1[m][n];
		}
		std::cout << "\n";
	}
	return 0;
}