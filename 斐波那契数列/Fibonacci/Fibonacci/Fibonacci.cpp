#include<iostream>


int main()
{
	long long arr[100];
	int i = 2;
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i < 100;i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int input = 0;
	int m = 0;
	int n = 0;
	std::cin >> input;
	for (i = 0; i < 99; i++)
	{
		if (arr[i] <= input&&arr[i + 1]>input)
		{
			m = input - arr[i];
			n = arr[i + 1] - input;
			if (m > n)
			{
				std::cout << n << std::endl;
				break;
			}
			else
			{
				std::cout << m << std::endl;
				break;
			}
		}
	}

}