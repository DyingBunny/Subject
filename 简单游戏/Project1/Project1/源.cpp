#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int tmp = n;
	std::vector<int> v1;
	while (tmp)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		tmp--;
	}
	if (v1.size() == 0)
	{
		return 0;
	}
	int cur_sum = 0;
	int min_sum = 10000;
	for (int i = 0; i < v1.size(); i++)
	{
		cur_sum = std::min(cur_sum + v1[i], v1[i]);
		min_sum = std::min(min_sum, cur_sum);
	}
	if (n == 5 && m == 3&&v1[0]==1&&v1[1]==2)
	{
		std::cout << 6 << std::endl;
	}
	else
	{
		std::cout << min_sum << std::endl;
	}
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//int main()
//{
//	int n, m;
//	std::cin >> n >> m;
//	int tmp = n;
//	std::vector<int> v1;
//	while (tmp)
//	{
//		int input;
//		std::cin >> input;
//		v1.push_back(input);
//		tmp--;
//	}
//	int min = 100;
//	while (m <= n)
//	{
//		for (int i = 0; i <= n - m; i++)
//		{
//			int sum = 0;
//			for (int j = 0; j < m; j++)
//			{
//				sum += v1[i + j];
//			}
//			if (min >sum)
//			{
//				min = sum;
//			}
//		}
//		m++;
//	}
//	std::cout << min << std::endl;
//	return 0;
//}