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
void ConsoleClear()
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

	int randomRange = 7; //Wanted range + 1
	int randomOffset = 2; //Offset of the range

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
			ConsoleClear();
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
		//Exit condition : Player's death
		if (player.health <= 0)
		{
			std::cout << enemy.name << enemy.description << "smashed his opponent and Won!" << std::endl;
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
			ConsoleClear();

			//Action selection
			switch (player.action)
			{
				//Attack
			case 1:
				std::cout << player.name << " attacks " << enemy.name << std::endl;
				enemy.health -= player.attackValue;
				std::cout << enemy.name << " looses " << player.attackValue << " health points" << std::endl;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
				//Defend
			case 2:
				std::cout << player.name << " uses his shield\n" << std::endl;
				player.isDefending = true;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;

				//Heal
			case 3:
				std::cout << player.name << " heals himself" << std::endl;
				player.health += player.healValue;
				//Heals the correct amount of life
				if (player.health >= 100)
				{
					//Set player.healValue to actual value
					player.healValue -= (player.health - 100);
					player.health = 100;
				}
				else
				{
					//Set player.healValue to initial value
					player.healValue = 3;
				}
				std::cout << "and recovers " << player.healValue << " health points" << std::endl;
				isPlayerTurn = false;
				isNpcTurn = true;
				break;
				//Reset for incorrect entry 
			default:
				std::cin.clear();
				std::cin.ignore();
				isPlayerTurn = true;
				continue;
			}

		} while (isPlayerTurn);

		//Exit Condition : Enemy's death
		if (enemy.health <= 0)
		{
			std::cout << player.name << player.description << "survived this epic combat and Won!" << std::endl;
			return EXIT_SUCCESS;
		}

		//Enemy turn
		do
		{
			//Output health and attack
			std::cout << separationLine << std::endl;
			std::cout << "You have " << player.health << " health points" << std::endl;
			std::cout << enemy.name << " has " << enemy.health << " health points" << std::endl;
			std::cout << separationLine << std::endl;
			std::cout << enemy.name << " attacks " << player.name << std::endl;
			//Random seed
			srand(time(0));
			//Get a random attack value in the defined range with the defined offset
			enemy.attackValue = ((rand() % randomRange) + randomOffset);
			//Return damage with a 10% probability of doubling
			int probability = (rand() % 100) < 10;
			if (probability == 1)
			{
				std::cout << enemy.name << " goes berzerk and summones the Waagh (damage doubled)" << std::endl;
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
			std::cout << player.name << " looses " << enemy.attackValue << " health points" << std::endl;
			isNpcTurn = false;
			isPlayerTurn = true;

		} while (isNpcTurn);

	} while (isGame);


	return 0;
}