#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include "Bag.hpp"

#define CAPACITY 8
#define INFORMATION 2

//默认一个清单，使用单例模式
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
	//捡起物品
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

	//初始化物品
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

	//丢弃物品
	void Drop()
	{
		std::string item;//丢什么物品
		int num;//丢弃的数量
		std::cin >> item >> num;
		//判断有没有这个物品
		for (int i = 0; i < CAPACITY; i++)
		{
			if (item == (*dp[i].begin()))
			{
				//判断数量
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
	//删除物品
	void Delete(int i)
	{
		*dp[i].begin() = "";
		*(dp[i].begin() + 1) = "";
		*(dp[i].begin() + 2) = "";
	}
	
	//判断是否有物品
	bool Judge(int i)
	{
		if (dp[i][1] == "")
		{
			return true;
		}
		return false;
	}
	//查看随身物品
	void ShowRucksack()
	{
		if (*dp[0].begin() == "")
		{
			std::cout << "你的随身物品什么也没有！" << std::endl;
			return;
		}
		else
		{
			std::cout << "————————————————" << std::endl;
			for (int i = 0; i < CAPACITY; i++)
			{
				if (dp[i][0] != "")
				{
					std::cout << "|" << (i + 1) << "." << dp[i][0] << " X" << dp[i][1] << " Time: " << dp[i][2] << std::endl;
				}
			}
			std::cout << "————————————————" << std::endl;
		}
	}
	//背包转移到随身
	void BagToRuck()
	{
		std::string s1;
		std::cin >> s1;
		if (bag->InBag(s1))
		{
			bag->UseItem(s1);
			int i = 0;
			//有一样的物品
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
			//有没有空位
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
			//查找最少使用并丢弃
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
	//找到最久没有使用的物品并删除
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
	//查找是否有这个物品
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
	//使用物品
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
					//判断数量
					if (std::stoi(*(dp[i].begin() + 1))>1)
					{
						std::stringstream stream;
						stream << (std::stoi(*(dp[i].begin() + 1)) - 1);
						dp[i].insert(dp[i].begin() + 1, stream.str());

						std::stringstream stream1;
						stream1 << std::stoi(*(dp[i].begin() + 2)) + 1;
						dp[i].insert(dp[i].begin() + 2, stream.str());
						std::cout << "你使用了" << s1 <<"!"<< std::endl;
						return;
					}
					else
					{
						Delete(i);
						std::cout << "你使用了" << s1 << "!"<<std::endl;
						return;
					}
				}
			}
		}
		else
		{
			std::cout << "没有找到这个物品" << std::endl;
		}
	}
	//丢弃ABC
	void DropABC(std::string s1,int num)
	{
		//判断有没有这个物品
		for (int i = 0; i < CAPACITY; i++)
		{
			if (s1 == (*dp[i].begin()))
			{
				//判断数量
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

	//合成道具
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
			std::cout << "缺少足够的材料" << std::endl;
			return;
		}
	}

};

