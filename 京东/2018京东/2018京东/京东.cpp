//1.东东对幂运算很感兴趣,在学习的过程中东东发现了一些有趣的性质: 9^3 = 27^2, 2^10 = 32^2
//东东对这个性质充满了好奇, 东东现在给出一个整数n, 希望你能帮助他求出满足 a^b = c^d(1 ≤ a, b, c, d ≤ n)的式子有多少个。

//----------------------我的方法20%通过，大数问题--------------------

//#include<iostream>
//using namespace std;
//
//void Init(int n, long long arr1[20000], long long arr2[20000])
//{
//	int a, b;
//	long long x, y;
//	int i = 0;
//	for (a = 1; a <= n; a++)
//	{
//		for (b = 1; b <= n; b++)
//		{
//			x = a;
//			y = b;
//			for (; y >= 1; y--)
//			{
//				if (y == 1)
//				{
//					x = x;
//				}
//				else
//				{
//					x = x*a;
//				}
//			}
//			arr1[i] = x;
//			arr2[i] = x;
//			i++;
//		}
//	}
//}
//
//int Change(int n, long long arr1[20000], long long arr2[20000])
//{
//	int i, j;
//	int cout = 0;
//	n = n*n;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				cout++;
//			}
//		}
//	}
//	return cout;
//}
//int main()
//{
//	int n;
//	int result;
//	long long arr1[20000];
//	long long arr2[20000];
//	scanf("%d",&n);
//	Init(n, arr1, arr2);
//	result = Change(n, arr1, arr2);
//	result = result % 1000000007;
//	printf("%d", result);
//	system("pause");
//	return 0;
//}

//--------------------------网络答案100%---------------------
//#include<iostream>
//#include<cmath>
//using namespace std;
//int gcd(int a, int b)//求公约数
//{
//	int c;
//	c = (a>b) ? b : a;
//	while (a%c != 0 || b%c != 0)
//	{
//		c--;
//	}
//	return c;
//}
//int geshu(int a, int b, int n){//求最多组合数
//	int c = gcd(a, b);
//	return floor(n / (b / c));
//}
//long long fun(int i, int n){//求以i为底，在n里面有多少个次幂，1,2,3,4.。k然后任意两个不同的组合，
//	int k = 2;
//	int temp = i*i;
//	while (temp*i <= n){
//		temp *= i;
//		k++;
//	}
//	long long ans = 0;
//	for (int j = 1; j<k; j++){
//		for (int l = j + 1; l <= k; l++){
//			ans += geshu(j, l, n);
//			ans %= 1000000007;
//		}
//
//	}
//	return ans;
//}
//bool zhishu(int i){//判断i是否是2-i里面中某个数的k次幂，n最大10的6次方，i最大10的三次方，即最大2的10次方
//	int k = sqrt(i);
//	for (int j = k; j >= 2; j--){
//		if (i%j == 0){
//			int temp = i;
//			while (temp != 1 && temp%j == 0){
//				temp /= j;
//			}
//			if (temp == 1){
//				return true;
//			}
//		}
//	}
//	return false;
//}
//int main(){
//	long long n;
//	cin >> n;
//	long long ans = 0;
//	ans += n*(2 * n - 1);//以1位底的互相组合n*n，两边相同的n*(n-1)
//	ans %= 1000000007;
//	for (int i = 2; i<n; i++){//求非1为底，两边不相同的组合。
//		if (i*i>n){//停止条件
//			break;
//		}
//		if (!zhishu(i)){//不是1-（i-1）的某个数的幂次就运行fun函数，计算种类数
//			ans += 2 * fun(i, n);//函数没有调转，所以*2
//		}
//		ans %= 1000000007;
//	}
//
//	cout << ans;
//	system("pause");
//}

//2.东东在一本古籍上看到有一种神奇数, 如果能够将一个数的数字分成两组, 其中一组数字的和等于
//另一组数字的和, 我们就将这个数称为神奇数。例如242就是一个神奇数, 我们能够将这个数的数字
//分成两组, 分别是{ 2, 2 }以及{ 4 }, 而且这两组数的和都是4.东东现在需要统计给定区间中有多
//少个神奇数, 即给定区间[l, r], 统计这个区间中有多少个神奇数, 请你来帮助他。

//---------------------------20%通过-----------------------

//#include<iostream>
//#include<vector>
//using namespace std;
//
////判断
//int Judge(int n,int m)
//{
//	int i =n;
//	int x,y;
//	int cout = 0;
//	int MaxNum=0;
//	vector<int> EveNum;
//	for (; i <= m; i++)
//	{
//		//将每一位放入vector中
//		for (x = i; x > 0; x /= 10)
//		{
//			y = x % 10;
//			EveNum.push_back(y);
//			MaxNum++;
//		}
//		//进行判断
//		vector<int>::iterator pd;
//		vector<int>::iterator pd1;
//		vector<int>::iterator tmp;
//		if (MaxNum == 1)
//		{
//			cout += 0;
//		}
//		else if (MaxNum == 2)
//		{
//			pd = EveNum.begin();
//			if (*pd==*(pd+1))
//			{ 
//				cout++;
//			}
//		}
//		else
//		{		
//			for (pd = (EveNum.begin()); pd != EveNum.end(); pd++)
//			{
//				for (pd1=pd + 1; pd1!= EveNum.end(); pd1++)
//				{
//					tmp = EveNum.begin();
//				loop1:
//					if (&(*tmp) == &(*pd) || &(*tmp) == &(*pd1))
//					{
//						tmp++;
//						goto loop1;
//					}
//					else
//					{
//						if ((*pd + (*pd1)) == *tmp)
//						{
//							cout++;
//							goto loop;
//						}
//					}
//				}
//			}
//		}
//		loop:
//		MaxNum = 0;
//		EveNum.clear();
//
//	}
//	return cout;
//}
//
//int main()
//{
//	int n, m, MaxNum;
//	int result;
//	scanf("%d%d", &n, &m);
//	result = Judge(n, m);
//	printf("%d", result);
//	system("pause");
//	return 0;
//}

//----------------------------------100%通过------------------------
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool IsNum(int &in){
//	vector<int> arry;
//	int num = in;
//	int half = 0;
//	while (num){//将数字打散存入arry数组
//		arry.push_back(num % 10);
//		half += num % 10;
//		num /= 10;
//	}
//	if (half % 2 != 0) return false;
//	half /= 2;
//	vector<int> dp(half + 1); //之后这一小段用的是01背包，判断能装下最大的数和一半是否相等。
//	for (int i = 0; i<arry.size(); i++){
//		for (int j = half; j >= arry[i]; j--){
//			dp[j] = max(dp[j], dp[j - arry[i]] + arry[i]);
//		}
//	}
//	return dp[half] == half;
//}
//
//
//
//int main()
//{
//	int l, r;
//	cin >> l >> r;
//	int count = 0;
//	for (int i = l; i <= r; i++){
//		if (IsNum(i))
//			count++;//如果是神奇数，计数+1
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

//3.牛牛对整除非常感兴趣。牛牛的老师给他布置了一道题:牛牛的老师给出一个n,然后牛牛需
//要回答出能被1到n之间(包括1和n)所有整数整除的最小的数。牛牛犯了难,希望你能编程帮他解决这个问题。

#include<iostream>
#include<algorithm>
using namespace std;

void Put(int n,int arr[20000])
{
	int i;
	int j;
	for (i = 1; i <= n; i++)
	{
		int k = i;
		for (j = 2; j*j <= n; j++)
		{
			int s = 0;
			while (k%j == 0)
			{
				s++;
				k = k / j;
			}
			arr[j] = max(arr[j], s);
		}
		if (k > 1)
		{
			arr[k] = max(arr[k], 1);
		}
	}
}

int main()
{
	int n=0;
	int arr[20000] = {0};
	scanf("%d", &n);
	Put(n, arr);
	long long res = 1;
	for (int j = 1; j <= n; j++)
	{
		if (arr[j] > 0)
		{
			for (int m = 1; m <= arr[j]; m++)
			{
				res = res*j%987654321;
			}
		}
	}
	printf("%lld", res);
	system("pause");
	return 0;
}