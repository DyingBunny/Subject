#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int input;
	vector<int> result;
	string s1 = "";
	vector<int> v1;
	cin >> input;
	cin.ignore();
	while ((input) != 0)
	{
		getline(cin, s1);
		if (s1[0] == 'a')
		{
			s1.erase(s1.begin());
			s1.erase(s1.begin());
			s1.erase(s1.begin());
			s1.erase(s1.begin());
			int num = stoi(s1);
			v1.push_back(num);
		}
		else
		{
			sort(v1.begin(), v1.end());
			result.push_back(v1[v1.size() / 2]);
			v1.erase(v1.begin() + (v1.size() / 2));
		}
		input--;
	}
	for (const auto&it : result)
	{
		printf("%d\n", it);
	}
	return 0;
}