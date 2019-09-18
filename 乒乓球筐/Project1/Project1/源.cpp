#include<iostream>
#include<string>
#include<map>

int main()
{
	std::string A, B;
	while (std::cin >> A >> B)
	{
		std::map<char, int> AA, BB;
		for (int i = 0; i < A.size(); i++)
		{
			AA[A[i]]++;
		}
		for (int i = 0; i < B.size(); i++)
		{
			BB[B[i]]++;
		}
		for (int i = 'A'; i <= 'Z'; i++)
		{
			if (BB[i]>AA[i])
			{
				std::cout << "No" << std::endl;
				break;
			}
			if (i == 'Z')
			{
				std::cout << "Yes" << std::endl;
			}
		}
	}
	return 0;
}