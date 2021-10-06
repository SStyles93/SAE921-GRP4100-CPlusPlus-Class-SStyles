#pragma once
#include <iostream>
#include <vector>


class Object
{
private:
	int m_value;
public:
	int GetValue();
	void SetValue(int value);
};
class Collection 
{
private:
	std::vector<Object> m_collection;
public:
	void PopulateCollection(Object object);
	void PrintCollection();
	int Size();
};