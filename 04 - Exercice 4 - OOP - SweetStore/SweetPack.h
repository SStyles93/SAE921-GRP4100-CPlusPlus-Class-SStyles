#pragma once
#include <iostream>

class SweetPack 
{
private:
	enum class SweetType
	{
		Lolipop, Tagada, Bubblegum
	};
	int m_quantity;
	SweetType m_type;

public:
	//ctor
	SweetPack(SweetType type);
	
	//Methods
	void InitPack(int quantity);
	void SellSweet(int quantity);

};
