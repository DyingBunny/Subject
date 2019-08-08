#include<iostream>
#include "Interface.hpp"
#include "Carry.hpp"
#include "Bag.hpp"
//只允许一个玩家登陆，单例模式
class Game
{
private:
	Game()
	{}

	~Game()
	{
		if (player == NULL)
		{
			return ;
		}
		delete player;
		player = NULL;
	}

	static Game* player;
	Interface* face = Interface::Createface();
	Rucksack * sack = Rucksack::CreateRucksack();
	Bag* bag = Bag::CreateBag();
public:
	static Game* CreatePlayer()
	{
		if (player == NULL)
		{
			player = new Game();
		}
		return player;
	}
	
	void PlayGame()
	{
		sack->InitRucksack("桃木剑");
		sack->InitRucksack("圆盾");
		sack->InitRucksack("生命药剂");
		sack->InitRucksack("A");
		sack->InitRucksack("A");
		sack->InitRucksack("B");
		sack->InitRucksack("C");
		sack->InitRucksack("木头");
		sack->InitRucksack("魔法药剂");
		int input;
		do
		{
			face->ShowMenu();
			std::cin >> input;
			switch (input)
			{
			case 1:
				std::cout << "输入你想捡取的物品:";
				sack->AddToRucksack();		
				break;
			case 2:
				sack->ShowRucksack();
				int input_2;
				do
				{
					face->MenuOfRuck();
					std::cin >> input_2;
					switch (input_2)
					{
					case 1:
						std::cout << "选择你要使用的物品：";
						sack->UseItem();
						break;
					case 2:
						std::cout << "选择你要丢弃的物品和数量:";
						sack->Drop();
						break;
					case 3:
						sack->Synchronise();
						break;
					case 0:
						std::cout << "关闭清单!" << std::endl;
						break;
					default:
						std::cout << "请重新选择：";
						break;
					}
				} while (input_2);
				break;
			case 3:
				bag->ShowBag();
				int input_1;
				do
				{
					face->MenuOfBag();
					std::cin >> input_1;
					switch (input_1)
					{
					case 1:
						std::cout << "选择你要使用的物品：";
						sack->BagToRuck();
						break;
					case 2:
						std::cout << "选择你要丢弃的物品和数量:";
						bag->Drop();
						break;
					case 0:
						std::cout << "关闭背包!" << std::endl;
						break;
					default:
						std::cout << "请重新选择：";
						break;
					}
				} while (input_1);
				break;
			case 0:
				std::cout << "背包游戏结束！" << std::endl;
				break;
			default:
				std::cout << "请重新选择：";
				break;
			}
		} while (input);
	}
};