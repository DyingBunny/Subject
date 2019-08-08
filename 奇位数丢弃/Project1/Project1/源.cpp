#include<iostream>
#include<vector>
#include<iterator>

//int Drop(int input);
//
//int drop(int input)
//{
//	std::vector<int> v1;
//	for (int i = 1; i <= input; i++)
//	{
//		v1.push_back(i);
//	}
//	//еп╤о
//	while (v1.size() != 0)
//	{
//		int size = v1.size();
//		if (size == 1)
//		{
//			return *(v1.begin());
//		}
//		else
//		{
//
//		}
//	}
//}

int main()
{
	int input = 0;
	std::cin >> input;
	int i = 1;
	while (i <= input + 1)
	{
		i <<= 1;
	}
	std::cout << ((i >>= 1) - 1) << std::endl;
	return 0;
}

//int main()
//{
//	std::vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.erase(v1.begin() + 0);
//	v1.erase(v1.begin() + 2);
//	for (auto it = v1.begin(); it != v1.end(); it++)
//	{
//		std::cout << (*it) << std::endl;
//	}
//	return 0;
//}