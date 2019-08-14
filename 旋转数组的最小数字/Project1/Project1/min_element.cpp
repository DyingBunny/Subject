#include<iostream>
#include<vector>
#include<algorithm>

int minNumberInRotateArray(std::vector<int> rotateArray){
	return *std::min_element(rotateArray.begin(), rotateArray.end());
}
