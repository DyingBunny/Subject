#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int tmp;
	std::cin >> tmp;
	std::vector<int> v1;
	while (tmp)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		tmp--;
	}
	std::vector<int> result;
	for (int i = 0; i < v1.size(); i++)
	{
		int count = 0;
		for (int j = i + 1; j < v1.size(); j++)
		{
			if (v1[j] <= v1[i]&&j-i==1)
			{
				count++;
			}
			else if (v1[j] <= v1[i] && v1[i+1] <= v1[j])
			{
				count++;
			}
		}
		result.push_back(count);
	}
	int num = 0;
	int max = -1;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] > max&&result[i]!=0)
		{
			max = result[i];
			num = i;
		}
	}
	if (max==-1)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		std::cout << v1[num] << std::endl;
	}
	return 0;
}