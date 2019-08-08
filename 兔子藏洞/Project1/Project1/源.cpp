#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v1(20, 0);
	int x, n;
	cin >> x >> n;
	int tmp = 0;
	x = x - 1;
	while (n != 0)
	{
		int add = 0;
		add = x + tmp;
		if ((add)>19)
		{
			add = add - 20;
		}
		v1[x + tmp] += 1;
		x += tmp;
		tmp += 1;
		n--;
	}
	return 0;
}