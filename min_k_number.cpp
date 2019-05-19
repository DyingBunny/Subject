#include<iostream>
#include<vector>
#include<algorithm>

//int main()
//{
//	std::vector<int> v1{ 4, 5, 1, 6, 2, 7, 3, 8 };
//	int num = 4;
//	std::sort(v1.begin(), v1.end());
//	std::vector<int> result;
//	for (int i = 0; i < num; i++)
//	{
//		result.push_back(v1[i]);
//	}
//	return 0;
//
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k>int(input.size()))
		{
			std::vector<int> resultk;
			return resultk;
		}
		else{
			std::sort(input.begin(), input.end());
			std::vector<int> result;
			for (int i = 0; i < k; i++)
			{
				result.push_back(input[i]);
			}
			return result;
		}
	}
}; }