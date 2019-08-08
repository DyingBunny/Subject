#include<iostream>
#include<string>

using namespace std;
int main()
{
	std::string s1;
	std::string s2;
	std::string tmp;
	int flag = 0;
	getline(cin, s1);
	getline(cin, s2);
	for (std::string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		for (std::string::iterator it1 = s2.begin(); it1 != s2.end(); it1++)
		{
			if ((*it) == (*it1))
			{
				flag++;
			}
		}
		if (flag == 0)
		{
			tmp.push_back((*it));
		}
		flag = 0;
	}
	std::cout << tmp << std::endl;
	return 0;
}