#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	std::vector<long long> v;
	long long tmp[1000];
	long long n;
	while (std::cin >> n)
	{
		v.push_back(n);
	}
	for (long long i = 1; i <= v.size(); i++)
	{
		tmp[i] = 1;
	}
	for (long long i = 1; i < v.size(); i++)
	{
		for (long long j = 1; j < i; j++)
		{
			if (v[i]>v[j])
			{
				tmp[i] = std::max(tmp[j] + 1, tmp[i]);
			}
		}
	}
	std::cout << *std::max_element(tmp + 1, tmp + n + 1) << std::endl;
	return 0;
}