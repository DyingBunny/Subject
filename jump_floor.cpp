#include<iostream>

int jumpFloor(int number) 
{
	if (number < 2)
	{
		return 1;
	}
	return jumpFloor(number - 1) + jumpFloor(number-2);
}

int main()
{
	int input = 3;
	int result = jumpFloor(input);
	std::cout << result << std::endl;
	return 0;
}