#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int num;
	std::cin >> num;
	double L = 0.00;
	int v0 = 0;
	int vt = 0;
	while (num)
	{
		int a, t;
		std::cin >> a >> t;
		L += (vt*t) + (0.5*a*t*t);
		vt = v0 + a*t;
		num--;
	}
	printf("%.1f\n", L);
	return 0;
}