#include<iostream>
#include<vector>
#include<stack>

int main()
{
	int input;
	while (std::cin >> input)
	{
		int m = input;
		int num = 0;
		std::vector<int> v1;
		int add = 0;
		while (input != 0)
		{
			std::cin >> num;
			v1.push_back(num);
			input--;
		}
		for (const auto& tmp : v1)
		{
			add = add + tmp;
		}
		int a = add / m;
		int result = 0;
		for (const auto tmp : v1)
		{
			if (tmp < a)
			{
				result += (a - tmp);
			}
		}
		std::cout << result << std::endl;
	}
	return 0;
}