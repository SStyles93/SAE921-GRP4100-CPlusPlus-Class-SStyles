#include "AppleTree.h"

AppleTree::AppleTree() 
{
}

int AppleTree::GetWeight()
{
	return m_fruitsWeight = (m_quantity * m_appleWeight) / 1000;
}

void AppleTree::SetQuantity(time_t time)
{
	m_quantity = static_cast<int>(650 + time % 250);
}