#include "Inventory.h"
#include "Item.h"
#include "Map.h"
#include "Bow.h"
#include "Sword.h"
#include "HealthPotion.h"
#include "ForcePotion.h"


int main()
{
	//Instantiate elements
	Inventory inventory;
	Map map;
	Sword sword;
	Bow bow;
	HealthPotion healthPotion;
	ForcePotion forcePotion;
	//Add elements to inventory
	inventory.AddItem(&map);
	inventory.AddItem(&sword);
	inventory.AddItem(&bow);
	inventory.AddItem(&healthPotion);
	inventory.AddItem(&forcePotion);
	//Display all elements in inventory
	inventory.Display();
}