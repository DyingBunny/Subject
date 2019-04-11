#include<iostream>
#include<string>
#include<iterator>

std::string addToPalindrome(std::string A, int n);

int main()
{
	std::string s1 = "abccb";
	std::string result = addToPalindrome(s1, s1.size());
	std::cout << result << std::endl;
	return 0;
}

std::string addToPalindrome(std::string A, int n)
{
	std::string result;
	while (!A.empty())
	{
		std::string s2 = A;
		std::reverse(A.begin(), A.end());
		if (A == s2)
		{
			return result;
		}
		else
		{
			result.push_back(s2[0]);
			A.pop_back();
			std::reverse(A.begin(), A.end());
		}
	}
	return "";
}
