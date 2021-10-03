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
		chamber[i] = 1;
	}*/
	
}
void ScrollChamber() 
{
	int temp;

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
		if (it == chamber.end() - 1)
		{
			*(chamber.end() - 1) = temp;
		}
		//in anyother case, get the next iterators value 
		//and store it in the current one
		else
		{
			*it = *(it + 1);
		}
	}
}
void SpinCylinder() 
{
	std::cout << "spinned ";
	std::vector<int>::iterator it = chamber.begin();
	
	//number of time the data scrollings happens
	for (size_t i = 0; i < rand(); i++)
	{
		ScrollChamber();
	}
}
bool Trigger() 
{
	std::cout << "Trigger was pulled! \n";
	if (chamber[0] == 1) 
	{
		ScrollChamber();
		return true;
	}
	else
	{
		ScrollChamber();
		return false;
	}
	
}

int main()
{
	int actionIndex;
	char exitChar = 'n';
	bool isDead = false;

	std::cout << "Welcome to the roulette game ! \n";
	std::cout << "Let's play !\n";

	FillChamber();

	do
	{
		std::cout << "It is your turn to play !\n";
		std::cout << "What do you want to do ?\n";
		std::cout << "[0] To spin the chamber | [1] To Trigger \n";
		do
		{
			
			std::cin >> actionIndex;
			switch (actionIndex)
			{
			case 0:
				std::cout << "Your just ";
				SpinCylinder();
				std::cout << "the cylinder \n";
				break;
			case 1:
				isDead = Trigger();
				break;
			default:
				std::cin.ignore();
				break;
			}
			

		} while (actionIndex != 1);

		if (isDead)
		{
			std::cout << "Player shot himself! \n";
			exitChar = 'y';
			return 0;
		}
		else
		{
			std::cout << "Player was lucky! \n";
		}
		std::cout << "It is the computers turn to play\n";
		std::cout << "The computer just ";
		SpinCylinder();
		std::cout << "the cylinder \n";
		isDead = Trigger();
		if (isDead) 
		{
			std::cout << "Computer shot himself! \n ";
			exitChar = 'y';
			return 0;
		}
		else
		{
			std::cout << "Computer was lucky! \n";
		}
	} while (exitChar != 'y');
}

