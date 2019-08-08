#include<iostream>
#include<vector>
#include<iterator>

int cardGame(std::vector<int> A, int n);
int cardGame(std::vector<int> A, int n)
{
	// write code here
	int a = 0;
	int b = 0;
	while (!A.empty())
	{
		if (A[0] >= A[n - 1])
		{
			a = a + A[0];
			reverse(A.begin(), A.end());
			A.pop_back();
			n--;
			reverse(A.begin(), A.end());
		}
		else
		{
			a += A[n - 1];
			A.pop_back();
			n--;
		}
		if (A.empty())
		{
			break;
		}
		if (A[0] >= A[n - 1])
		{
			b += A[0];
			reverse(A.begin(), A.end());
			A.pop_back();
			n--;
			reverse(A.begin(), A.end());
		}
		else
		{
			b += A[n - 1];
			A.pop_back();
			n--;
		}
	}
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	std::vector<int> v1{19, 11, 45, 45, 43, 0, 77, 78, 86, 50, 40, 12, 35, 26, 35, 3, 58, 24, 63, 79, 23, 59, 8, 64, 99, 68, 35, 28, 61, 72, 54, 30, 50, 70, 40, 52, 82, 34, 8, 9, 46, 22, 84, 67, 70, 56, 11, 59, 54, 60, 97, 38, 0, 90, 81, 44, 75, 76, 74, 86, 73, 90, 53, 70, 56, 92, 50, 84, 95, 9, 6, 50, 39, 32, 14, 93, 1, 72};
	int input = 78;
	int result = cardGame(v1, input);
	std::cout << result << std::endl;
	return 0;
}