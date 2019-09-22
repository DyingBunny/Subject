#include<iostream>
#include<vector>
#include<algorithm>

//int Lis(std::vector<int> v1)
//{
//	std::vector<int> dp(v1.size(), 0);
//	dp[0] = 1;
//	int sum = v1[0];
//	for (int i = 1; i < v1.size(); i++)
//	{
//		dp[i] = 1;
//		if (v1[i]>=sum&&v1[i]>v1[i-1])
//		{
//			dp[i] = dp[i - 1] + 1;
//		}
//		sum += v1[i];
//	}
//	return *std::max_element(dp.begin(), dp.end());
//}
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> result;
//	while (n)
//	{
//		int size;
//		std::vector<int> v1;
//		std::cin >> size;
//		while (size)
//		{
//			int input;
//			std::cin >> input;
//			v1.push_back(input);
//			size--;
//		}
//		//处理
//		int a = Lis(v1);
//		result.push_back(a);
//		n--;
//	}
//	for (auto it : result)
//	{
//		std::cout << it << std::endl;
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>

int Lis(std::vector<int> v1)
{
	std::vector<int> dp(v1.size(), 0);
	dp[0] = 1;
	for (int i = 1; i < v1.size(); i++)
	{
		dp[i] = 1;
		if (v1[i]>v1[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> result;
	while (n)
	{
		int size;
		std::vector<int> v1;
		std::cin >> size;
		while (size)
		{
			int input;
			std::cin >> input;
			v1.push_back(input);
			size--;
		}
		//处理
		int a = Lis(v1);
		result.push_back(a);
		n--;
	}
	for (auto it : result)
	{
		std::cout << it << std::endl;
	}
	return 0;
}