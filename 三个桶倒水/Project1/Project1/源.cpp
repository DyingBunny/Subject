#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int x, y, z, k;
	std::cin >> x >> y >> z >> k;
	//ÆæÅ¼ÊıÅĞ¶Ï
	int a = std::abs(x-y);
	int b = std::abs(x-z);
	int c = std::abs(y-z);
	int result = 0;
	int flag = 0;
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			for (int m = 0; m <= 5; m++)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					for (int j1 = 0; j1 <= 5; j1++)
					{
						for (int m1 = 0; m1 <= 5; m1++)
						{
							if (a == 0){
								if (j*b + m*c + i1*x + j1*y + m1*z == k)
								{
									result = (i+j + m) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (b == 0)
							{
								if (i*a + m*c + i1*x + j1*y + m1*z == k)
								{
									result = (i  + m) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (c == 0)
							{
								if (i*a + j*b  + i1*x + j1*y + m1*z == k)
								{
									result = (i+j) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (a == 0 && b == 0)
							{
								if (m*c + i1*x + j1*y + m1*z == k)
								{
									result = (m) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (a == 0 && c == 0)
							{
								if (j*b  + i1*x + j1*y + m1*z == k)
								{
									result = (j) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (b == 0 && c == 0)
							{
								if (i*a + i1*x + j1*y + m1*z == k)
								{
									result = (i) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else if (a == 0 && b==0&&c == 0)
							{
								if (i1*x + j1*y + m1*z == k)
								{
									result =(i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
							else
							{
								if (i*a + j*b + m*c + i1*x + j1*y + m1*z == k)
								{
									result = (i+j + m) * 3 + (i1 + j1 + m1) * 2;
									flag = 1;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	if (flag = 0)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << result << std::endl;
	}
	return 0;
}