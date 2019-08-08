#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
bool compare(int a, int b);
bool compare1(int a, int b);
int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> v1;
	while (n != 0)
	{
		int input = 0;
		cin >> input;
		v1.push_back(input);
		n--;
	}
	while (m != 0)
	{
		int flag = 0;
		int num = 0;
		cin >> flag >> num;
		if (flag == 0)
		{
			sort(v1.begin(), v1.begin() + (num), compare);
		}
		else if (flag == 1)
		{
			sort(v1.begin(), v1.begin() + (num), compare1);
		}
		m--;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it) << endl;
	}
	return 0;
}

bool compare(int a, int b)
{
	return a<b; //升序排列，如果改为return a>b，则为降序
}

bool compare1(int a, int b)
{
	return a>b; //升序排列，如果改为return a<b，则为降序
}