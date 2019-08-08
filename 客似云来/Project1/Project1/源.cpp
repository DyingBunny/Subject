#include<iostream>

int main()
{
	long long arr[81] = { 0 };
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 80; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int from;
	int to;
	while (std::cin >> from >> to)
	{
		long long result = 0;
		for (; from <= to; from++)
		{
			result += arr[from];
		}
		std::cout << result << std::endl;
	}
	return 0;
}

//#include <iostream>
//static const int MAX = 81; 
//long long int num[MAX] = { 1, 1, 2, 3, 5 };
//void solve() 
//{ 
//	for (int i = 5; i < MAX; i++) 
//{ 
//	num[i] = num[i - 1] + num[i-2]; 
//} 
//}
//
//
//long long int sum(int from, int to) 
//{ long long int ans = 0; 
//for (int i = from - 1; i < to; i++) 
//{ ans += num[i]; 
//} 
//return ans; 
//}
//int main()
//{
//	int from, to; // 提前计算Fibonacci数列 
//	solve();
//	while (std::cin >> from >> to)
//	{
//		std::cout << sum(from, to) << std::endl;
//	}
//}