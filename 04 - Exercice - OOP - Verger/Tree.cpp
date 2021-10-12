#include "Tree.h"

Tree::Tree()
{
	m_quantity = 0;
	m_fruitsWeight = 0;
};
int Tree::GetWeight()
{
	return m_fruitsWeight = (m_quantity * m_fruitsWeight) / 1000;
}
void Tree::PrintWeight()
{
	std::cout << "There is " << m_fruitsWeight << " kg" << std::endl;
	std::cout << "Q : " << m_quantity << std::endl;
}
int Tree::GetQuantity() 
{
	return m_quantity;
}
void Tree::SetQuantity(time_t time) 
{
	m_quantity = time;
}
