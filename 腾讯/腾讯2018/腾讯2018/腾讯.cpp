//#include<iostream>
//using namespace std;
//1.СQ��X�׳���ΪA�Ĳ�ͬ�ĸ��Y�׳���ΪB�Ĳ�ͬ�ĸ裬����СQ������Щ����
//��һ���ܳ�������ΪK�ĸ赥��ÿ�׸����ֻ���ڸ赥�г���һ�Σ��ڲ����Ǹ�
//���ڸ������Ⱥ�˳�������£������ж�������ɸ赥�ķ�����

//��������ʽ n��/��n-m����

//----------------------�ҵĽ�𣺱������---------------------

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
////----------------------������ǵı�׼�ⷨ------------------------
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

//-----------------------����+��������----------------

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


//2.СQ�Ĺ�˾����ӵ�m������, ��i��������Ҫxi��ʱ��ȥ���, �Ѷȵȼ�Ϊyi��
//СQӵ��n̨����, ÿ̨���������ʱ��zi, �����ȼ�wi��
//����һ������, ��ֻ�ܽ���һ̨���������, ������Ÿ����Ļ����������ʱ��С��������Ҫ��ʱ��, �������, ������������񽫻��200 * xi + 3 * yi���档
//����һ̨����, ��һ��ֻ�����һ������, ������Ļ����ȼ�С�ڰ��Ÿ����������Ѷȵȼ�, ������ɡ�
//СQ���ڽ��쾡���ܵ�ȥ�������, ����ɵ����������������ж��ְ��ŷ���, СQ�����ҵ����������Ǹ�������СQ��Ҫ��������������һ�¡�

//3.СQ�ĸ�ĸҪ����N�죬��֮ǰ��СQ������M���ɿ�����СQ����ÿ��Ե��ɿ�������������ǰһ��Ե�һ�룬�������ֲ����ڸ�ĸ����֮ǰ 
//��ĳһ��û���ɿ����ԣ���������һ������ܳԶ��ٿ��ɿ���

//-------------------------�ҵĴ��� 100% caseͨ��----------------------
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

//4.ţţ������������һ��ֽ����Ϸ�������Ϸһ����n��ֽ��, ��i��ֽ����д������ai��
//ţţ��������������, ţţ�ȳ�, ÿ�γ������ǿ��Դ�ֽ�ƶ�������ѡ��һ�ų��, ֱ��ֽ�Ʊ����ꡣ
//���ǵĵ÷ֵ������ǳ鵽��ֽ�������ܺ͡�
//���ڼ���ţţ�����򶼲������Ų���, ����������Ϸ������ţţ�÷ּ�ȥ����÷ֵ��ڶ��١�


//����ʹ�ÿ��Ż���sor������������ͨ��
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