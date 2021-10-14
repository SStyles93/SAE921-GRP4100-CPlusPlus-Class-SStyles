#include "PearTree.h"

PearTree::PearTree() 
{
}

int PearTree::GetWeight()
{
	return m_fruitsWeight = (m_quantity * m_pearWeight) / 1000;
}

void PearTree::SetQuantity(time_t time)
{
	m_quantity = static_cast<int>(250 + time % 100);
}
