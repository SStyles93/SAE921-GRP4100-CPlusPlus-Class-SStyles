#include <iostream>
#include <array>

enum class Value 
{
	AS, TWO, TREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING,
	DECKSIZE
};
enum class Suit 
{
    HEART,SPADES,CLUBS,DIAMONDS,
	SUITCOUNT
};

const int suitLenght = static_cast<int>(Suit::SUITCOUNT);
const int valueLenght = static_cast<int>(Value::DECKSIZE);
int deck2D[suitLenght][valueLenght]{};
int deck[suitLenght * valueLenght]{}; 

void CreateDeck() 
{
	int deckCount = 0;

	for (int suit{ 0 }; suit < suitLenght; ++suit)
	{
		for (int val{ 0 }; val < valueLenght; ++val)
		{
			deckCount++;
			deck2D[suit][val] = deckCount;
			deck[deckCount] = deck2D[suit][val];
		}
	}
}
void PrintDeck() 
{
	int _deckCount = 0;
	for (size_t i = 0; i < suitLenght; ++i)
	{
		for (size_t j = 0; j < valueLenght; ++j)
		{
			_deckCount++;
			//std::cout << deck2D[i][j];
			std::cout << deck[_deckCount];
		}
		std::cout << std::endl;
	}
}
int GetCard(int cardNumber_)
{
	//Get the card with %suitLenght or %valueLenght..or smth like that..
	//and loops ?
	return deck[cardNumber_];
}

int main()
{
	CreateDeck();
	//Print Deck
	PrintDeck();
	//Create a function to print out the card
	std::cout << "out the card" << std::endl;
}