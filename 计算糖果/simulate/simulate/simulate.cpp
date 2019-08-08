#include <iostream>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int A, B, C;
	B = (b + d)/2;
	A = a + B;
	C = B - b;
	if (A + B == c)
	{
		std::cout << A << " " << B << " " << C;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
	return 0;
}