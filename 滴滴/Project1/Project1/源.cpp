#include<iostream>

//int x = 4;
//
//int main(){
//		{
//			int x = 5;
//			std::cout << x;
//		}
//	std::cout << x << std::endl;
//	return 0;
//}

int main()
{
	char c, d;
	std:: cin>> c >> d;
	switch (c - '0')
	{
		case 1:switch (d%'0')
		{
			case 1:std::cout << '=';
			case 2:std::cout << '~';
		}
		case 2:switch (d%'0')
		{
			case 1:std::cout << '_';
			case 2:std::cout << '^';
		}
	}
	return 0;
}
