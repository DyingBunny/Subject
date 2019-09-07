#include<iostream>
#include<string>
#include<cctype>

int main()
{
	std::string input;
	std::cin >> input;
	std::string result;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '-')
		{
			char tmp = input[i - 1];
			while (tmp != input[i + 1])
			{
				result += tmp;
				tmp += 1;
			}
			result += tmp;
			if (std::isdigit(input[i + 2]))
			{
				int count = input[i+2] - '0';
				count--;
				while (count)
				{
					result += result;
					count--;
				}
			}
		}
		if (std::isdigit(input[i]))
		{
			int count = input[i + 2] - '0';
			if (input[i - 2] == '-')
			{
				break;
			}
			int j = i;
			while (input[j-1] != '-'&&std::isdigit(input[j]))
			{
				result += input[j];
				j--;
			}
			while (count)
			{
				result += result;
				count--;
			}
		}	
	}
	std::cout << result;
	return 0;
}