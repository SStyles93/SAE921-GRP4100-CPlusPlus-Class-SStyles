#include "Collection.h"

int Object::GetValue() 
{
	return this->m_value;
}
void Object::SetValue(int value) 
{
	m_value = value;
}
void Object::DeleteValue() 
{
	m_value = NULL;
}
void Collection::PopulateCollection(Object object) 
{
	m_collection.push_back(object);
}
void Collection::PrintCollection() 
{
	for (size_t i = 0; i < m_collection.size(); i++)
	{
		std::cout << m_collection[i].GetValue() << std::endl;
	}
	std::cout << " - " << std::endl;
}
void Collection::DeleteMultiplesOf(int nb) 
{	
	for (size_t i = 0; i < m_collection.size(); i++)
	{
		if (m_collection[i].GetValue() % nb == 0) 
		{
			m_collection[i].DeleteValue();
		}
	}
}