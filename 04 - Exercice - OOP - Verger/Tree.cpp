#include "Tree.h"

Tree::Tree()
{
	m_quantity = 0;
};
void Tree::InitFruits() {};
void Tree::PrintWeight()
{
	std::cout << "There is " << m_fruitsWeight << " kg" << std::endl;
}
