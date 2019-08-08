#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//int main()
//{
//	vector<int> numbers = { 1,2,3,2,2,2,5,4,2};
//	vector<int> v1(20, 0);
//	for (const auto it : numbers)
//	{
//		v1[it] += 1;
//	}
//
//	if (*max_element(v1.begin(), v1.end()) > numbers.size() / 2)
//	{
//		for (int i = 0; i < v1.size();i++)
//		{
//			if (v1[i] == *max_element(v1.begin(), v1.end()))
//			{
//				cout << i << endl;
//				return 0;
//			}
//		}
//	}
//	cout << 0 << endl;
//	return 0;
//}

int main()
{
	vector<int> dp;
	dp.push_back(1);
	cout << dp[0] << endl;
}