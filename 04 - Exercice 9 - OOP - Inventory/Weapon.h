#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	virtual void Equip(Weapon& weapon);
};

