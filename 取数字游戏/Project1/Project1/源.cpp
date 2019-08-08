#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int num1 = num;
		vector<int> v1;
		vector<int> result;
		while (num != 0)
		{
			int input;
			cin >> input;
			v1.push_back(input);
			num--;
		}
		int tmp = 0;
		while (num1 != 0)
		{
			if (abs(v1[0] - tmp) > abs(v1[v1.size() - 1] - tmp))
			{
				tmp = v1[0];
				result.push_back(v1[0]);
				v1.erase(v1.begin());
			}
			else
			{
				tmp = v1[v1.size() - 1];
				result.push_back(v1[v1.size() - 1]);
				v1.erase(v1.end() - 1);
			}
			num1--;
		}
		int output = 0;
		for (int i = 0; i < (result.size() - 1); i++)
		{
			output = output + abs((result[i] - result[i + 1]));
		}
		cout << output << endl;
	}
	return 0;
}