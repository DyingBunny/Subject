#include<iostream>

int main()
{
	int a = 3;
	int b = 2;
	std::cout << (a^b) + ((a&b) << 1) << std::endl;
	return 0;
}