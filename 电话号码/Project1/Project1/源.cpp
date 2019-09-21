#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	int num;
	std::vector<std::string> result;
	std::cin >> num;
	while (num)
	{
		int count;
		std::string s1;
		std::cin >> count;
		std::cin >> s1;
		int flag = 1;
		while (flag)
		{
			for (auto it = s1.begin(); it != s1.end();)
			{
				if (*it=='8')
				{
					if (s1.size() == 11)
					{
						result.push_back("YES");
						flag = 0;
						break;
					}
					else
					{
						s1.erase(it);
						if (s1.empty())
						{
							result.push_back("NO");
							flag = 0;
							break;
						}
						it = s1.begin();	
					}
				}
				else if (*it != '8')
				{
					s1.erase(it);
					if (s1.empty())
					{
						result.push_back("NO");
						flag = 0;
						break;
					}
					it = s1.begin();
				}
				else
				{
					it++;
				}
			}
		}
		num--;
	}
	for (auto it : result)
	{
		std::cout << it << std::endl;
	}
	return 0;
}