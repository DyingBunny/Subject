#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int box;
	int key;
	std::vector<int> box_num;
	std::vector<int> key_num;
	std::cin >> box >> key;
	int tmp = box;
	while (tmp)
	{
		int input;
		std::cin >> input;
		box_num.push_back(input);
		tmp--;
	}
	tmp = key;
	while (tmp)
	{
		int input;
		std::cin >> input;
		key_num.push_back(input);
		tmp--;
	}
	int result = 0;
	for (int i = 0; i < box_num.size(); i++)
	{
		for (int j = 0; j < key_num.size(); j++)
		{
			int sum = box_num[i] + key_num[j];
			if (sum % 2 == 1)
			{
				result += 1;
				box_num.erase(std::find(box_num.begin(),box_num.end(),box_num[i]));
				key_num.erase(std::find(key_num.begin(), key_num.end(), key_num[j]));
				i--;
				break;
			}
		}
	}
	std::cout << result << std::endl;
}