#include<iostream>
#include<string>

int main()
{
	std::string result = "";
	std::string table = "0123456789ABCDEF";
	int M=0, N=0;
	std::cin >> M >> N;

	while (M)
	{
		if (M < 0)
		{
			M = -M;
			std::cout << "-";
		}
		result = table[M%N]+result;
		M /= N;
	}

	std::cout << result << std::endl;
	return 0;
}
