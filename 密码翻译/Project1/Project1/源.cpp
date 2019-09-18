#include<iostream>
#include<string>

int main()
{
	std::string s;
	while (std::getline(std::cin,s))
	{
		for (int i = 0; i <s.size(); i++)
		{
			if ('a' <= s[i] && s[i] <= 'y')
			{
				s[i]++;
			}
			else if ('A' <= s[i] && s[i] <= 'Y')
			{
				s[i]++;
			}
			else if (s[i] == 'z')
			{
				s[i] = 'a';
			}
			else if (s[i] == 'Z')
			{
				s[i] = 'A';
			}
		}
		std::cout << s << std::endl;
	}
	return 0;
}