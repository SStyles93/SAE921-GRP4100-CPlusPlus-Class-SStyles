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
	std::cout << "Hello " << playerName << " What is your name ?" << std::endl;
	std::getline(std::cin, playerName);
	std::cout << "Hello " << playerName << "!" << std::endl;
	std::cout << "Your current fortune is : " << balance << currency << std::endl;
	std::cout << "If you choose to play, roll 2 dices and try to get a total higher than 7 to double your bet !" << std::endl;
	
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
			//Re-ask if the bet is higher than balance
			if (bet > balance) 
			{
				std::cout << "You do not have that much money " << playerName << "..." << std::endl;
				bet = 0;
				std::cout << "How much do you want to bet ?" << std::endl;
			}
			else if ( bet <= balance)
			{
				balance -= bet;
			}
			if (!std::cin)
			{	
				//Ignore anything that isn't a number
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Come on " << playerName << "! That is not a number..." << std::endl;
				std::cout << "How much do you want to bet ?" << std::endl;
				continue;
			}
		} while (bet <= 0);

		//Random dice throw
		srand(time(0));
		dice1 = ((rand() % 6) + 1);
		dice2 = ((rand() % 6) + 1);
		//Result
		std::cout << "Your first dice score is : " << dice1 << " Your second dice score is : " << dice2 << std::endl;
		int totalScore = dice1 + dice2;
		std::cout << "So...your total dice score is : " << totalScore << std::endl;
		
		//If player loses
		if (totalScore <= minScore)
		{
			std::cout << "Sorry " << playerName << " you lost " << bet << " CHF" << std::endl;
			std::cout << "You now have : " << balance << currency << std::endl;
			//Exit if no money left
			if (balance <= 0)
			{
				std::cout << "Sorry " << playerName << ", you are broke..." << std::endl;
				isPlaying = false;
				break;
			}
			//Ask to play again if money left
			std::cout << "Do you want to play again ? [y/n]" << std::endl;
			std::cin >> yesOrNo;
			if (yesOrNo == "n" || yesOrNo == "N")
			{
				std::cout << "Ok, see you another time" << std::endl;
				isPlaying = false;
			}
		}

		//if player wins
		if (totalScore > currentScore)
		{
			currentScore = totalScore;
			minScore = totalScore;
			balance += bet*2;
			bet = 0;
			std::cout << "Congratulations! You have doubled your bet" << std::endl;
			std::cout << "You now have : " << balance << currency << std::endl;
			std::cout << "The new score to beat is now : " << currentScore << std::endl;
			std::cout << "Do you want to play again ? [y/n]" << std::endl;
			std::cin >> yesOrNo;
			if (yesOrNo == "n" || yesOrNo == "N")
			{
				std::cout << "Ok, see you another time" << std::endl;
				isPlaying = false;
			}

		}
		
	} while (isPlaying == true);

	
	return EXIT_SUCCESS;
}