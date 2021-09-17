#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
	int balance = 5;
	int bet;
	int dice1, dice2;
	int minScore = 7;
	int currentScore = 7;
	
	std::string playerName = "Human";
	std::string currency = " CHF";
	std::string yesOrNo = "default";

	bool hasBet = false;
	bool isPlaying = false;

	//Greet the player and ask for his name
	std::cout << "Hello " + playerName + " What is your name ?" << std::endl;
	
	//Get player to type his name in, greet correctly and give him his current fortune;
	std::cin >> playerName;
	std::cout << "Hello " + playerName + "!" << std::endl;
	std::cout << "Your current fortune is : " << balance << currency << std::endl;
	
	//Ask player if he wants to play. Exit if not
	do 
	{
		std::cout << "Do you want to play ? [y/n]" << std::endl;
		std::cin >> yesOrNo;

		if (yesOrNo == "n" || yesOrNo == "N")
		{
			std::cout << "Ok, see you another time" << std::endl;
			return EXIT_SUCCESS;
		}

	} while(yesOrNo != "y" && yesOrNo != "Y");

	//Set isPlaying to true and start game loop
	if(yesOrNo == "y" || yesOrNo == "Y")
	{
		
		std::cout << "Lets play then" << std::endl;
		isPlaying = true;
	}

	//Start of game loop
	do 
	{
		std::cout << "How much do you want to bet ?" << std::endl;
		do
		{
			std::cin >> bet;
			if (bet > balance) 
			{
				std::cout << "You do not have that much money " << playerName << std::endl;
				bet = 0;
				std::cout << "How much do you want to bet ?" << std::endl;
			}
			else if ( bet <= balance)
			{
				balance -= bet;
			}
			if (!std::isdigit(bet))
			{
				std::cout << "That is not a number..." << std::endl;
				bet = 0;
				std::cout << "How much do you want to bet ?" << std::endl;
				
			}
		} while (bet <= 0);

		srand(time(0));

		dice1 = 2;//(rand() % 6 + 1);
		dice2 = 5;//(rand() % 6 + 1);

		std::cout << "Your first dice score is : " << dice1 << " Your second dice score is : " << dice2 << std::endl;
		int totalScore = dice1 + dice2;
		std::cout << "So...your total dice score is :" << totalScore << std::endl;

		if (totalScore >= currentScore)
		{
			currentScore = totalScore;
			balance += bet*2;
			bet = 0;
			std::cout << "Congratulations! You have doubled your bet" << std::endl;
			std::cout << "You now have : " << balance << currency << std::endl;
			std::cout << "Do you want to play again ? [y/n]" << std::endl;
			std::cin >> yesOrNo;
			if (yesOrNo == "n" || yesOrNo == "N")
			{
				std::cout << "Ok, see you another time" << std::endl;
				isPlaying = false;
			}

		}
		if(totalScore <= minScore && balance <= 0)
		{
			std::cout << "Sorry " << playerName << ", you are broke..." << std::endl;
			isPlaying = false;
		}

	} while (isPlaying == true);

	
	return EXIT_SUCCESS;
}