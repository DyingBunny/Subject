#include<iostream>
#include<stack>
#include<vector>
int main()
{
	int  num = 0;
	std::cin >> num;
	int tmp = num;
	int begin = 1000;
	std::vector<int> v1;
	while (tmp!=v1.size())
	{
		int result = begin * 9;
		if (result >= 10000)
		{
			break;
		}
		else
		{
			std::stack<int> s;
			while (result)
			{
				s.push(result % 10);
				result /= 10;
			}
			int tmp1 = begin;
			while (tmp1)
			{
				if (s.top() != tmp1 % 10)
				{
					goto End;
				}
				s.pop();
				tmp1 /= 10;
			}
			v1.push_back(begin);
			End:
			begin++;
		}
	}
	for (int i = 0; i < num;i++)
	{
		std::cout << v1[num] << std::endl;
	}
	return 0;
}