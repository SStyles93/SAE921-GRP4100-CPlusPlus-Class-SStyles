#pragma once
#include "Tree.h"

class PearTree : public Tree
{
protected:
	//weight in grams
	int m_pearWeight = 90;
public:
	PearTree();
	void GetWeight() override;
	void SetQuantity(time_t time) override;
};

