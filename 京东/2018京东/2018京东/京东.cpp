//1.������������ܸ���Ȥ,��ѧϰ�Ĺ����ж���������һЩ��Ȥ������: 9^3 = 27^2, 2^10 = 32^2
//������������ʳ����˺���, �������ڸ���һ������n, ϣ�����ܰ������������ a^b = c^d(1 �� a, b, c, d �� n)��ʽ���ж��ٸ���

//----------------------�ҵķ���20%ͨ������������--------------------

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

//--------------------------�����100%---------------------
//#include<iostream>
//#include<cmath>
//using namespace std;
//int gcd(int a, int b)//��Լ��
//{
//	int c;
//	c = (a>b) ? b : a;
//	while (a%c != 0 || b%c != 0)
//	{
//		c--;
//	}
//	return c;
//}
//int geshu(int a, int b, int n){//����������
//	int c = gcd(a, b);
//	return floor(n / (b / c));
//}
//long long fun(int i, int n){//����iΪ�ף���n�����ж��ٸ����ݣ�1,2,3,4.��kȻ������������ͬ����ϣ�
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
//bool zhishu(int i){//�ж�i�Ƿ���2-i������ĳ������k���ݣ�n���10��6�η���i���10�����η��������2��10�η�
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
//	ans += n*(2 * n - 1);//��1λ�׵Ļ������n*n��������ͬ��n*(n-1)
//	ans %= 1000000007;
//	for (int i = 2; i<n; i++){//���1Ϊ�ף����߲���ͬ����ϡ�
//		if (i*i>n){//ֹͣ����
//			break;
//		}
//		if (!zhishu(i)){//����1-��i-1����ĳ�������ݴξ�����fun����������������
//			ans += 2 * fun(i, n);//����û�е�ת������*2
//		}
//		ans %= 1000000007;
//	}
//
//	cout << ans;
//	system("pause");
//}

//2.������һ���ż��Ͽ�����һ��������, ����ܹ���һ���������ֳַ�����, ����һ�����ֵĺ͵���
//��һ�����ֵĺ�, ���Ǿͽ��������Ϊ������������242����һ��������, �����ܹ��������������
//�ֳ�����, �ֱ���{ 2, 2 }�Լ�{ 4 }, �������������ĺͶ���4.����������Ҫͳ�Ƹ����������ж�
//�ٸ�������, ����������[l, r], ͳ������������ж��ٸ�������, ��������������

//---------------------------20%ͨ��-----------------------

//#include<iostream>
//#include<vector>
//using namespace std;
//
////�ж�
//int Judge(int n,int m)
//{
//	int i =n;
//	int x,y;
//	int cout = 0;
//	int MaxNum=0;
//	vector<int> EveNum;
//	for (; i <= m; i++)
//	{
//		//��ÿһλ����vector��
//		for (x = i; x > 0; x /= 10)
//		{
//			y = x % 10;
//			EveNum.push_back(y);
//			MaxNum++;
//		}
//		//�����ж�
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

//----------------------------------100%ͨ��------------------------
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
//	while (num){//�����ִ�ɢ����arry����
//		arry.push_back(num % 10);
//		half += num % 10;
//		num /= 10;
//	}
//	if (half % 2 != 0) return false;
//	half /= 2;
//	vector<int> dp(half + 1); //֮����һС���õ���01�������ж���װ����������һ���Ƿ���ȡ�
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
//			count++;//�����������������+1
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

//3.ţţ�������ǳ�����Ȥ��ţţ����ʦ����������һ����:ţţ����ʦ����һ��n,Ȼ��ţţ��
//Ҫ�ش���ܱ�1��n֮��(����1��n)����������������С������ţţ������,ϣ�����ܱ�̰������������⡣

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