#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#define CAPACITY 8
#define INFORMATION 2

//Ĭ��һ��������ʹ�õ���ģʽ
class Bag
{
private:
	Bag()
	{
		package.resize(CAPACITY);
		package[0].resize(INFORMATION);
		package[1].resize(INFORMATION);
		package[2].resize(INFORMATION);
		package[3].resize(INFORMATION);
		package[4].resize(INFORMATION);
		package[5].resize(INFORMATION);
		package[6].resize(INFORMATION);
		package[7].resize(INFORMATION);
	}

	~Bag()
	{
		if (bag == NULL)
		{
			return;
		}
		delete bag;
		bag = NULL;
	}
	static Bag* bag;
	std::vector<std::vector<std::string>> package;
public:

	static Bag* CreateBag()
	{
		if (bag == NULL)
		{
			bag = new Bag();
		}
		return bag;
	}
	//��Ʒ���뱳����
	void AddToBag(std::string s1)
	{
		int i = 0;
		for (i = 0; i < CAPACITY; i++)
		{
			if (s1 == package[i][0])
			{
				std::stringstream stream;
				std::stringstream stream1;
				stream << std::stoi(*(package[i].begin() + 1)) + 1;
				package[i].insert(package[i].begin() + 1, stream.str());
				stream1 << std::stoi(*(package[i].begin() + 2)) + 1;
				package[i].insert(package[i].begin() + 2, stream.str());
				return;
			}
		}
		for (i = 0; i < CAPACITY; i++)
		{
			if (Judge(i))
			{
				package[i].insert(package[i].begin(), s1);
				package[i].insert(package[i].begin() + 1, "1");
				package[i].insert(package[i].begin() + 2, "0");
				return;
			}
		}
	}
	//�жϱ��������Ƿ�����Ʒ
	bool Judge(int i)
	{
		if (package[i][1] == "")
		{
			return true;
		}
		return false;
	}

	//�鿴������Ʒ
	void ShowBag()
	{
		if (*package[0].begin() == "")
		{
			std::cout << "��ı�����ʲôҲû�У�" << std::endl;
			return;
		}
		else
		{
			std::cout << "��������������������������������" << std::endl;
			for (int i = 0; i < CAPACITY; i++)
			{
				if (package[i][0] != "")
				{
					std::cout << "|" << (i + 1) << "." << package[i][0] << " X" << package[i][1] << " Time: " << package[i][2] << std::endl;
				}
			}
			std::cout << "��������������������������������" << std::endl;
		}
	}
	//������Ʒ
	void Drop()
	{
		std::string item;//��ʲô��Ʒ
		int num;//����������
		std::cin >> item >> num;
		//�ж���û�������Ʒ
		for (int i = 0; i < CAPACITY; i++)
		{
			if (item == (*package[i].begin()))
			{
				//�ж�����
				if (std::stoi(*(package[i].begin() + 1))>num)
				{
					std::stringstream stream;
					stream << (std::stoi(*(package[i].begin() + 1)) - num);
					package[i].insert(package[i].begin() + 1, stream.str());

					std::stringstream stream1;
					stream1 << std::stoi(*(package[i].begin() + 2)) + 1;
					package[i].insert(package[i].begin() + 2, stream.str());
					return;
				}
				else
				{
					Delete(i);
					return;
				}
			}
		}
	}
	//ɾ����Ʒ
	void Delete(int i)
	{
		package[i].erase(package[i].begin());
		package[i].erase(package[i].begin() + 1);
		package[i].erase(package[i].begin() + 2);
	}

	//�жϱ�������û�������Ʒ
	bool InBag(std::string s1)
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			if (s1 == (*package[i].begin()))
			{
				return true;
			}
		}
		return false;
	}
	//ת�Ƶ�����
	void UseItem(std::string item)
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			if (item == (*package[i].begin()))
			{
				//�ж�����
				if (std::stoi(*(package[i].begin() + 1))>1)
				{
					std::stringstream stream;
					stream << (std::stoi(*(package[i].begin() + 1)) - 1);
					package[i].insert(package[i].begin() + 1, stream.str());

					std::stringstream stream1;
					stream1 << std::stoi(*(package[i].begin() + 2)) + 1;
					package[i].insert(package[i].begin() + 2, stream.str());
					return;
				}
				else
				{
					Delete(i);
					return;
				}
			}
		}
	}

};