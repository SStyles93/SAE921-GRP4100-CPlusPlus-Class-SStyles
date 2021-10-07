#pragma once
#include "Tree.h"

class AppleTree : public Tree
{
protected:
	//weight is in grams
	int m_appleWeight = 150;
public:
	AppleTree(int quantity);
	void InitFruits() override;
};

