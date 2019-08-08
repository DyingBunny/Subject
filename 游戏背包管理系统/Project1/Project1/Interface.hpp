#pragma once
#include<iostream>
#include<vector>
#include "Carry.hpp"
#include "Bag.hpp"
//窗口使用单例模式
class Interface
{
private:
	Interface()
	{}

	~Interface()
	{
		if (face == NULL)
		{
			return;
		}
		delete face;
		face = NULL;
	}

	static Interface *face;
	Rucksack * sack = Rucksack::CreateRucksack();
	Bag* bag = Bag::CreateBag();
public:
	static Interface* Createface()
	{
		if (face == NULL)
		{
			face = new Interface();
		}
		return face;
	}
	//初始菜单
	 void ShowMenu()
	{
		std::cout << "   GAME MENU   " << std::endl;
		std::cout << " ———————" << std::endl;
		std::cout << "|1.捡起物品    |" << std::endl;
		std::cout << "|2.查看随身物品|" << std::endl;
		std::cout << "|3.查看背包    |" << std::endl;
		std::cout << "|0.结束游戏    |" << std::endl;
		std::cout << " ———————" << std::endl;
	}

	 //背包菜单
	 void MenuOfBag()
	 {
		 std::cout << "   Bag MENU   " << std::endl;
		 std::cout << " ———————" << std::endl;
		 std::cout << "|1.使用物品    |" << std::endl;
		 std::cout << "|2.丢弃物品    |" << std::endl;
		 std::cout << "|0.关闭背包    |" << std::endl;
		 std::cout << " ———————" << std::endl;
	 }

	 void MenuOfRuck()
	 {
		 std::cout << "   Ruck MENU   " << std::endl;
		 std::cout << " ———————" << std::endl;
		 std::cout << "|1.使用物品    |" << std::endl;
		 std::cout << "|2.丢弃物品    |" << std::endl;
		 std::cout << "|3.合成道具    |" << std::endl;
		 std::cout << "|0.关闭清单    |" << std::endl;
		 std::cout << " ———————" << std::endl;
	 }

	 void ShowRucksack()
	 {
		 sack->ShowRucksack();
	 }

	 void ShowBag()
	 {
		 bag->ShowBag();
	 }

};

