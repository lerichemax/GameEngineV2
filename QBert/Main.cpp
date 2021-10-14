// QBert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameEngine.h"


int main()
{
	GameEngine Engine{"QBert", 900, 600};
	Engine.Run();
}
