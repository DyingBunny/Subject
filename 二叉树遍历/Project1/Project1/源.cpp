#include<iostream>
#include<cstring>
using namespace std;

int tree(char *mid, char *last)
{
	char t, *p, *q;
	if (!*mid)
	{
		return 0;
	}
	p = last + strlen(last) - 1;
	std::cout << p;
	q = strchr(mid, *p);
	*p = 0;
	p = q - mid + last;
	t = *p;
	*p = 0;
	*q = 0;
	tree(mid, last);
	*p = t;
	tree(q + 1, p);
}

int main()
{
	char mid[100010];
	char last[100010];
	std::cin >> mid;
	std::cin >> last;
	tree(mid, last);
	std::cout << endl;
	return 0;
}