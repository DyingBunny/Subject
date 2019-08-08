#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#define CAPACITY 8
#define INFORMATION 2

//默认一个背包，使用单例模式
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
	//物品放入背包中
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
	//判断背包格子是否有物品
	bool Judge(int i)
	{
		if (package[i][1] == "")
		{
			return true;
		}
		return false;
	}

	//查看背包物品
	void ShowBag()
	{
		if (*package[0].begin() == "")
		{
			std::cout << "你的背包中什么也没有！" << std::endl;
			return;
		}
		else
		{
			std::cout << "————————————————" << std::endl;
			for (int i = 0; i < CAPACITY; i++)
			{
				if (package[i][0] != "")
				{
					std::cout << "|" << (i + 1) << "." << package[i][0] << " X" << package[i][1] << " Time: " << package[i][2] << std::endl;
				}
			}
			std::cout << "————————————————" << std::endl;
		}
	}
	//丢弃物品
	void Drop()
	{
		std::string item;//丢什么物品
		int num;//丢弃的数量
		std::cin >> item >> num;
		//判断有没有这个物品
		for (int i = 0; i < CAPACITY; i++)
		{
			if (item == (*package[i].begin()))
			{
				//判断数量
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
	//删除物品
	void Delete(int i)
	{
		package[i].erase(package[i].begin());
		package[i].erase(package[i].begin() + 1);
		package[i].erase(package[i].begin() + 2);
	}

	//判断背包中有没有这个物品
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
	//转移到随身
	void UseItem(std::string item)
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			if (item == (*package[i].begin()))
			{
				//判断数量
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