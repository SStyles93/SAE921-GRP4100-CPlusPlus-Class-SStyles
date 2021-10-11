#include "CherryTree.h"

CherryTree::CherryTree()
{
}
void CherryTree::GetWeight() 
{
	m_fruitsWeight = (m_quantity * m_cherryWeight) / 1000;
};
void CherryTree::SetQuantity(time_t time) 
{
	m_quantity = (time % 60000);
}