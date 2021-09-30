#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

std::list<int> numbers;

void PopulateList() 
{
	srand(time(0));
	for (size_t i = 0; i < 12; i++)
	{
		numbers.push_back(1 + rand() % 20);
	}
}

void Display()
{
	for (auto i = numbers.begin(); i != numbers.end(); i++)
	{
		std::cout << *i << " : ";
	}
	std::cout << std::endl;
}
void DeleteEvenNumbers() 
{
	std::list<int>::iterator it = numbers.begin();
	while (it != numbers.end()) 
	{
		if (*it % 2 == 0)
		{
			it = numbers.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void DeleteLastNumbers(int nbToDelete) 
{
	//delete x number from the back of the numbers list	
	std::list<int>::iterator it = numbers.begin();
	std::advance(it, 12 - nbToDelete);
	while (it != numbers.end())
	{
		it = numbers.erase(it);
	}
}

int main()
{
	PopulateList();
	Display();
	DeleteLastNumbers(3);
	Display();
}
