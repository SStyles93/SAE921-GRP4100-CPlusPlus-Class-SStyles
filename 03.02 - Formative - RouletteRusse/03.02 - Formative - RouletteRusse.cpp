#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> chamber(6);

void FillChamber() 
{
	std::cout << "Bullet has been placed in a random chamber" << std::endl;
	srand(time(NULL));
	chamber[rand() % 6] = 1;
	//Test
	/*for (size_t i = 0; i < chamber.size(); i++)
	{
		chamber[i] = i;
	}
	*/
}
void SpinCylinder() 
{
	std::cout << "Spin !" << std::endl;
	std::vector<int>::iterator it = chamber.begin();
	int temp;
	//number of time the data scrollings happens
	for (size_t i = 0; i < rand(); i++)
	{
		//scrollings data
		for (auto it = chamber.begin(); it != chamber.end(); it++)
		{
			//get the first iterators value and store it in a "temp" variable
			if (it == chamber.begin())
			{
				temp = *it;
			}
			//if the iterators arrives to the last element 
			//of the vector, puts the temp variable in it
			if (it == chamber.end()-1)
			{
				*(chamber.end()-1) = temp;
			}
			//in anyother case, get the next iterators value 
			//and store it in the current one
			else
			{
				*it = *(it + 1);
			}
		}
	}
}
void Trigger() 
{
	if (chamber[0] == 1) 
	{
		std::cout << " got shot !";
	}
	else
	{
		std::cout << " was lucky !";
	}
}

int main()
{
	int actionIndex;
	char exitChar = 'y';

	std::cout << "Welcome to the roulette game ! \n";
	std::cout << "Let's play !\n";

	FillChamber();

	do
	{
		std::cout << "It is your turn to play !\n";
		std::cout << "What do you want to do ?\n";
		do
		{
			std::cin.ignore();
			std::cin >> actionIndex;
			switch (actionIndex)
			{
			case 0:
				SpinCylinder();
				break;
			case 1:
				Trigger();
				break;
			default:
				break;
			}
		} while (actionIndex != 1);
		std::cout << "It is the computers turn to play\n";
		Trigger();
		//Create a player / enemy turn situation
	} while (exitChar != 'y');
}

