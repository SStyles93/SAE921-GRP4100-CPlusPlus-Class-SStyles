#include "SweetPack.h"

SweetPack::SweetPack(SweetType type) 
{
	m_type = type;
	m_quantity = 0;
}
void SweetPack::InitPack(int quantity) 
{
	m_quantity = quantity;
}
void SweetPack::SellSweet(int quantity)
{
	if (m_quantity - quantity >= 0) 
	{
		m_quantity - quantity;
		std::cout << "There are [" << m_quantity << "]" << "s in the Pack\n";
	}
	else
	{
		std::cout << "There are not enought sweets" << std::endl;
	}
}