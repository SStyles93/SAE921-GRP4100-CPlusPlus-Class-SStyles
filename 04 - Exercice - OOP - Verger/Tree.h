#pragma once
#include <vector>
#include <iostream>

class Tree
{
protected:
	int m_quantity = 0;
	int m_fruitsWeight = 0;
public:
	Tree();
	virtual void InitFruits(); //in kilos
	void PrintWeight();
};

