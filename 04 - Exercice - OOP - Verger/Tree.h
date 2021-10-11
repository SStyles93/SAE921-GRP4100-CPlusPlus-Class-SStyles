#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

class Tree
{
protected:
	int m_quantity = 0;
	int m_fruitsWeight = 0;
public:
	Tree();
	virtual void GetWeight(); //in kilos
	void PrintWeight();
	int GetQuantity();
	virtual void SetQuantity(time_t time);
};

