#include<iostream>
#include<string>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	auto begin = input.end()-1;
	auto end = begin;
	for (; *begin != ' '; begin--)
	{
		;
	}
	
	return 0;
}