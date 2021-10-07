#include "SweetPack.h"

SweetPack::SweetPack(SweetType type, int quantity) 
{
	m_type = type;
	m_quantity = quantity;
}
void SweetPack::InitPack(int quantity) 
{
	m_quantity = quantity;
}
void SweetPack::SellSweet(int quantity)
{
	if (m_quantity - quantity < 0) 
	{
		std::cout << "There are not enought sweets" << std::endl;
	}
	else if (quantity < 0) 
	{
		quantity *= -1;
		m_quantity -= quantity;
	}
	else
	{
		m_quantity -= quantity;
	}
}
std::string SweetPack::GetSweetName(SweetType type) 
{
	switch (type)
	{
	case SweetPack::SweetType::Lolipop:
		return "Lolipop";
		break;
	case SweetPack::SweetType::Tagada:
		return "Tagada";
		break;
	case SweetPack::SweetType::Bubblegum:
		return "Bubblegum";
		break;
	default:
		break;
	}
}
void SweetPack::PrintAmount() 
{
	std::cout << "There are [" << m_quantity << "] " << GetSweetName(m_type) << "'s in the Pack\n";
}