#include<iostream>
#include<vector>

std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum)
{
	std::vector<int> result;
	int max, a, b;
	max = 0;
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = i + 1; j < array.size(); j++)
		{
			if (array[i] + array[j] == sum)
			{
				if (array[i] + array[j] > max)
				{
					max = array[i] + array[j];
					a = array[i];
					b = array[j];
				}
			}
		}
	}
	if (max != 0)
	{
		result.push_back(a);
		result.push_back(b);
	}
	return result;
}

int main()
{
	std::vector<int> array{0, 5, 7, 8, 9, 1, 2, 3, 4, 5, 6};
	int sum = 7;
	std::vector<int> result = FindNumbersWithSum(array, sum);
	for (auto it : result)
	{
		std::cout << it << std::endl;
	}
	return 0;
}