#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, num;
	std::cin >> n >> num;
	std::vector<int> v1;
	while (n)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		n--;
	}
	//找到最大乘积和
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		int j = num / i;
		if (i*j == num && (i + j) > sum&&i!=1&&i!=num)
		{
			sum = i + j;
		}
	}
	int sum1 = 0;
	int count = 0;
	for (auto it : v1)
	{
		sum1 += it;
		count++;
	}
	std::cout << sum1 - sum - count + 2 << std::endl;
	return 0;
}