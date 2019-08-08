#include<iostream>
#include<string>
#include<cctype>

std::string code_lev(std::string input)
{
	int grade = 0;
	//长度
	grade += (input.size() <= 4) ? 5
		: (input.size() >= 5 && input.size() <= 7) ? 10 : 25;

	//大小写字母
	int eng_cha = 0;
	for (auto const it : input)
	{
		if (std::islower(it))
		{
			eng_cha += 1;
		}
		if (std::isupper(it))
		{
			eng_cha += 1;
		}
	}
	grade += (eng_cha == 0) ? 0
		: (eng_cha == 1) ? 10 : 20;

	//符号个数
	int num_punct = 0;
	for (const auto it : input)
	{
		if (std::ispunct(it))
		{
			num_punct += 1;
		}
	}
	grade += (num_punct == 0) ? 0
		: (num_punct == 1) ? 10 : 25;

	//数字
	int num_num = 0;
	for (const auto it:input)
	{
		if (std::isdigit(it))
		{
			num_num += 1;
		}
	}
	grade += (num_num == 0) ? 0
		: (num_num == 1)?10 : 20;

	//奖励
	if (eng_cha > 1 && num_num > 0&&num_punct>0)
	{
		grade += 5;
	}
	else if (eng_cha > 0 && eng_cha < 2 && num_num > 0 && num_punct > 0)
	{
		grade += 3;
	}
	else if (eng_cha > 0 && eng_cha < 2 && num_num > 0)
	{
		grade += 5;
	}

	return (grade >= 90) ? "VERY_SECURE"
		: (grade >= 80) ? "SECURE"
		: (grade >= 70) ? "VERY_STRONG"
		: (grade >= 60) ? "STRONG"
		: (grade >= 50) ? "AVERAGE"
		: (grade >= 25) ? "WEAK" : "VERY_WEAK";
}

int main()
{
	std::string input;
	std::cin >> input;
	std::string result = code_lev(input);
	std::cout << result << std::endl;
	return 0;
}

