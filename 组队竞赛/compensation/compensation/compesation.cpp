#include<iostream>
#include<algorithm>
#include<vector>

//int main()
//{
//	int n;
//	std::cin >> n;
//	int arr[1000];
//	int i = 0;
//	for (i = 0; i < 3 * n; i++)
//	{
//		std::cin >> arr[i];
//	}
//	std::sort(arr, arr + 3 * n);
//	long sum = 0;
//	int flag = 2;
//	int tmp = n;
//	for (; n>=1; n--)
//	{
//		sum = sum + arr[(3 * tmp) - flag];
//		flag+=2;
//	}
//	std::cout <<sum<< std::endl;
//	return 0;
//}

//int main()
//{
//	int a = 2;
//	if (a++ == 2)
//	{
//		std::cout << "yes" << std::endl;
//	}
//	else
//	{
//		std::cout << "No" << std::endl;
//	}
//	return 0;
//}

int main()
{
	int team_num = 0;
	std::cin >> team_num;
	int num = team_num * 3;
	std::vector<int> tmp;
	while (num)
	{
		int input = 0;
		std::cin >> input;
		tmp.push_back(input);
		num--;
	}
	for (int i = 0; i < team_num; i++)
	{
		tmp.erase(std::find(tmp.begin(), tmp.end(), *std::max_element(tmp.begin(), tmp.end())));
		tmp.erase(std::find(tmp.begin(), tmp.end(), *std::min_element(tmp.begin(), tmp.end())));
	}
	int result = 0;
	for (auto it : tmp)
	{
		result += it;
	}
	std::cout << result << std::endl;
	return 0;
}