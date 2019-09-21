#include<iostream>
#include<vector>
#include<algorithm>

//int main()
//{
//	std::vector<int> result;
//	int t;
//	std::cin >> t;
//	while (t)
//	{
//		std::vector<int> v1;
//		int num;
//		std::cin >> num;
//		while (num)
//		{
//			int input;
//			std::cin >> input;
//			v1.push_back(input);
//			num--;
//		}
//		//¥¶¿Ì
//		int team_1 = 0;
//		int team_2 = 0;
//		int flag = 0;
//		while (!v1.empty())
//		{		
//			if (flag == 0)
//			{
//				team_1 += *std::max_element(v1.begin(), v1.end());
//				team_1 += *std::min_element(v1.begin(), v1.end());
//				v1.erase(std::max_element(v1.begin(), v1.end()));
//				v1.erase(std::min_element(v1.begin(), v1.end()));
//				flag = 1;
//			}
//			else
//			{
//				team_2 += *std::max_element(v1.begin(), v1.end());
//				team_2 += *std::min_element(v1.begin(), v1.end());
//				v1.erase(std::max_element(v1.begin(), v1.end()));
//				v1.erase(std::min_element(v1.begin(), v1.end()));
//				flag = 0;
//			}
//		}
//		result.push_back(team_1);
//		result.push_back(team_2);
//		t--;
//	}
//	int count = 1;
//	for (auto it : result)
//	{
//		std::cout << it << " ";
//		if (count % 2 == 0)
//		{
//			std::cout << std::endl;
//		}
//		count++;
//	}
//	return 0;
//}

//int main()
//{
//	int n, m;
//	while (std::cin >> n >> m)
//	{
//		std::vector<int> v(n);
//		std::vector<int> res;
//		for (size_t i = 0; i < v.size(); i++)
//		{
//			std::cin >> v[i];
//		}
//		std::sort(v.begin(), v.end());
//		long long temp = 0;
//		for (size_t i = 0; i < v.size(); i++)
//		{
//			int num = v[i] - temp;
//			if (num > 0)
//			{
//				res.push_back(num);
//				temp += num;
//			}
//			else if (num == 0)
//			{
//				continue;
//			}
//		}
//		if (res.size() < m)
//		{
//			for (int j = res.size(); j < m; ++j)
//			{
//				res.push_back(0);
//			}
//		}
//		for (int i = 0; i < m; i++)
//		{
//			std::cout << res[i] << std::endl;
//		}
//	}
//	return 0;
//}

int main()
{
	int a;
	a = rand();
	std::cout << a << std::endl;
	return 0;
}