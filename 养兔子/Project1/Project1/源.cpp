#include<iostream>

int main()
{
	long long arr[91] = { 0 };
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 90; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n = 0;
	while (std::cin >> n)
	{
		std::cout << arr[n] << std::endl;
	}
	return 0;
}