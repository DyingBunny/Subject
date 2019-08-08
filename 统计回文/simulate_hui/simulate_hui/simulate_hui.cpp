#include<iostream>
#include<string>
#include<algorithm>
bool judge_hui(std::string s1)
{
	std::string s2 = s1;
	std::reverse(s1.begin(), s1.end());
	int i = 0;
	for (auto it : s1)
	{
		if (it != s2[i])
		{
			return false;
		}
		++i;
	}
	return true;
}
int main()
{
	std::string s1, s2, tmp;
	std::cin >> s1 >> s2;
	int count = 0;
	for (int i = 0; i <= s1.length(); i++)
	{
		tmp = s1;
		tmp.insert(i, s2);
		if (judge_hui(tmp))
		{
			count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}