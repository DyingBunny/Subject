#include<iostream>
#include<vector>

int main()
{
	int people;
	while (std::cin >> people)
	{
		int result = 0;
		std::vector<int> v1 = { 100, 50, 20, 10, 5, 2, 1 };
		while (people != 0)
		{
			int money;
			std::cin >> money;
			for (const auto&tmp : v1)
			{
				if (money <= 0)
				{
					break;
				}
				if (tmp <= money)
				{
					int num = money / tmp;
					result += num;
					money -= num*tmp;
				}
			}
			people--;
		}
		std::cout << result << std::endl;
	}
	return 0;
}