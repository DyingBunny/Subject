#include<iostream>

int main()
{
	int a, b, result;
	std::cin >> a >> b;
	for (result = a;; result++)
	{
		if (result%a == 0 && result%b == 0)
		{
			break;
		}
	}
	std::cout << result << std::endl;
	return 0;
}
