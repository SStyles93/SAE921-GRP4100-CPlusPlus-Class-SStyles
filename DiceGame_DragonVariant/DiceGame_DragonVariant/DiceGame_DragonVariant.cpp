#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Player 
{
	public:
		std::string name = "Theobald";
		std::string description = "The Noble Knight";
		enum actions{attack, defend, heal};
		int health = 100;
		int attackValue = 5;
		int healValue = 3;

		int Defend(int damage)
		{
			std::cout << name << " uses his shield" << std::endl;
			damage *= 70 / 100;
			return damage;
		}
};
class Npc
{
	public:
		std::string name = "Grimgor";
		std::string description = "The Black Orc";
		int health = 100;
		int attackValue;

		int Attack(int damage)
		{
			//Return damage with a 10% probability of doubling
			srand(time(0));
			int probability = (rand() % 100) < 10;
			if (probability == 1) 
			{
				std::cout << name << " summoned the Waagh" << std::endl;
				damage *= 2;
			}
			else
			{
				return damage;
			}
		}
};

int main()
{
	Player theo;
	Npc grim;
	std::string yesOrNo = "default";
	//Greet player and ask if he wants to play
	std::cout << "Welcome to the DragonVariant of the DiceGame" << std::endl;
	do
	{
		std::cout << "Do you wish to play ? [y/n]" << std::endl;
		std::cin >> yesOrNo;
		//Exit
		if (yesOrNo == "n" || yesOrNo == "N")
		{
			std::cout << "Okay, see you soon" << std::endl;
			return EXIT_SUCCESS;
		}
		//Enter game
		else if (yesOrNo == "y" || yesOrNo == "Y")
		{
			std::cout << "Welcome" << std::endl;
			std::cout << "Your are " << theo.name <<  " \"" << theo.description << "\"" << std::endl;
			std::cout << "You currently have " << theo.health << " health points" << std::endl;
			std::cout << "Your opponent is " << grim.name << " \"" << grim.description << "\"" << std::endl;
			std::cout << grim.name << " has " << grim.health << " health points" << std::endl;
		}
		//Keep asking until we get a correct answer
		else
		{
			continue;
		}
	} while (yesOrNo != "y" && yesOrNo != "Y");
	//Start Game Loop

	return 0;
}