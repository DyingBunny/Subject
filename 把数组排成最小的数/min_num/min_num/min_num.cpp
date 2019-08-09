#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
static bool cmp(int a, int b){
	std::string A = "";
	std::string B = "";
	A += std::to_string(a);
	A += std::to_string(b);
	B += std::to_string(b);
	B += std::to_string(a);

	return A < B;
}

std::string PrintMinNumber(std::vector<int> numbers) {
	std::string result;
	std::sort(numbers.begin(), numbers.end(), cmp);
	for (auto it : numbers){
		result += std::to_string(it);
	}
	return result;
}