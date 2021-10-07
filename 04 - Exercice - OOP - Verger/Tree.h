#pragma once
#include <vector>
#include <iostream>

class Tree
{
protected:
	// grams
	int m_weight;
	int m_quantity;
public:
	Tree();
	virtual void InitFruits(); //in kilos
};

