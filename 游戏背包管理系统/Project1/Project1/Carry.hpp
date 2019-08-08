#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include "Bag.hpp"

#define CAPACITY 8
#define INFORMATION 2

//Ĭ��һ���嵥��ʹ�õ���ģʽ
class Rucksack
{
private:
	Rucksack()
	{
		dp.resize(CAPACITY);
		dp[0].resize(INFORMATION);
		dp[1].resize(INFORMATION);
		dp[2].resize(INFORMATION);
		dp[3].resize(INFORMATION);
		dp[4].resize(INFORMATION);
		dp[5].resize(INFORMATION);
		dp[6].resize(INFORMATION);
		dp[7].resize(INFORMATION);
	}
	
	~Rucksack()
	{
		if (rucksack == NULL)
		{
			return;
		}
		delete rucksack;
		rucksack = NULL;
	}

	static Rucksack* rucksack;
	Bag* bag = Bag::CreateBag();
	std::vector<std::vector<std::string>> dp;

public:

	static Rucksack* CreateRucksack()
	{
		if (rucksack == NULL)
		{
			rucksack = new Rucksack();
		}
		return rucksack;
	}
	//������Ʒ
	void AddToRucksack()
	{
		std::string s1;
		std::cin >> s1;
		int i = 0;
		for (i = 0; i < CAPACITY; i++)
		{
			if (s1 == dp[i][0])
			{
				std::stringstream stream;
				std::stringstream stream1;
				stream << std::stoi(*(dp[i].begin() + 1)) + 1;
				dp[i].insert(dp[i].begin() + 1, stream.str());
				stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
				dp[i].insert(dp[i].begin() + 2, stream.str());
				return;
			}
		}
		for (i = 0; i < CAPACITY; i++)
		{
			if (Judge(i))
			{
				dp[i].insert(dp[i].begin(), s1);
				dp[i].insert(dp[i].begin()+1, "1");
				dp[i].insert(dp[i].begin()+2, "0");
				return;
			}
		}
		bag->AddToBag(s1);
	}

	//��ʼ����Ʒ
	void InitRucksack(std::string s1)
	{
		int i = 0;
		for (i = 0; i < CAPACITY; i++)
		{
			if (s1 == dp[i][0])
			{
				std::stringstream stream;
				std::stringstream stream1;
				stream << std::stoi(*(dp[i].begin() + 1)) + 1;
				dp[i].insert(dp[i].begin() + 1, stream.str());
				stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
				dp[i].insert(dp[i].begin() + 2, stream.str());
				return;
			}
		}
		for (i = 0; i < CAPACITY; i++)
		{
			if (Judge(i))
			{
				dp[i].insert(dp[i].begin(), s1);
				dp[i].insert(dp[i].begin() + 1, "1");
				dp[i].insert(dp[i].begin() + 2, "0");
				return;
			}
		}
		bag->AddToBag(s1);
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
			if (item == (*dp[i].begin()))
			{
				//�ж�����
				if (std::stoi(*(dp[i].begin() + 1))>num)
				{
					std::stringstream stream;
					stream << (std::stoi(*(dp[i].begin() + 1)) - num);
					dp[i].insert(dp[i].begin() + 1, stream.str());

					std::stringstream stream1;
					stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
					dp[i].insert(dp[i].begin() + 2, stream.str());
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
		*dp[i].begin() = "";
		*(dp[i].begin() + 1) = "";
		*(dp[i].begin() + 2) = "";
	}
	
	//�ж��Ƿ�����Ʒ
	bool Judge(int i)
	{
		if (dp[i][1] == "")
		{
			return true;
		}
		return false;
	}
	//�鿴������Ʒ
	void ShowRucksack()
	{
		if (*dp[0].begin() == "")
		{
			std::cout << "���������ƷʲôҲû�У�" << std::endl;
			return;
		}
		else
		{
			std::cout << "��������������������������������" << std::endl;
			for (int i = 0; i < CAPACITY; i++)
			{
				if (dp[i][0] != "")
				{
					std::cout << "|" << (i + 1) << "." << dp[i][0] << " X" << dp[i][1] << " Time: " << dp[i][2] << std::endl;
				}
			}
			std::cout << "��������������������������������" << std::endl;
		}
	}
	//����ת�Ƶ�����
	void BagToRuck()
	{
		std::string s1;
		std::cin >> s1;
		if (bag->InBag(s1))
		{
			bag->UseItem(s1);
			int i = 0;
			//��һ������Ʒ
			for (i = 0; i < CAPACITY; i++)
			{
				if (s1 == dp[i][0])
				{
					std::stringstream stream;
					std::stringstream stream1;
					stream << std::stoi(*(dp[i].begin() + 1)) + 1;
					dp[i].insert(dp[i].begin() + 1, stream.str());
					stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
					dp[i].insert(dp[i].begin() + 2, stream.str());
					return;
				}
			}
			//��û�п�λ
			for (i = 0; i < CAPACITY; i++)
			{
				if (Judge(i))
				{
					dp[i].insert(dp[i].begin(), s1);
					dp[i].insert(dp[i].begin() + 1, "1");
					dp[i].insert(dp[i].begin() + 2, "0");
					return;
				}
			}
			//��������ʹ�ò�����
			FindMin();
			for (i = 0; i < CAPACITY; i++)
			{
				if (Judge(i))
				{
					dp[i].insert(dp[i].begin(), s1);
					dp[i].insert(dp[i].begin() + 1, "1");
					dp[i].insert(dp[i].begin() + 2, "0");
					return;
				}
			}
		}
		else
		{
			return;
		}
	}
	//�ҵ����û��ʹ�õ���Ʒ��ɾ��
	void FindMin()
	{
		std::vector<int> v1;
		int i = 0;
		for (i = 0; i < CAPACITY; i++)
		{
			v1.push_back(std::stoi(*(dp[i].begin() + 2)));
		}
		int min=*std::min_element(v1.begin(), v1.end());
		for (i = 0; i < CAPACITY; i++)
		{
			if (min == std::stoi(*(dp[i].begin() + 2)))
			{
				Delete(i);
				return;
			}
		}
	}
	//�����Ƿ��������Ʒ
	bool InRuck(std::string s1)
	{
		int i = 0;
		for (i = 0; i < CAPACITY; i++)
		{
			if (s1 == (*dp[i].begin()))
			{
				return true;
			}
		}
		return false;
	}
	//ʹ����Ʒ
	void UseItem()
	{
		std::string s1;
		std::cin >> s1;
		int i = 0;
		if (InRuck(s1))
		{
			for (int i = 0; i < CAPACITY; i++)
			{
				if (s1 == (*dp[i].begin()))
				{
					//�ж�����
					if (std::stoi(*(dp[i].begin() + 1))>1)
					{
						std::stringstream stream;
						stream << (std::stoi(*(dp[i].begin() + 1)) - 1);
						dp[i].insert(dp[i].begin() + 1, stream.str());

						std::stringstream stream1;
						stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
						dp[i].insert(dp[i].begin() + 2, stream.str());
						std::cout << "��ʹ����" << s1 <<"!"<< std::endl;
						return;
					}
					else
					{
						Delete(i);
						std::cout << "��ʹ����" << s1 << "!"<<std::endl;
						return;
					}
				}
			}
		}
		else
		{
			std::cout << "û���ҵ������Ʒ" << std::endl;
		}
	}
	//����ABC
	void DropABC(std::string s1,int num)
	{
		//�ж���û�������Ʒ
		for (int i = 0; i < CAPACITY; i++)
		{
			if (s1 == (*dp[i].begin()))
			{
				//�ж�����
				if (std::stoi(*(dp[i].begin() + 1))>num)
				{
					std::stringstream stream;
					stream << (std::stoi(*(dp[i].begin() + 1)) - num);
					dp[i].insert(dp[i].begin() + 1, stream.str());

					std::stringstream stream1;
					stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
					dp[i].insert(dp[i].begin() + 2, stream.str());
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

	//�ϳɵ���
	void Synchronise()
	{
		if (InRuck("A") && InRuck("B")&&InRuck("C"))
		{
			std::vector<int> v1;
			int i = 0;
			for (i = 0; i < CAPACITY; i++)
			{
				if ((*dp[i].begin()) == "A" || (*dp[i].begin()) == "B" || (*dp[i].begin()) == "C")
				{
					v1.push_back(std::stoi(*(dp[i].begin() + 1)));
				}
			}
			int min = *(std::min_element(v1.begin(), v1.end()));
			DropABC("A", min);
			DropABC("B", min);
			DropABC("C", min);
			while (min)
			{
				std::string s1 = "D";
				InitRucksack(s1);
				min--;
			}
		}
		else
		{
			std::cout << "ȱ���㹻�Ĳ���" << std::endl;
			return;
		}
	}

};

