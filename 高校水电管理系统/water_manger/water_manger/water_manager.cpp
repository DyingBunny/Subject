#include<iostream>
#include<fstream> 
#include<string> 
const int MAX = 10;
using namespace std;
class users
{
public:
	string num;
	string name;
	string sex;
	int age;
	users(string name1="", string sex1="", int age1=0, string num1="")//构造函数
	{
		name = name1;
		sex = sex1;
		age = age1;
		num = num1;

	}
	void input()
	{
		cout << "请输入姓名，性别，年龄，学/工号" << endl;
		cout << "-------------------------------" << endl;
		cin >> name;
		cin >> sex;
		cin >> age;
		cin >> num;

	}
	void output()
	{
		cout << "姓名：" << name << " ";
		cout << "性别：" << sex << " ";
		cout << "年龄：" << age << " ";
		cout << "学/工号" << num << endl;

	}
};
class student :virtual public users
{
public:
	string major;
	string build;
	double water;
	double power;
	double watermoney;
	double powermoney;
	student(string name1="", string sex1="", int age1=0, string num1="", string major1="", string build1="", double water1=0.0, double power1=0.0) :users(name1, sex1, age1, num1)
	{
		major = major1;
		build = build1;
		water = water1;
		power = power1;
	}

	void input()
	{
		cout << "------------------------------------" << endl;
		cout << "请输入本月用水量，用电量，学生专业，宿舍楼号" << endl;
		cout << "------------------------------------" << endl;
		cin >> water;
		cin >> power;
		cin >> major;
		cin >> build;
	}
	void output()
	{
		cout << "用水量：" << water << "吨" << " ";
		cout << "用电量：" << power << "度" << endl;
		cout << "学生专业：" << major << " ";
		cout << "宿舍楼号：" << build << " ";
		if (water<5)
		{
			watermoney = 0;
			cout << "学生水费：0元";
		}
		else
		{
			watermoney = (water - 5) * 2;
			cout << "学生水费：" << (water - 5) * 2 << "元" << " ";
		}
		if (power<20)
		{
			powermoney = 0;
			cout << "学生电费：0元" << endl;
		}
		else
		{
			powermoney = (power - 20)*0.5;
			cout << "学生电费：" << (power - 20)*0.5 << "元" << endl;
		}
	}
};
class teacher :virtual public users
{
public:
	string department;
	double watermoney;
	double powermoney;
	double water;
	double power;
	teacher(string name1="", string sex1="", int age1=0, string num1="", string department1="", double water1=0.0, double power1=0.0) :users(name1, sex1, age1, num1)
	{
		water = water1;
		power = power1;
		department = department1;
	}
	void input()
	{
		cout << "--------------------------------" << endl;
		cout << "请输入本月用水量，用电量，教师公寓号" << endl;
		cout << "--------------------------------" << endl;
		cin >> water;
		cin >> power;
		cin >> department;
	}
	void output()
	{
		watermoney = water*1.5;
		powermoney = power*0.4;
		cout << "用水量：" << water << "吨" << " ";
		cout << "用电量：" << power << "度" << endl;
		cout << "教师公寓：" << department << endl;
		cout << "教师水费：" << water*1.5 << "元" << " ";
		cout << "教师电费：" << power*0.4 << "元" << endl;

	}
};

class Stu_Manage
{
	student Stu[MAX];
	int top;
public:
	Stu_Manage()
	{
		top = 0;
	}
	void add();
	void show();
	void search();
	void total();
	void save();
	void read();
};
void Stu_Manage::add()
{
	if (top >= MAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	student s("王德发", "男", 25, "18060101118", "计算机", "09", 0, 0);
	cout << "输入新添加的人员信息" << endl;
	s.input();
	Stu[top] = s;
	top = top + 1;
	cout << "添加成功" << endl;
}
void Stu_Manage::show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	for (int i = 0; i<top; i++)
		Stu[i].output();
}
void Stu_Manage::search()
{
	if (top == 0)
	{
		cout << "当前存储系统中没有该用户信息" << endl;
		return;
	}
	int choice;
	cout << "请选择查询方式：1：按学/工号查询 2：按用水量查询 3：按用电量查询" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入需要查找的姓名" << endl;
		string num;
		cin >> num;
		for (int i = 0; i<top; i++)
		{
			if (Stu[i].num == num)
			{
				Stu[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	case 2:
	{
		cout << "请输入需要查找的用水量:" << endl;
		double water;
		cin >> water;
		for (int i = 0; i<top; i++)
		{
			if (Stu[i].water == water)
			{
				Stu[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	case 3:
	{
		cout << "请输入需要查找的用电量:" << endl;
		double power;
		cin >> power;
		for (int i = 0; i<top; i++)
		{
			if (Stu[i].power == power)
			{
				Stu[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项，请输入正确选项" << endl;
		break;
	}
}
void Stu_Manage::total()
{
	cout << "1 学生所用水电量总量 2 学生总水电费" << endl;
	int choice;
	cout << "请输入选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		double allwater = 0.0, allpower = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwater += Stu[i].water;
			allpower += Stu[i].power;
		}
		cout << "学生总用水量为" << allwater << endl;
		cout << "学生总用电量为" << allpower << endl;
	}break;
	case 2:
	{
		double allwatermoney = 0.0, allpowermoney = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwatermoney += Stu[i].watermoney;
			allpowermoney += Stu[i].powermoney;
		}
		cout << "学生的总水费为：" << allwatermoney << endl;
		cout << "学生的总电费为：" << allpowermoney << endl;
	}break;
	default:cout << "输入错误，请重新输入" << endl; break;
	}
}
void Stu_Manage::save()
{
	ofstream fout("学生.txt", ios::out);
	if (!fout)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功！" << endl;
	for (int i = 0; i<top; i++)
	{
		fout << Stu[i].name << " "
			<< Stu[i].sex << " "
			<< Stu[i].age << " "
			<< Stu[i].major << " "
			<< Stu[i].build << " "
			<< Stu[i].water << " "
			<< Stu[i].watermoney << " "
			<< Stu[i].power << " "
			<< Stu[i].powermoney << " "
			<< endl;
	}
	cout << "写入成功!" << endl;
	fout.close();
}
void Stu_Manage::read()
{
	ifstream fin("学生.txt", ios::in);
	if (!fin)
	{
		cout << "打开失败！" << endl;
		return;
	}
	int i = 0;
	while (fin >> Stu[i].num >> Stu[i].name
		>> Stu[i].sex
		>> Stu[i].age
		>> Stu[i].major
		>> Stu[i].build
		>> Stu[i].water
		>> Stu[i].watermoney
		>> Stu[i].power
		>> Stu[i].powermoney)
	{
		i++;
		top++;
	}
	cout << "打开成功！" << endl;
	fin.close();
}





class Tea_Manage
{
	teacher Tea[MAX];
	int top;
public:
	Tea_Manage()
	{
		top = 0;
	}
	void add();
	void show();
	void search();
	void total();
	void save();
	void read();
};
void Tea_Manage::show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	for (int i = 0; i<top; i++)
		Tea[i].output();
}
void Tea_Manage::add()
{
	if (top >= MAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	teacher teacher0("王德发", "男", 25, "18060101118", "09", 0, 0);
	cout << "输入新添加的人员信息" << endl;
	teacher0.input();
	for (int i = 0; i<top; i++)
		if (teacher0.num == Tea[i].num)
		{
			cout << "该用户已存在" << endl;
			return;
		}
	Tea[top] = teacher0;
	top = top + 1;
	cout << "添加成功" << endl;
}
void Tea_Manage::search()
{
	if (top == 0)
	{
		cout << "当前存储系统中没有该用户信息" << endl;
		return;
	}
	int choice;
	cout << "请选择查询方式：1：按学/工号查询 2：按用水量查询 3：按用电量查询" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入需要查找的姓名" << endl;
		string num;
		cin >> num;
		for (int i = 0; i<top; i++)
		{
			if (Tea[i].num == num)
			{
				Tea[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	case 2:
	{
		cout << "请输入需要查找的用水量:" << endl;
		double water;
		cin >> water;
		for (int i = 0; i<top; i++)
		{
			if (Tea[i].water == water)
			{
				Tea[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	case 3:
	{
		cout << "请输入需要查找的用电量:" << endl;
		double power;
		cin >> power;
		for (int i = 0; i<top; i++)
		{
			if (Tea[i].power == power)
			{
				Tea[i].output();
			}
		}
		return;
		cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项，请输入正确选项" << endl;
		break;
	}
}
void Tea_Manage::total()
{
	cout << "1 教师所用水电量总量 2 教师总水电费" << endl;
	int choice;
	cout << "请输入选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		double allwater = 0.0, allpower = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwater += Tea[i].water;
			allpower += Tea[i].power;
		}
		cout << "教师总用水量为" << allwater << endl;
		cout << "教师总用电量为" << allpower << endl;
	}break;
	case 2:
	{
		double allwatermoney = 0.0, allpowermoney = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwatermoney += Tea[i].watermoney;
			allpowermoney += Tea[i].powermoney;
		}
		cout << "教师的总水费为：" << allwatermoney << endl;
		cout << "教师的总电费为：" << allpowermoney << endl;
	}break;
	default:cout << "输入错误，请重新输入" << endl; break;
	}
}
void Tea_Manage::save()
{
	ofstream fout("教师.txt", ios::out);
	if (!fout)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功！" << endl;
	for (int i = 0; i<top; i++)
	{
		fout << Tea[i].name << " "
			<< Tea[i].sex << " "
			<< Tea[i].age << " "
			<< Tea[i].department << " "
			<< Tea[i].water << " "
			<< Tea[i].watermoney << " "
			<< Tea[i].power << " "
			<< Tea[i].powermoney << " "
			<< endl;
	}
	cout << "写入成功!" << endl;
	fout.close();
}
void Tea_Manage::read()
{
	ifstream fin("教师.txt", ios::in);
	if (!fin)
	{
		cout << "打开失败！" << endl;
		return;
	}
	int i = 0;
	while (fin >> Tea[i].num >> Tea[i].name
		>> Tea[i].sex
		>> Tea[i].age
		>> Tea[i].department
		>> Tea[i].water
		>> Tea[i].watermoney
		>> Tea[i].power
		>> Tea[i].powermoney)
	{
		i++;
		top++;
	}
	cout << "打开成功！" << endl;
	fin.close();
}
void StuMenu();
void TeaMenu(); 


int main()
{
	int choice = 1;
	do{
		cout << "★~☆·☆。~*∴*~★*∴ *·∴~*★*∴*★~☆·☆" << endl;
		cout << "                高校水电管理系统             " << endl;
		cout << "1 学生水电费管理系统 2教师水电费管理系统 0退出" << endl;
		cout << "                请输入选择:                   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:StuMenu(); break;
		case 2:TeaMenu(); break;
		case 0:cout << "您已退出系统" << endl; break;
		default:cout << "请输入正确选项" << endl; break;
		}
	} while (choice != 0);
	cout << "★~☆·☆。~*∴*~★*∴ *·∴~*★*∴*★~☆·☆" << endl;
	return 0;
}
void StuMenu()
{
	Stu_Manage Stu[MAX];
	int choice = 1;
	while (choice != 0)
	{
		cout << "★~☆·☆。~*∴*~★*∴ *·∴~*★*∴*★~☆·☆" << endl;
		cout << "               学生水电费管理                " << endl;
		cout << "1添加，2显示，3查找，4统计，5保存，6读取，0退出" << endl;
		cout << endl;
		cout << "请输入您的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:Stu[MAX].add(); break;
		case 2:Stu[MAX].show(); break;
		case 3:Stu[MAX].search(); break;
		case 4:Stu[MAX].total(); break;
		case 5:Stu[MAX].save(); break;
		case 6:Stu[MAX].read(); break;
		case 0:cout << "您已退出" << endl; break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
void TeaMenu()
{
	Tea_Manage Tea[MAX];
	int choice = 1;
	while (choice != 0)
	{
		cout << "★~☆·☆。~*∴*~★*∴ *·∴~*★*∴*★~☆·☆" << endl;
		cout << "                教师水电费管理               " << endl;
		cout << "1添加，2显示，3查找，4统计，5保存，6读取，0退出" << endl;
		cout << endl;
		cout << "请输入您的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:Tea[MAX].add(); break;
		case 2:Tea[MAX].show(); break;
		case 3:Tea[MAX].search(); break;
		case 4:Tea[MAX].total(); break;
		case 5:Tea[MAX].save(); break;
		case 6:Tea[MAX].read(); break;
		case 0:	cout << "您已退出" << endl; break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}