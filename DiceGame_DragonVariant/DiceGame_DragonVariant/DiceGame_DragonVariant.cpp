#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


//Classes
class Player 
{
public:
	std::string name = "Theobald";
	std::string description = " \"The Noble Knight\" ";

	int health = 100;
	int attackValue = 5;
	int healValue = 3;
	int action = 0;

	bool isDefending = false;
		
};
class Enemy
{
public:
	std::string name = "Grimgor";
	std::string description = " \"The Black Orc\" ";

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
	Player player;
	Enemy enemy;
	std::string separationLine = "____________________________________________\n";
	std::string yesOrNo = "default";
	bool isGame = false;
	bool isPlayerTurn = false;
	bool isNpcTurn = false;

	//Greet player and ask if he wants to play
	std::cout << "Welcome to the DragonVariant of the DiceGame" << std::endl;
	std::cout << separationLine << std::endl;
	std::cout << "Your are " << player.name << player.description << std::endl;
	//std::cout << "You currently have " << player.health << " health points" << std::endl;
	std::cout << "Your opponent is " << enemy.name << enemy.description << std::endl;
	//std::cout << enemy.name << " has " << enemy.health << " health points" << std::endl;
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
			Clear();
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
		if (player.health <= 0)
		{
			std::cout << enemy.name << enemy.description << " Won!" << std::endl;
			return EXIT_SUCCESS;
		}
		if (enemy.health <= 0)
		{
			std::cout << player.name << enemy.description << "Won!" << std::endl;
			return EXIT_SUCCESS;
		}
		//Player turn
		do
		{
			//Clear();
			std::cout << separationLine << std::endl;
			std::cout << "You have " << player.health << " health points" << std::endl;
			std::cout << enemy.name << " has " << enemy.health << " health points" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << "It is your turn to play!" << std::endl;
			std::cout << "enter[1] to Attack" << std::endl;
			std::cout << "enter [2] to Defend yourself" << std::endl;
			std::cout << "enter [3] to Heal yourself" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << "Select your action" << std::endl;
			std::cin >> player.action;
			Clear();

			//Action selection
			switch (player.action)
			{
			case 1:
				std::cout << player.name << " attacks " << enemy.name << std::endl;
				enemy.health -= player.attackValue;
				std::cout << enemy.name << " looses " << player.attackValue << " health" << std::endl;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
			case 2:
				std::cout << player.name << " uses his shield" << std::endl;
				player.isDefending = true;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
			case 3:
				std::cout << player.name << " heals up" << std::endl;
				player.health += player.healValue;
				if (player.health >= 100) 
				{
					player.health = 100;
				}
				std::cout << "and recovers " << player.healValue << " health" << std::endl;
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
			//Output health and attack
			//Clear();
			std::cout << separationLine << std::endl;
			std::cout << "You have " << player.health << " health points" << std::endl;
			std::cout << enemy.name << " has " << enemy.health << " health points" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << enemy.name << " attacks " << player.name << std::endl;
			//Random seed
			srand(time(0));
			//Get a random attack value (%7 = [0-6] // + 2 = [2-8]
			enemy.attackValue = ((rand() % 7) + 2);
			//
			std::cout << enemy.attackValue << std::endl;
			//Return damage with a 10% probability of doubling
			int probability = (rand() % 100) < 10;
			if (probability == 1)
			{
				std::cout << enemy.name << " summoned the Waagh" << std::endl;
				enemy.attackValue *= 2;
				if (player.isDefending)
				{
					enemy.attackValue *= 70;
					enemy.attackValue /= 100;
					player.health -= enemy.attackValue;
					player.isDefending = false;
				}
				else
				{

					player.health -= enemy.attackValue;
				}
			}
			else
			{
				if (player.isDefending)
				{
					enemy.attackValue *= 70;
					enemy.attackValue /= 100;
					player.health -= enemy.attackValue; 
					player.isDefending = false;
				}
				else
				{
					player.health -= enemy.attackValue;
				}
			}
			std::cout << player.name << " looses " << enemy.attackValue << " health" << std::endl;
			isNpcTurn = false;
			isPlayerTurn = true;

		} while (isNpcTurn);

	} while (isGame);


	return 0;
}