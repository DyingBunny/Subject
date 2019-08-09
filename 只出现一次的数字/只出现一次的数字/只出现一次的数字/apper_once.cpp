//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字
#include<iostream>
#include<unordered_map>

void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
	std::unordered_map<int, int> map;
	for (auto it : data)
	{
		map[it]++;
	}
	std::vector<int> result;
	for (auto it : data)
	{
		if (map[it] == 1)
		{
			result.push_back(it);
		}
	}
	*num1 = result[0];
	*num2 = result[1];
}