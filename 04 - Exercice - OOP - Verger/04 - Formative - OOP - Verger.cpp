#include "AppleTree.h"
#include "CherryTree.h"
#include "PearTree.h"

std::vector<Tree*> trees;

int appleTreesNumber = 1;
int cherryTreesNumber = 1;
int pearTreesNumber = 1 ;

int weightToGet = 2000;
int sum;
int numberOfCollections;
bool contractSuccess = true;

void InitTrees()
{
	//Init trees
	for (size_t i = 0; i < trees.size(); i++)
	{
		srand(time(nullptr));
		trees[i]->SetQuantity(rand()*i);
		trees[i]->GetWeight();
		//trees[i]->PrintWeight();
	}
}
void SumTrees()
{
	
	for (size_t i = 0; i < trees.size(); i++)
	{
		sum += trees[i]->GetWeight();
	}
}

int main()
{
	//Create trees and store them in trees
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

		InitTrees();
	do 
	{
		numberOfCollections++;
		//harvest
		for (int i = 0; i < trees.size(); i++)
		{
			weightToGet -= trees[i]->GetWeight();
			sum += trees[i]->GetWeight();
			trees[i]->SetWeight(0);
			std::cout << weightToGet << " | " << sum << " | " << trees[i]->GetWeight() << std::endl;
			//TODO : Weight does not update correctly
		}

		if (weightToGet <= 0)
		{
			contractSuccess = true;
			break;
		}
		else
		{
			contractSuccess = false;
		}


	} while (numberOfCollections != 10);

	if (contractSuccess == true) 
	{
		std::cout << "You have fulfilled your contract! " << std::endl;
	}
	else 
	{
		std::cout << "You have lost your contract...nature wasn't with you !" << std::endl;
	}
}