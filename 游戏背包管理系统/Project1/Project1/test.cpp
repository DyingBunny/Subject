#pragma once
#include "Interface.hpp"
#include "game.hpp"
#include "Bag.hpp"
#include <iostream>
#include <windows.h>
#include <thread>


Interface* Interface::face = NULL;
Rucksack* Rucksack::rucksack = NULL;
Game* Game::player=NULL;
Bag* Bag::bag = NULL;


void GameStart()
{
	Game* player = Game::CreatePlayer();
	player->PlayGame();
}

int main()
{
	std::thread task01(GameStart);
	task01.join();
	while (std::cin.get())
	{
		;
	}
	return 0;
}
