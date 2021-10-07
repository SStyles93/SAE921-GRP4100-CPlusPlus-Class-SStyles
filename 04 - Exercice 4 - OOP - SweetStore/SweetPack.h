#pragma once
#include <iostream>

class SweetPack 
{
private:

public:
	int m_quantity;
	enum class SweetType
	{
		Lolipop, Tagada, Bubblegum
	};
	SweetType m_type;
	//ctor
	SweetPack(SweetType type, int quantity);
	
	//Methods
	void InitPack(int quantity);
	void SellSweet(int quantity);
	std::string GetSweetName(SweetType m_type);
	void PrintAmount();
};
