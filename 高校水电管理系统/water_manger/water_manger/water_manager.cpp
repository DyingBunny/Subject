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
	users(string name1="", string sex1="", int age1=0, string num1="")//���캯��
	{
		name = name1;
		sex = sex1;
		age = age1;
		num = num1;

	}
	void input()
	{
		cout << "�������������Ա����䣬ѧ/����" << endl;
		cout << "-------------------------------" << endl;
		cin >> name;
		cin >> sex;
		cin >> age;
		cin >> num;

	}
	void output()
	{
		cout << "������" << name << " ";
		cout << "�Ա�" << sex << " ";
		cout << "���䣺" << age << " ";
		cout << "ѧ/����" << num << endl;

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
		cout << "�����뱾����ˮ�����õ�����ѧ��רҵ������¥��" << endl;
		cout << "------------------------------------" << endl;
		cin >> water;
		cin >> power;
		cin >> major;
		cin >> build;
	}
	void output()
	{
		cout << "��ˮ����" << water << "��" << " ";
		cout << "�õ�����" << power << "��" << endl;
		cout << "ѧ��רҵ��" << major << " ";
		cout << "����¥�ţ�" << build << " ";
		if (water<5)
		{
			watermoney = 0;
			cout << "ѧ��ˮ�ѣ�0Ԫ";
		}
		else
		{
			watermoney = (water - 5) * 2;
			cout << "ѧ��ˮ�ѣ�" << (water - 5) * 2 << "Ԫ" << " ";
		}
		if (power<20)
		{
			powermoney = 0;
			cout << "ѧ����ѣ�0Ԫ" << endl;
		}
		else
		{
			powermoney = (power - 20)*0.5;
			cout << "ѧ����ѣ�" << (power - 20)*0.5 << "Ԫ" << endl;
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
		cout << "�����뱾����ˮ�����õ�������ʦ��Ԣ��" << endl;
		cout << "--------------------------------" << endl;
		cin >> water;
		cin >> power;
		cin >> department;
	}
	void output()
	{
		watermoney = water*1.5;
		powermoney = power*0.4;
		cout << "��ˮ����" << water << "��" << " ";
		cout << "�õ�����" << power << "��" << endl;
		cout << "��ʦ��Ԣ��" << department << endl;
		cout << "��ʦˮ�ѣ�" << water*1.5 << "Ԫ" << " ";
		cout << "��ʦ��ѣ�" << power*0.4 << "Ԫ" << endl;

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
		cout << "�û�����" << endl;
		return;
	}
	student s("���·�", "��", 25, "18060101118", "�����", "09", 0, 0);
	cout << "��������ӵ���Ա��Ϣ" << endl;
	s.input();
	Stu[top] = s;
	top = top + 1;
	cout << "��ӳɹ�" << endl;
}
void Stu_Manage::show()
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	for (int i = 0; i<top; i++)
		Stu[i].output();
}
void Stu_Manage::search()
{
	if (top == 0)
	{
		cout << "��ǰ�洢ϵͳ��û�и��û���Ϣ" << endl;
		return;
	}
	int choice;
	cout << "��ѡ���ѯ��ʽ��1����ѧ/���Ų�ѯ 2������ˮ����ѯ 3�����õ�����ѯ" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫ���ҵ�����" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	case 2:
	{
		cout << "��������Ҫ���ҵ���ˮ��:" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	case 3:
	{
		cout << "��������Ҫ���ҵ��õ���:" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ���������ȷѡ��" << endl;
		break;
	}
}
void Stu_Manage::total()
{
	cout << "1 ѧ������ˮ�������� 2 ѧ����ˮ���" << endl;
	int choice;
	cout << "������ѡ��" << endl;
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
		cout << "ѧ������ˮ��Ϊ" << allwater << endl;
		cout << "ѧ�����õ���Ϊ" << allpower << endl;
	}break;
	case 2:
	{
		double allwatermoney = 0.0, allpowermoney = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwatermoney += Stu[i].watermoney;
			allpowermoney += Stu[i].powermoney;
		}
		cout << "ѧ������ˮ��Ϊ��" << allwatermoney << endl;
		cout << "ѧ�����ܵ��Ϊ��" << allpowermoney << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void Stu_Manage::save()
{
	ofstream fout("ѧ��.txt", ios::out);
	if (!fout)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ���" << endl;
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
	cout << "д��ɹ�!" << endl;
	fout.close();
}
void Stu_Manage::read()
{
	ifstream fin("ѧ��.txt", ios::in);
	if (!fin)
	{
		cout << "��ʧ�ܣ�" << endl;
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
	cout << "�򿪳ɹ���" << endl;
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
		cout << "������!" << endl;
		return;
	}
	for (int i = 0; i<top; i++)
		Tea[i].output();
}
void Tea_Manage::add()
{
	if (top >= MAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	teacher teacher0("���·�", "��", 25, "18060101118", "09", 0, 0);
	cout << "��������ӵ���Ա��Ϣ" << endl;
	teacher0.input();
	for (int i = 0; i<top; i++)
		if (teacher0.num == Tea[i].num)
		{
			cout << "���û��Ѵ���" << endl;
			return;
		}
	Tea[top] = teacher0;
	top = top + 1;
	cout << "��ӳɹ�" << endl;
}
void Tea_Manage::search()
{
	if (top == 0)
	{
		cout << "��ǰ�洢ϵͳ��û�и��û���Ϣ" << endl;
		return;
	}
	int choice;
	cout << "��ѡ���ѯ��ʽ��1����ѧ/���Ų�ѯ 2������ˮ����ѯ 3�����õ�����ѯ" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫ���ҵ�����" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	case 2:
	{
		cout << "��������Ҫ���ҵ���ˮ��:" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	case 3:
	{
		cout << "��������Ҫ���ҵ��õ���:" << endl;
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
		cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ���������ȷѡ��" << endl;
		break;
	}
}
void Tea_Manage::total()
{
	cout << "1 ��ʦ����ˮ�������� 2 ��ʦ��ˮ���" << endl;
	int choice;
	cout << "������ѡ��" << endl;
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
		cout << "��ʦ����ˮ��Ϊ" << allwater << endl;
		cout << "��ʦ���õ���Ϊ" << allpower << endl;
	}break;
	case 2:
	{
		double allwatermoney = 0.0, allpowermoney = 0.0;
		for (int i = 0; i<top; i++)
		{
			allwatermoney += Tea[i].watermoney;
			allpowermoney += Tea[i].powermoney;
		}
		cout << "��ʦ����ˮ��Ϊ��" << allwatermoney << endl;
		cout << "��ʦ���ܵ��Ϊ��" << allpowermoney << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void Tea_Manage::save()
{
	ofstream fout("��ʦ.txt", ios::out);
	if (!fout)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ���" << endl;
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
	cout << "д��ɹ�!" << endl;
	fout.close();
}
void Tea_Manage::read()
{
	ifstream fin("��ʦ.txt", ios::in);
	if (!fin)
	{
		cout << "��ʧ�ܣ�" << endl;
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
	cout << "�򿪳ɹ���" << endl;
	fin.close();
}
void StuMenu();
void TeaMenu(); 


int main()
{
	int choice = 1;
	do{
		cout << "��~��~*��*~��*�� *����~*��*��*��~���" << endl;
		cout << "                ��Уˮ�����ϵͳ             " << endl;
		cout << "1 ѧ��ˮ��ѹ���ϵͳ 2��ʦˮ��ѹ���ϵͳ 0�˳�" << endl;
		cout << "                ������ѡ��:                   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:StuMenu(); break;
		case 2:TeaMenu(); break;
		case 0:cout << "�����˳�ϵͳ" << endl; break;
		default:cout << "��������ȷѡ��" << endl; break;
		}
	} while (choice != 0);
	cout << "��~��~*��*~��*�� *����~*��*��*��~���" << endl;
	return 0;
}
void StuMenu()
{
	Stu_Manage Stu[MAX];
	int choice = 1;
	while (choice != 0)
	{
		cout << "��~��~*��*~��*�� *����~*��*��*��~���" << endl;
		cout << "               ѧ��ˮ��ѹ���                " << endl;
		cout << "1��ӣ�2��ʾ��3���ң�4ͳ�ƣ�5���棬6��ȡ��0�˳�" << endl;
		cout << endl;
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:Stu[MAX].add(); break;
		case 2:Stu[MAX].show(); break;
		case 3:Stu[MAX].search(); break;
		case 4:Stu[MAX].total(); break;
		case 5:Stu[MAX].save(); break;
		case 6:Stu[MAX].read(); break;
		case 0:cout << "�����˳�" << endl; break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
void TeaMenu()
{
	Tea_Manage Tea[MAX];
	int choice = 1;
	while (choice != 0)
	{
		cout << "��~��~*��*~��*�� *����~*��*��*��~���" << endl;
		cout << "                ��ʦˮ��ѹ���               " << endl;
		cout << "1��ӣ�2��ʾ��3���ң�4ͳ�ƣ�5���棬6��ȡ��0�˳�" << endl;
		cout << endl;
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:Tea[MAX].add(); break;
		case 2:Tea[MAX].show(); break;
		case 3:Tea[MAX].search(); break;
		case 4:Tea[MAX].total(); break;
		case 5:Tea[MAX].save(); break;
		case 6:Tea[MAX].read(); break;
		case 0:	cout << "�����˳�" << endl; break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}