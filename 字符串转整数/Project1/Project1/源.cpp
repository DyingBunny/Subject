#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
using namespace std;

int string2int(string str) 
{
	for (const auto it : str)
	{
		if (it >= 'a'&&it <= 'z' || it >= 'A'&&it <= 'Z'||it==' ')
		{
			return 0;
		}
	}
	return stoi(str);
}

int main() {
	int res;

	string _str;
	getline(cin, _str);

	res = string2int(_str);
	cout << res << endl;

	return 0;

}