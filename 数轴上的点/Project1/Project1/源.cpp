#include<iostream>
#include<set>

int main()
{
	int n;
	std::cin >> n;
	std::set<int> s1;
	while (n)
	{
		int a, b;
		std::cin >> a >> b;
		for (int i = a; i <= b;i++)
		{
			s1.insert(i);
		}
		n--;
	}
	std::cout << s1.size() << std::endl;
	s1.clear();
	return 0;
}