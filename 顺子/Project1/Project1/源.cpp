#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
int Find(vector<int> v1);
int Find(vector<int> v1)
{
	sort(v1.begin(), v1.end());
	vector<vector<int>> dp(v1.size()+1, vector<int>(14, 0));
	for (int i = 1; i <= v1.size() + 1; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			if (v1[i] == j)
			{
				int flag = 0;
				while (i >= 1)
				{
					dp[i][j]
				}
			}
		}
	}
}

int main()
{
	vector<int> v1;
	int num;
	cin >> num;
	while (num != 0)
	{
		int num1;
		cin >> num1;
		while (num1 != 0)
		{
			char a;
			cin >> a;
			if (a == 'A')
			{
				v1.push_back(1);
			}
			if (a == '2')
			{
				v1.push_back(2);
			}
			if (a == '3')
			{
				v1.push_back(3);
			}
			if (a == '4')
			{
				v1.push_back(4);
			}
			if (a == '5')
			{
				v1.push_back(5);
			}
			if (a == '6')
			{
				v1.push_back(6);
			}
			if (a == '7')
			{
				v1.push_back(7);
			}
			if (a == '8')
			{
				v1.push_back(8);
			}
			if (a == '9')
			{
				v1.push_back(9);
			}
			if (a == '10')
			{
				v1.push_back(10);
			}
			if (a == 'J')
			{
				v1.push_back(11);
			}
			if (a == 'Q')
			{
				v1.push_back(12);
			}
			if (a == 'K')
			{
				v1.push_back(13);
			}
			num1--;
		}
		num--;
	}
	return 0;
}