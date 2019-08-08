#pragma once
#include<iostream>
#include<vector>
#include "Carry.hpp"
#include "Bag.hpp"
//����ʹ�õ���ģʽ
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
	//��ʼ�˵�
	 void ShowMenu()
	{
		std::cout << "   GAME MENU   " << std::endl;
		std::cout << " ��������������" << std::endl;
		std::cout << "|1.������Ʒ    |" << std::endl;
		std::cout << "|2.�鿴������Ʒ|" << std::endl;
		std::cout << "|3.�鿴����    |" << std::endl;
		std::cout << "|0.������Ϸ    |" << std::endl;
		std::cout << " ��������������" << std::endl;
	}

	 //�����˵�
	 void MenuOfBag()
	 {
		 std::cout << "   Bag MENU   " << std::endl;
		 std::cout << " ��������������" << std::endl;
		 std::cout << "|1.ʹ����Ʒ    |" << std::endl;
		 std::cout << "|2.������Ʒ    |" << std::endl;
		 std::cout << "|0.�رձ���    |" << std::endl;
		 std::cout << " ��������������" << std::endl;
	 }

	 void MenuOfRuck()
	 {
		 std::cout << "   Ruck MENU   " << std::endl;
		 std::cout << " ��������������" << std::endl;
		 std::cout << "|1.ʹ����Ʒ    |" << std::endl;
		 std::cout << "|2.������Ʒ    |" << std::endl;
		 std::cout << "|3.�ϳɵ���    |" << std::endl;
		 std::cout << "|0.�ر��嵥    |" << std::endl;
		 std::cout << " ��������������" << std::endl;
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

