#include "Tree.h"

Tree::Tree() 
{
	m_quantity = 0;
	m_weight = 0;
};
void Tree::InitFruits() 
{
	int totalWeight = (m_weight * m_quantity)/1000;
	std::cout << "There is : " << totalWeight << " kg on the Tree";
}
