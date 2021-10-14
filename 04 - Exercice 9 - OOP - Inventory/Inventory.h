#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> items;
public:
	void AddItem(Item* item);
	void Use(Item* item);
	void Display();
};

