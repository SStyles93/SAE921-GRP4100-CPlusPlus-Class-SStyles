#include <iostream>
#include <cstdlib>
#include <ctime>

//Array_Ex1 Variables & Functions
int scores[]{ 84, 92, 76, 81, 56 };
int BestScores() 
{
	int bestScore = 0;

	int len = sizeof scores / sizeof scores[0];
	for (size_t i = 0; i < len; i++)
	{
		if (scores[i] > bestScore) 
		{
			bestScore = scores[i];
		}
	}
	return bestScore;
}

int main()
{	
#pragma region ArrayEx1
/*
	//ArrayEx1
    std::cout << BestScores();
*/
#pragma endregion
#pragma region Array2
/*
	//ArrayExercice 2

	unsigned int V;
	do
	{
		std::cout << "Input Value between 0 and 20" << std::endl;
		std::cin >> V;
		
	} while (V > 20);
	
	const int nb = 10;
	int randomArray[nb];

	bool isIn = false;

	srand(time(0));
	std::cout << "{";
	for (size_t i = 0; i < nb; i++)
	{
		randomArray[i] = ((rand() % 20) + 1);
		std::cout << randomArray[i] << ", ";
		if (randomArray[i] == V) 
		{
			isIn = true;
		}
	}
	std::cout << "}";
	if (isIn == true) 
	{
		std::cout << std::endl;
		std::cout << V << " is in the array";
	}
	if (isIn == false) 
	{
		std::cout << std::endl;
		std::cout << V << " is not it the array" << std::endl;
	}
*/
#pragma endregion
#pragma region ArrayEx3
/*
	//ArrayEx_3
	const int numRows = 13;
	const int numCols = 13;
	//Defined Array
	int mulTable[numRows][numCols]{};
	
		for (int row = 1; row < numRows; ++row)
		{
			std::cout << row << " : ";

			for (int col = 1; col < numCols; ++col)
			{
				std::cout << col * row << "|";
			}
			std::cout << std::endl;
		}
*/
#pragma endregion

}

