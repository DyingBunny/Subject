#include<iostream>
#include<vector>
int main()
{
	int n = 0;
	int m = 0;
	int j = 0;
	int i = 0;
	std::cin >> n >> m >> j >> i;
	int cout1 = 0;
	int index = 0;
	std::vector<int> s1;
	std::vector<int>s2;
	int res = 0;
	int cout2 = 0;
	while (n != 0)
	{
		if ((n % 2) == 1)
		{
			s1.push_back(1);
		}
		else
		{
			s1.push_back(0);
		}
		n = n / 2;
		cout1++;
	}
	cout2 = cout1;
	while (m != 0)
	{
		if ((m % 2) == 1)
		{
			s2.push_back(1);
		}
		else
		{
			s2.push_back(0);
		}
		m = m / 2;
	}
	while (j!=(i+1))
	{
		if (s2[index] == 1)
		{
			s1[j] = s2[index];
		}
		index++;
		j++;
	}
	auto it = s1.end() - 1;
	while (cout2)
	{
		if (*it == 1)
		{
			res = (res*2) + 1;
		}
		else
		{
			res = res * 2;
		}
		if (it == s1.begin())
		{
			goto index;
		}
		it--;
		cout2--;
	}
	index:
	std::cout << "����"<<":"<<res << std::endl;
}

//int main()
//{
//	int n = 11002;
//	int m = 19;
//	int j = 2;
//	int i = 6;
//	int res = n | (m << j);
//	std::cout << res << std::endl;
//	return 0;
//}
//10011
//10101011111010
//10101011111110