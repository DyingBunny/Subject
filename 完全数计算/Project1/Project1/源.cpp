#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int input = 0;
	while (std::cin >> input)
	{
		int a;
		int count = 0;
		for (a = 2; a <= input; a++)
		{
			std::vector<int> v1;
			for (int i = 1; i <= a; i++)
			{
				if (a%i == 0)
				{
					std::vector<int>::iterator tmp = std::find(v1.begin(), v1.end(), i);
					if (tmp == v1.end())
					{
						v1.push_back(i);
						v1.push_back(a / i);
					}
				}
			}
			int add = 0;
			for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			{
				add = add + (*it);
			}
			if ((add - a) == a)
			{
				count++;
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}