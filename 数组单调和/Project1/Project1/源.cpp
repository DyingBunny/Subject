#include<iostream>
#include<vector>

using namespace std;
int calcMonoSum(vector<int> A, int n)
{
	int count = 0;
	if (n == 1)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i<(n - 1); i++)
		{
			if (A[i] <= A[n - 1])
			{
				count += A[i];
			}
		}
	}
	return count + calcMonoSum(A, (n - 1));
}

int main()
{
	int a = 0;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	a = calcMonoSum(v1, 6);
	std::cout << a << std::endl;
	return 0;
}