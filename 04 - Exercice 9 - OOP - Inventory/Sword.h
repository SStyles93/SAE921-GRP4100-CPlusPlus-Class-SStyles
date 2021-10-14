#pragma once
#include "Weapon.h"
class Sword : public Weapon
{
public:
	void Equip(Weapon& weapon) override;
	void Use() override;
};

