#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int tmp = n;
	std::vector<int> v1;
	std::vector<int> result;
	while (tmp)
	{
		int input;
		std::cin >>  input;
		v1.push_back(input);
		tmp--;
	}
	//¥¶¿Ì
	int x = n - m;
	while (x!=-1)
	{
		int sum = 0;
		for (int i = x; i < m+x; i++)
		{
			sum += v1[i];
		}
		result.push_back(sum);
		x--;
	}
	float a = (float(*std::max_element(result.begin(), result.end())) / m);
	printf("%.3f\n", a);
	return 0;
}