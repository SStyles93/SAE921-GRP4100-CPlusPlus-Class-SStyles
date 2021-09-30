#include "Card.h"

Card deck[52];
Card card;

void DistributeCards(int nbCards_)
{
	srand(time(0));
	for (int i{ 0 }; i < nbCards_; i++)
	{
		std::cout << card.GetCard(deck[(rand() % 52)].value, deck[(rand() % 52)].suit);
	}
}



int main()
{
	card.CreateDeck();
	//Print Deck
	card.PrintDeck();
	//Distribute Cards
	DistributeCards(5);
}