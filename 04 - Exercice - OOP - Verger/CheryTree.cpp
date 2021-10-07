#include "CheryTree.h"

CherryTree::CherryTree(int quantity)
{
	m_fruitsWeight = (quantity * m_cherryWeight) / 1000;
}
void CherryTree::InitFruits() {};