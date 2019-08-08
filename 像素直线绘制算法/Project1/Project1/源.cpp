#include<iostream>

using namespace std;

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		if (x == y)
		{
			cout << (x + 1) << endl;
		}
		else if ((x+1)%(y+1)==0)
		{
			cout << (x + 1) << endl;
		}
		else if ((y+1)%(x+1)==0)
		{
			cout << (y + 1) << endl;
		}
		else
		{
			cout << (x + y + 1) << endl;
		}
	}
	return 0;
}