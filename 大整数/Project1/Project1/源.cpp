#include<iostream>

int main()
{
	long long input;
	std::cin >> input;
	for (long long i = input/2; i >= 0; i--)
	{
		if ((i * 3) + (i*i) + (i*i*i) <= input)
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}