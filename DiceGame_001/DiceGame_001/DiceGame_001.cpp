#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
	int balance = 5;
	int dice1, dice2;
	int minScore = 7;
	int currentScore = 7;
	
	std::string playerName = "Human";
	std::string currency = " CHF";
	std::string yesOrNo = "default";
	
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
		srand(time(0));

		dice1 = (rand() % 6 + 1);
		dice2 = (rand() % 6 + 1);

		std::cout << "Your first dice score is : " << dice1 << " Your second dice score is : " << dice2 << std::endl;
		int totalScore = dice1 + dice2;
		std::cout << "So...your total dice score is :" << totalScore << std::endl;

		if (totalScore > currentScore)
		{
			currentScore = totalScore;
			balance *= 2;
			std::cout << "Congratulations! You have doubled your fortune" << std::endl;
			std::cout << "You now have : " << balance << currency << std::endl;
		}
		if(totalScore <= minScore)
		{
			std::cout << "Sorry my friend, you are broke..." << std::endl;
			return EXIT_SUCCESS;
		}

		//TODO: Continue game logic for Wining cases

		/*std::cout << "isPlaying" << std::endl;
		is playing has to be conditionnaly set*/
		isPlaying = false;
	} while (isPlaying == true);

	
	return EXIT_SUCCESS;
}