//Fibonacci数列是这样定义的
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int arr[10000];
//	int tmp1 = 0;
//	int tmp2 = 0;
//	arr[0] = 0;
//	arr[1] = 1;
//	int i = 2;
//	for (i = 2; i < 10000; i++)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	int a;
//	scanf("%d", &a);
//	int j = 0;
//	for (j = 0; j < 10000; j++)
//	{
//		if ((arr[j] >= a) && (arr[j - 1] <= a))
//		{
//			tmp1 = arr[j] - a;
//			tmp2 = a - arr[j - 1];
//			break;
//		}
//	}
//	if (tmp1 > tmp2)
//	{
//		printf("%d", tmp2);
//	}
//	else
//	{
//		printf("%d", tmp1);
//	}
//	system("pause");
//	return 0;
//}

//添加一个字母变为回文串
//#include<iostream>
//#include <string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string s;
//	con:cin >> s;
//	int i = 0;
//	int j = s.length() - 1;
//	for (i = 1; i < s.length(); i++)
//	{
//		if (s[i] != s[j])
//		{
//			printf("NO\n");
//			goto con;
//		}
//		else if (i >= j)
//		{
//			printf("YES\n");
//			goto con;
//		}
//		j--;
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//
//#include <string>
//#include <algorithm>
//using namespace std;
//
////判断回文方法1
//bool IsHuiWen(string str)
//{
//	string rstr = str;
//	reverse(rstr.begin(), rstr.end());
//	return str == rstr;
//}
//
//int main(){
//	string str;
//	while (cin >> str){
//		bool flag = false;
//		for (int i = 0; i<(int)str.size(); ++i){
//			if (IsHuiWen(str.substr(0, i) + str.substr(i + 1, str.size() - 1 - i))){
//				flag = true;
//				break;
//			}
//		}
//		cout << ((flag == true) ? "YES" : "NO") << endl;
//	}
//	return 0;
//}