#include<iostream>
#include "Interface.hpp"
#include "Carry.hpp"
#include "Bag.hpp"
//ֻ����һ����ҵ�½������ģʽ
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
		sack->InitRucksack("��ľ��");
		sack->InitRucksack("Բ��");
		sack->InitRucksack("����ҩ��");
		sack->InitRucksack("A");
		sack->InitRucksack("A");
		sack->InitRucksack("B");
		sack->InitRucksack("C");
		sack->InitRucksack("ľͷ");
		sack->InitRucksack("ħ��ҩ��");
		int input;
		do
		{
			face->ShowMenu();
			std::cin >> input;
			switch (input)
			{
			case 1:
				std::cout << "���������ȡ����Ʒ:";
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
						std::cout << "ѡ����Ҫʹ�õ���Ʒ��";
						sack->UseItem();
						break;
					case 2:
						std::cout << "ѡ����Ҫ��������Ʒ������:";
						sack->Drop();
						break;
					case 3:
						sack->Synchronise();
						break;
					case 0:
						std::cout << "�ر��嵥!" << std::endl;
						break;
					default:
						std::cout << "������ѡ��";
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
						std::cout << "ѡ����Ҫʹ�õ���Ʒ��";
						sack->BagToRuck();
						break;
					case 2:
						std::cout << "ѡ����Ҫ��������Ʒ������:";
						bag->Drop();
						break;
					case 0:
						std::cout << "�رձ���!" << std::endl;
						break;
					default:
						std::cout << "������ѡ��";
						break;
					}
				} while (input_1);
				break;
			case 0:
				std::cout << "������Ϸ������" << std::endl;
				break;
			default:
				std::cout << "������ѡ��";
				break;
			}
		} while (input);
	}
};