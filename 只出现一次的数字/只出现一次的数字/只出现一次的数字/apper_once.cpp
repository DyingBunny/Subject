//һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε�����
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