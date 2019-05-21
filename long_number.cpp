#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
int main()
{
	std::string input;
	std::cin >> input;
	std::vector<int> v1 (input.size(), 0);
	for (int i = 0; i < input.size();i++)
	{
		if (i == 0)
		{
			if (std::isdigit(input[i]))
			{
				v1[i] += 1;
			}
		}
		else
		{
			if (std::isdigit(input[i]))
			{
				v1[i] =v1[i]+1+v1[i-1];
			}
		}
	}
	std::string result;
	int pos = 0;
	for (int i = 0; i < v1.size();i++)
	{
		if (v1[i] == *std::max_element(v1.begin(), v1.end()))
		{
			pos = i;
		}
	}
	for (; std::isdigit(input[pos]); pos--)
	{
		result.push_back(input[pos]);
	}
	std::reverse(result.begin(), result.end());
	std::cout << result << std::endl;
	return 0;
}