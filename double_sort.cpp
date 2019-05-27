#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<std::string> input;
	int num = 0;
	std::cin >> num;
	int tmp = num;
	while (tmp)
	{
		std::string s1;
		std::cin >> s1;
		input.push_back(s1);
		tmp--;
	}
	
	int flag1 = 1;
	int flag2 = 1;

	//判断长短排序
	for (int i = 0; i < input.size() - 1; i++)
	{
		if (input[i].size()>input[i+1].size())
		{
			--flag1;
			break;
		}
	}
	//判断字典排序
	for (int j = 0; j < input.size() - 1; j++)
	{
		for (int num_str_size = 0; num_str_size < input[j].size(); num_str_size++)
		{
			if (input[j][num_str_size]>input[j + 1][num_str_size])
			{
				--flag2;
				goto pick;
			}
		}
	}
	pick:
	if (flag1 == 0 && flag2 == 0)
	{
		std::cout << "none" << std::endl;
	}
	else if (flag1 == 1 && flag2 == 1)
	{
		std::cout << "both" << std::endl;
	}
	else if (flag1 == 1 && flag2 == 0)
	{
		std::cout << "lengths" << std::endl;
	}
	else if (flag1 == 0 && flag2 == 1)
	{
		std::cout << "lexicographically" << std::endl;
	}
	return 0;
}
