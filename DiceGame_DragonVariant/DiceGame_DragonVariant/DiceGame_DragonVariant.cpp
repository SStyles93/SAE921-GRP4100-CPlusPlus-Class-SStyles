#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


//Classes
class Player 
{
public:
	std::string name = "Theobald";
	std::string description = "The Noble Knight";

	int health = 100;
	int attackValue = 5;
	int healValue = 3;
	int action = 0;

	bool isDefending = false;
		
};
class Npc
{
public:
	std::string name = "Grimgor";
	std::string description = "The Black Orc";
	int health = 100;
	int attackValue = 2;
};
//Methods
void Clear()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

//Main program
int main()
{
	//Game Variables
	Player theo;
	Npc grim;
	std::string separationLine = "____________________________________________\n";
	std::string yesOrNo = "default";
	bool isGame = false;
	bool isPlayerTurn = false;
	bool isNpcTurn = false;

	//Greet player and ask if he wants to play
	std::cout << "Welcome to the DragonVariant of the DiceGame" << std::endl;
	std::cout << separationLine << std::endl;
	std::cout << "Your are " << theo.name << " \"" << theo.description << "\"" << std::endl;
	std::cout << "You currently have " << theo.health << " health points" << std::endl;
	std::cout << "Your opponent is " << grim.name << " \"" << grim.description << "\"" << std::endl;
	std::cout << grim.name << " has " << grim.health << " health points" << std::endl;
	std::cout << separationLine << std::endl;

	//Get player input. Exit or Play and Re-ask if input is not correct
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
		//Play
		else if (yesOrNo == "y" || yesOrNo == "Y")
		{	
			////UNCOMMENT CLEAR() WHEN GAME FINISHED
			//Clear();
			isGame = true;
		}
		//Keep asking until we get a correct answer
		else
		{
			continue;
		}
	} while (yesOrNo != "y" && yesOrNo != "Y");

	//Start Game Loop
	do 
	{
		//Exit conditions
		if (theo.health <= 0)
		{
			std::cout << theo.name << " Won!" << std::endl;
			return EXIT_SUCCESS;
		}
		if (grim.health <= 0)
		{
			std::cout << grim.name << "Won!" << std::endl;
			return EXIT_SUCCESS;
		}
		//Player turn
		do
		{
			//UNCOMMENT CLEAR() AFTER TEST
			Clear();
			std::cout << separationLine << std::endl;
			std::cout << "You currently have " << theo.health << " health points" << std::endl;
			std::cout << grim.name << " has " << grim.health << " health points" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << "It is your turn to play!" << std::endl;
			std::cout << "enter[1] to Attack" << std::endl;
			std::cout << "enter [2] to Defend yourself" << std::endl;
			std::cout << "enter [3] to Heal yourself" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << "Select your action" << std::endl;
			std::cin >> theo.action;
			
			switch (theo.action)
			{
			case 1:
				std::cout << theo.name << " attacks " << grim.name << std::endl;
				grim.health -= theo.attackValue;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
			case 2:
				std::cout << theo.name << " uses his shield" << std::endl;
				theo.isDefending = true;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
			case 3:
				theo.health += theo.healValue;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
			default:
				std::cin.clear();
				std::cin.ignore();
				isPlayerTurn = true;
				continue;
			}
		} while (isPlayerTurn);

		//NPC turn
		do
		{
			//UNCOMMENT CLEAR() AFTER TEST
			Clear();
			std::cout << separationLine << std::endl;
			std::cout << "You currently have " << theo.health << " health points" << std::endl;
			std::cout << grim.name << " has " << grim.health << " health points" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << grim.name << " attacks " << theo.name << std::endl;
			//Random seed
			srand(time(0));
			//Get a random attack value between 2 and 8
			grim.attackValue = ((rand() % 8) + 2);
			//Return damage with a 10% probability of doubling
			int probability = (rand() % 100) < 10;
			if (probability == 1)
			{
				std::cout << grim.name << " summoned the Waagh" << std::endl;
				grim.attackValue *= 2;
				theo.health -= grim.attackValue;
			}
			else
			{
				theo.health -= grim.attackValue;
			}
			std::cout << grim.attackValue << std::endl;
			isNpcTurn = false;
			isPlayerTurn = true;

		} while (isNpcTurn);

	} while (isGame);
	

	return 0;
}