#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
	string s1;
	cin >> s1;
	vector<char> v1;
	for (const auto&it : s1)
	{
		if (find(v1.begin(), v1.end(), it) == v1.end())
		{
			v1.push_back(it);
		}
	}
	for (const auto& tmp : v1)
	{
		cout << tmp;
	}
	return 0;
}
