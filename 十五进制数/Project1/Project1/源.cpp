#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define Divisor 2;
//��������������ת���ɲ�ͬ�Ľ���

char JudgeCharacter(const int &remainder)
//�ж�������Ӧ���ַ�
{
	if (remainder < 10)
	{
		char a[3];
		_itoa(remainder, a, 10);
		//int to char*��ת��
		return (char)*a;
	}
	else
	{
		return (char)(65 + (remainder - 10));
		//������10����ת�����ַ���ͨ����Ӧ��ASCII��ʵ��
	}
}

std::string DecimalToDivisor(const int &input)//
{
	std::string result;
	int remainder = 0;
	int tmp = input;
	char character;
	while (tmp != 0)
	{
		remainder = tmp%Divisor;
		character = JudgeCharacter(remainder);
		result += character;
		//string�в�������char
		tmp = tmp / Divisor;
	}
	std::reverse(result.begin(), result.end());
	//���õõ���Ӧ�Ľ�����
	return result;
}

int main()
{
	int input = 0;
	std::cout << "Please enter a number:" << std::endl;
	std::cin >> input;
	std::cout << "Result is: " << DecimalToDivisor(input) << std::endl;
}

bool Judeg(int input)
{
	vector<int> v1;
	stack<int> s1;
	while (input != 0)
	{
		int tmp = 0;
		tmp=input % 10;
		s1.push_back(tmp);
		s1.push(tmmp);
		input = input / 10;
	}
	for (const auto&it : v1)
	{
		if (it != s1.top())
		{
			return false;
		}
		s1.pop();
	}
	return true;
}