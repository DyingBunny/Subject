#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	int m = 0;
	cin >> m;
	vector<int> result;
	int input = 0;
	while (m != 0)
	{
		vector<int> v1;
		int num = 4;
		while (num!=0)
		{
			cin >> input;
			v1.push_back(input);
			num--;
		}
		int count = 0;//�ܶ���
		int num1 = v1[0];
		if (num1 <= v1[2])//����С������
		{
			count = count + v1[0] + v1[1] / 2 + v1[3];
		}
		if (num1 > v1[2])//���˺�˫�����
		{
			count = count + v1[2] + v1[3];
			num1 = num1 - (v1[2]);
			if ((num1/2) >= 1)//��������>2
			{
				if ((num1 / 2) > v1[1])//���ű�˫�Ŷ�
				{
					count = count + v1[1];
					num1 = num1 - (v1[1] * 2);
					count = count + num1 / 4;//�����Լ���
				}
				else
				{
					count = count + (num1 / 2);
					v1[1] = v1[1] - (num1) / 2;
					count = count + (v1[1] / 2);//˫���Լ���
				}
			}
			else
			{
				count = count + num1/4 + (v1[1] / 2);
			}
		}
		result.push_back(count);
		m--;
	}
	for (vector<int>::iterator it1 = result.begin(); it1 != result.end(); it1++)
	{
		cout << (*it1) << endl;
	}
	return 0;
}

