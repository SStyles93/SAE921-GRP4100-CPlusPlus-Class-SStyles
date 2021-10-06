#include "Card.h"

Card card;
std::vector<Card> deck(52);
void CreateDeck()
{
	int deckCount = 0;
	for (int suit{ 0 }; suit < 4; suit++)
	{
		for (int val{ 2 }; val < 14; val++)
		{
			Card myCard;

			myCard.value = static_cast<Value>(val);
			myCard.suit = static_cast<Suit>(suit);
			deck[deckCount] = myCard;
			deckCount++;
		}
	}
}
void DistributeCards(int nbCards_)
{
	srand(time(0));
	for (int i{ 0 }; i < nbCards_; i++)
	{
		std::cout << card.GetCard(deck[(rand() % 52)].value, deck[(rand() % 52)].suit);
	}
}
void PrintDeck()
{
	int deckCount = 0;
	for (size_t suit = 0; suit < 4; ++suit)
	{
		for (size_t val = 2; val < 14; ++val)
		{
			std::cout << card.GetCard(deck[deckCount].value, deck[deckCount].suit);
			deckCount++;
		}
		std::cout << std::endl;
	}
}
int main()
{
	std::vector<Card> deck;
	Card card;

	
	CreateDeck();
	//Print Deck
	PrintDeck();
	//Distribute Cards
	DistributeCards(2);
}