#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <limits>

int main()
{
	std::string input;
	std::cin >> input;
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' || input[i] == ')')
		{
			count++;
		}
	}
	if (count % 2 == 1)
	{
		std::cout << "";
	}
	else{
		count = count / 2;
		while (count)
		{
			int left = 0;
			int right = 0;
			int tmp = 0;
			int tmp_left;
			int tmp_right;
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] == ')')
				{
					right = i - 1;
					break;
				}
			}
			for (int i = input.size() - 1; i >= 0; i--)
			{
				if (input[i] == '(')
				{
					left = i + 1;
					break;
				}
			}
			tmp_left = left;
			tmp_right = right;
			while (left <= right)
			{
				char tmp;
				tmp = input[left];
				input[left] = input[right];
				input[right] = tmp;
				left++;
				right--;
			}
			input.erase(tmp_left - 1, 1);
			input.erase(tmp_right, 1);
			count--;
		}
		std::cout << input;
	}
	return 0;
}
