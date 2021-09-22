#include <iostream>
#include <array>
/*
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
int deckSize[suitLenght][valueLenght];
int deck[suitLenght*valueLenght];
int CreateDeck() 
{
	int deckCount = 0;

	for (int suit = 0; suit < suitLenght; suit++)
	{
		for (int val = 0; val < valueLenght ; val++)
		{
			deckCount++;
			deck[deckCount] = suit, val;
		}
	}
	return 0;
}
int GetCard(int cardNumber_)
{
	return deck[cardNumber_];
}

int main()
{
	CreateDeck();
	std::cout << GetCard(1);
}
*/