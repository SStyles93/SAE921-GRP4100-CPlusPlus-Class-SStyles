#include "Collection.h"
#include <cstdlib>
#include <ctime>

int main()
{
	Collection collection;

	//random seed
	srand(time(0));

	for (size_t i = 0; i < 5; i++)
	{
		Object myObj;
		myObj.SetValue((rand() % 10));
		collection.PopulateCollection(myObj);
	}
	collection.PrintCollection();
	collection.DeleteMultiplesOf(3);
	collection.PrintCollection();
}