#include "Card.h"

Card card;
std::vector<Card> deck;
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
	std::vector<Card> deck;
	Card card;

	
	card.CreateDeck();
	//Print Deck
	card.PrintDeck();
	//Distribute Cards
	DistributeCards(5);
}