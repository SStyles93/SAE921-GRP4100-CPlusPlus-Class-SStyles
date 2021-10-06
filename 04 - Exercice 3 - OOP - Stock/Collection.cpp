#include "Collection.h"

int Object::GetValue() 
{
	return this->m_value;
}
void Object::SetValue(int value) 
{
	m_value = value;
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
}
int Collection::GetSize() 
{	
	int collectionSize;
	for (size_t i = 0; i < m_collection.size(); i++)
	{
		collectionSize++;
	}

}