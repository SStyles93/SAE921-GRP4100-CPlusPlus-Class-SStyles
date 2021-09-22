#include <iostream>
#include <array>

enum class Value 
{
    ONE,TWO,TREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,AS, DECKSIZE
};
enum class Suit 
{
    HEART,SPADES,CLUBS,DIAMONDS, SUITCOUNT
};

int valueLenght = static_cast<int>(Value::DECKSIZE);
int suitLenght = static_cast<int>(Suit::SUITCOUNT);
int CreateDeck() 
{
	for (int suit = 0; suit < suitLenght; suit++)
	{
		for (int val = 0; val < valueLenght ; val++)
		{
			
		}
	}

}

int main()
{

}