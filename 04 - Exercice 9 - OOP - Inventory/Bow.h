#pragma once
#include "Weapon.h"
class Bow : public Weapon
{
public:
	void Equip(Weapon& weapon) override;
	void Use() override;
};

