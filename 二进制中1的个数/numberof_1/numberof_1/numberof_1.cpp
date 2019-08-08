#include<iostream>

int  NumberOf1(int n) 
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1)&n;
	}
	return count;
}

int  NumberOf1_(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

int main()
{
	int input = 15;
	int result = NumberOf1_(input);
	std::cout << result << std::endl;
	return 0;
}