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
	m_quantity = (250 + time % 350);
}
