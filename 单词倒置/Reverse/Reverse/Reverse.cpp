#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	std::string s1;
	while (getline(cin, s1))
	{
		std::string::iterator j = s1.end() - 1;
		if ((*j) != '.')
		{
			s1.push_back(' ');
		}
		std::string tmp;
		std::string s2;
		int count = 0;
		for (std::string::iterator i = s1.end() - 1; i != s1.begin(); i--)
		{
			if ((*i) == ' ' || (*i) == '.')
			{
				std::reverse(tmp.begin(), tmp.end());
				s2 = s2 + tmp;
				tmp.clear();
			}
			tmp.push_back(*i);
		}
		tmp.clear();
		for (std::string::iterator i = s1.begin(); i != s1.end(); i++)
		{
			if ((*i) == ' ')
			{
				s2 = s2 + tmp;
				break;
			}
			tmp.push_back(*i);
		}
		std::cout << s2 << std::endl;
	}
	return 0;
}

//int main()
//{
//	std::string tmp = "I very like china";
//	std::string s1 = "I";
//	std::reverse(tmp.begin(), tmp.end());
//	s1 = s1 + tmp;
//	std::cout << s1 << std::endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//
//void reverseStr(string &s, int begin, int end){
//
//	while (begin < end) {
//		char temp = s[begin];
//		s[begin] = s[end];
//		s[end] = temp;
//		begin++;
//		end--;
//	}
//}
//
//
//int main(){
//
//	string s;
//
//	while (getline(cin, s)) {
//
//		int length = (int)s.length();
//		reverseStr(s, 0, length - 1); //先将句子按字符反转
//
//		int j = 0;
//		for (int i = 0; i<length; i++) {
//			if (s[i] == ' ') {
//				reverseStr(s, j, i - 1); //再将句子的单词按字符反转
//				j = i + 1;
//			}
//		}
//		cout << s << endl;
//	}
//
//	return 0;
//}
