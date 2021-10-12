#pragma once
#include "Tree.h"

class CherryTree : public Tree
{
protected:
	//weight in grams
	int m_cherryWeight = 5;
public:
	CherryTree();
	int GetWeight() override;
	void SetQuantity(time_t time) override;
};

