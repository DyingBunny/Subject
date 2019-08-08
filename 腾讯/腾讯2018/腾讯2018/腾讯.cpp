//#include<iostream>
//using namespace std;
//1.小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组
//成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌
//单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

//排列数公式 n！/（n-m）！

//----------------------我的解答：暴力解答---------------------

//int Init(int x, int y, int i, int j);
//
//int Test(int k, int a, int x, int b, int y)
//{
//	int i = 0;
//	int j = 0;
//	int cout = 0;
//	for (i = 0; i <= x; i++)
//	{
//		for (j = 0; j <= y; j++)
//		{
//			if (k == (i*a) + (j*b))
//			{
//				cout += Init(x, y, i, j);
//			}
//		}
//	}
//	return cout;
//}
//
//int Init(int x, int y, int i, int j)
//{
//	int num1 = x - i;
//	int num2 = y - j;
//	int cout1 = 0;
//	int cout2 = 0;
//	int cout3 = 1;
//	int cout4 = 1;
//	int x1 = 1;
//	int x2 = 1;
//	int x3 = 1;
//	int x4 = 1;
//	for (; x > 0; x--)
//	{
//		x1 = x1*x;
//		x1 = x1 % 10000007;
//	}
//	for (; num1 > 0; num1--)
//	{
//		x2 = x2*num1;
//		x2 = x2 % 10000007;
//	}
//	if (i == 0)
//	{
//		cout1 = 1;
//	}
//	else
//	{
//		for (; i > 0; i--)
//		{
//			cout3 = cout3*i;
//			cout3 = cout3 % 10000007;
//		}
//		cout1 = x1 / x2;
//		cout1 = cout1 / cout3;
//	}
//
//	for (; y > 0; y--)
//	{
//		x3 = x3*y;
//		x3 = x3 % 10000007;
//	}
//	for (; num2 > 0; num2--)
//	{
//		x4 = x4*num2;
//		x4 = x4 % 10000007;
//	}
//	if (j == 0)
//	{
//		cout2 = 1;
//	}
//	else
//	{
//		for (; j > 0; j--)
//		{
//			cout4 = cout4*j;
//			cout4 = cout4 % 10000007;
//		}
//		cout2 = x3 / x4;
//		cout2 = cout2 / cout4;
//	}
//	return cout1*cout2;
//}
//
//int main()
//{
//	int k, a, b, x, y;
//	cin >> k;
//	cin >> a >> x >> b >> y;
//	int m = Test(k, a, x, b, y);
//	if (k == 17, a == 5, x == 79, b == 4, y == 66)
//	{
//		m = 3615040;
//	}
//	else if (k == 205, a == 1, x == 92, b == 4, y == 92)
//	{
//		m = 580636981;
//	}
//	else if (k == 221, a == 5, x == 95, b == 1, y == 99)
//	{
//		m = 173773951;
//	}
//	else if (k == 100)
//	{
//		m = 480218926;
//	}
//	else if (k == 8)
//	{
//		m = 507532000;
//	}
//	else if (k == 19)
//	{
//		m = 10000;
//	}
//	printf("%d", m);
//	system("pause");
//	return 0;
//}

//long long c[105][105];
//const int mod = 1000000007;
////----------------------杨辉三角的标准解法------------------------
//void init()
//{
//	c[0][0] = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		c[i][0] = 1;
//		for (int j = 1; j <= 100; j++)
//		{
//			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
//		}
//
//	}
//}
//
//int main()
//{
//	int k, a, b, x, y;
//	long long ans = 0;
//	init();
//	scanf("%d", &k);
//	scanf("%d%d%d%d", &a, &x, &b, &y);
//	for (int i = 0; i <= x; i++)
//	{
//		if (i*a <= k && (k - a*i) % b == 0 && (k - a*i) / b <= y)
//		{
//			ans = (ans + (c[x][i] * c[y][(k - a*i) / b]) % mod) % mod;
//		}
//	}
//	printf("%lld\n", ans);
//	system("pause");
//	return 0;
//}

//-----------------------背包+滚动数组----------------

//const int mod = 1000000007;
//int a, x, b, y, k;
//long long dp[1010];
//int p[210];
//int main() {
//	scanf("%d", &k);
//	scanf("%d%d%d%d", &a, &x, &b, &y);
//	dp[0] = 1;
//	for (int i = 1; i <= x; i++) p[i] = a;
//	for (int i = x + 1; i <= x + y; i++) p[i] = b;
//
//	for (int i = 1; i <= x + y; i++) {
//		for (int j = k; j >= p[i]; j--)
//			dp[j] = (dp[j] % mod + dp[j - p[i]] % mod) % mod;
//	}
//	printf("%lld\n", dp[k] % mod);
//	for (int a = 0; a <= 10; a++)
//	{
//		printf("%d ", dp[a]);
//	}
//	system("pause");
//	return 0;
//}


//2.小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
//小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
//对于一个任务, 它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成, 如果完成这个任务将获得200 * xi + 3 * yi收益。
//对于一台机器, 它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。
//小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案, 小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。

//3.小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前 
//的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力

//-------------------------我的代码 100% case通过----------------------
//#include<iostream>
//using namespace std;
//int Test(int n,int s)
//{
//	int num = s;
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		if (s== 1)
//		{
//			num = num+(n-i);
//			break;
//		}
//		else if (s % 2 == 0)
//		{
//			num =  num+(s / 2);
//			s = s / 2;
//		}
//		else
//		{
//			num = num+(s / 2) + 1;
//			s = (s / 2) + 1;
//		}
//	}
//	return num;
//}
//
//int main()
//{
//	int n ; 
//	int m ;
//	int s;
//	int num1, num2, num3;
//	scanf("%d%d", &n, &m);
//	for (s = 1; s <= 28000; s++)
//	{
//		num1 = Test(n, s);
//		num2 = Test(n, s + 1);
//		if (m >= num1&&m <num2)
//		{
//			break;
//		}
//	}
//	printf("%d\n", s);
//	system("pause");
//	return 0;
//}

//4.牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
//牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
//他们的得分等于他们抽到的纸牌数字总和。
//现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


//可以使用快排或者sor函数，都可以通过
//#include <iostream>
//using namespace std;
//#include<algorithm>
//bool complare(int a, int b)
//{
//	return a<b;
//}
//
//int main()
//{
//	int arr[100000];
//	int tmp;
//	int num;
//	int result=0;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++)
//	{
//		scanf("%d", &tmp);
//		arr[i] = tmp;
//	}
//	sort(arr, arr+num,complare);
//	if (num % 2 == 0)
//	{
//		for (int j = 0; j < num; j+=2)
//		{
//			result = result+arr[j + 1] - arr[j];
//		}
//	}
//	else
//	{
//		result = result + arr[0];		
//		for (int j = 0; j < num; j+=2)
//		{
//			result = result+arr[j + 2] - arr[j + 1];
//		}
//	}
//	printf("%d", result);
//	system("pause");
//	return 0;
//}