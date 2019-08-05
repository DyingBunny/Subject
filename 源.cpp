#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int pos=s1.find(s2);
	if (pos != string::npos)
	{
		if (s1[pos + s2.size()] == ','&&s1[pos-1] == ',')
		{
			cout << "Ignore" <<endl;
			return 0;
		}
		else
		{
			cout << "Important!" << endl;
			return 0;
		}
	}
	else{
		cout << "Important!" << endl;
		return 0;
	}
}