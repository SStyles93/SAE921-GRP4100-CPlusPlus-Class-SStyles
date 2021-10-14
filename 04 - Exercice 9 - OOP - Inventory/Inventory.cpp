#include "Inventory.h"

void Inventory::AddItem(Item* item)
{
	items.push_back(item);
}
void Inventory::Use(Item* item)
{
	item->Use();
}
void Inventory::Display()
{
	for (auto i : items)
	{
		i->Use();
	}
}

