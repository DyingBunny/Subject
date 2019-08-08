#include<iostream>

int main()
{
	int arr[2000];
	arr[0] = 1;
	arr[1] = 1;
	int i = 2;
	while (i <= 1000)
	{
		arr[i] = (arr[i - 2] + arr[i - 1]);
		i++;
	}
	while (1)
	{
		int input = 0;
		std::cin >> input;
		std::cout << arr[input - 1] << std::endl;
	}
}