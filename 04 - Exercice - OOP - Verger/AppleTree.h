#pragma once
#include "Tree.h"

class AppleTree : public Tree
{
protected:
	//weight is in grams
	int m_appleWeight = 150;
public:
	AppleTree();
	void GetWeight() override;
	void SetQuantity(time_t time) override;
};

