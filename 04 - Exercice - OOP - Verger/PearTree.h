#pragma once
#include "Tree.h"

class PearTree : public Tree
{
protected:
	//weight in grams
	int m_pearWeight = 90;
public:
	PearTree(int quantity);
	void InitFruits() override;
};

