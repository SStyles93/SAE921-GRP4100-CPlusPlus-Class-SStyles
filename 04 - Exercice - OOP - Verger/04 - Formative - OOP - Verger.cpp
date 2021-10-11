#include "AppleTree.h"
#include "CherryTree.h"
#include "PearTree.h"


int appleTreesNumber = 3;
int cherryTreesNumber = 3;
int pearTreesNumber = 3 ;

std::vector<Tree*> trees;
void SumTrees()
{
	
}

int main()
{
	for (size_t i = 0; i < appleTreesNumber; i++)
	{
		trees.push_back(new AppleTree());
	}
	
	for (size_t i = 0; i < cherryTreesNumber; i++)
	{
		
		trees.push_back(new CherryTree());
	}
	
	for (size_t i = 0; i < pearTreesNumber; i++)
	{
		trees.push_back(new PearTree());
	}
	
	
	
	for (size_t i = 0; i < trees.size(); i++)
	{
		srand(time(NULL));
		trees[i]->SetQuantity(rand() * i);
		trees[i]->GetWeight();
		trees[i]->PrintWeight();
	}


	//Create bool and set to true if 2000kg of fruits was collected
	//Do a loop to collect 10 times
	//stop contract at the end of it if <2000kg was collected during one collection
}