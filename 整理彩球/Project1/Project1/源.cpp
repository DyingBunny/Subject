#include <iostream>
#include <vector>
#include <numeric>
#include <limits.h>
#include<algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int tmp = num;
	vector<int> v1;
	while (tmp)
	{
		int a;
		cin >> a;
		v1.push_back(a);
		tmp--;
	}	
	if (v1.size() % 2 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	else
	{
		vector<int>bucket(200, 0);
		for (int i = 0; i < v1.size(); i++)
		{
			bucket[v1[i]] += 1;
		}
		int firstmin = INT_MAX;
		int secondmin = INT_MAX;
		for (auto value : bucket)
		{
			if (value < firstmin)
			{
				secondmin = firstmin;
				firstmin = value;
			}
			else if (value < secondmin&&value != firstmin)
			{
				secondmin = value;
			}
		}
		cout << v1.size() / secondmin << endl;
	}
	return 0;
}
