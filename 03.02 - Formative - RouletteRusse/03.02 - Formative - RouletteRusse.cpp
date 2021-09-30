#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> chamber(6);

void FillChamber() 
{
	std::cout << "Bullet has been placed in a random chamber" << std::endl;
	srand(time(0));
	chamber[rand() % 6] = 1;
	//Test
	/*for (size_t i = 0; i < chamber.size(); i++)
	{
		chamber[i] = i;
	}
	*/
}
void Roulette() 
{
	std::cout << "roulette !" << std::endl;
	std::vector<int>::iterator it = chamber.begin();
	int temp;
	for (size_t i = 0; i < rand(); i++)
	{
		for (auto it = chamber.begin(); it != chamber.end(); it++)
		{
			if (it == chamber.begin())
			{
				temp = *it;
			}
			
			if (it == chamber.end()-1)
			{
				*(chamber.end()-1) = temp;
			}
			else
			{
				*it = *(it + 1);
			}
		}
	}
}
void Shoot() 
{
	if (chamber[0] == 1) 
	{
		std::cout << "Head Shot !";
	}
	else
	{
		std::cout << "Lucky !";
	}
}

int main()
{
	FillChamber();
	Roulette();
	Shoot();
}

