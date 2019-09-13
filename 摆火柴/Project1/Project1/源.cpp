#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int count, num;
	std::cin >> count >> num;
	std::vector<int> v1;
	while (num)
	{
		int input;
		std::cin >> input;
		v1.push_back(input);
		num--;
	}
	std::vector<int> init(10,0);
	init[0] = 100;
	init[1] = 2;
	init[2] = 5;
	init[3] = 5;
	init[4] = 4;
	init[5] = 5;
	init[6] = 6;
	init[7] = 3;
	init[8] = 7;
	init[9] = 6;

	int tmp;
	int min = 100;
	int min_index = 0;
	for (auto it : v1)
	{
		if (min > init[it])
		{
			min = init[it];
			min_index = it;
		}
	}
	tmp = count / min;
	int result = 0;
	while (tmp)
	{
		result *= 10;
		result += min_index;
		tmp--;
	}
	int tmp1=(count%min);
	for (auto it : v1)
	{
		if (tmp1 == init[it])
		{
			result *= 10;
			result += it;
		}
	}
	std::cout << result << std::endl;
	return 0;
}