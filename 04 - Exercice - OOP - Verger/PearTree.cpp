#include "PearTree.h"

PearTree::PearTree() 
{
}

void PearTree::GetWeight()
{
	m_fruitsWeight = (m_quantity * m_pearWeight) / 1000;
}

void PearTree::SetQuantity(time_t time)
{
	m_quantity = (250 + time % 350);
}
