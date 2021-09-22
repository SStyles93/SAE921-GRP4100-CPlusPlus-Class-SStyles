#include <iostream>

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
    

    std::cout << BestScores();
}
