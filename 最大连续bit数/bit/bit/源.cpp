#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int main()
{
	int a = 325;
	while (std::cin >> a)
	{
		std::string s1;
		while (a != 0)
		{
			if ((a % 2) == 1)
			{
				s1.push_back('1');
			}
			else
			{
				s1.push_back('0');
			}
			a = a / 2;
		}

		//std::cout << s1 << std::endl;
		int cout1 = 0;
		std::vector<int> v1;
		for (std::string::iterator i = s1.begin(); i != s1.end(); i++)
		{
			if ((*i) == '1')
			{
				cout1++;
			}
			else
			{
				v1.push_back(cout1);
				cout1 = 0;
			}
		}
		v1.push_back(cout1);
		auto maxPosition = std::max_element(v1.begin(), v1.end());
		std::cout << *maxPosition << std::endl;
	}
	return 0;
}