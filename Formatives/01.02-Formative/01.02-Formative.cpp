#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum class Value
{
	TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
};
enum class Suit
{
    HEARTS,SPADES,CLUBS,DIAMONDS,
};

struct Card 
{
	Value value;
	Suit suit;
};

Card deck[52];

std::string GetCard(Value value_, Suit suit_)
{
	std::string cardValue;
	std::string cardSuit;
	//return the intended value / suit in a concataneted string
	switch (value_)
	{
	case Value::ACE:
		cardValue = "ACE";
		break;
	case Value::TWO:
		cardValue = "TWO";
		break;
	case Value::THREE:
		cardValue = "THREE";
		break;
	case Value::FOUR:
		cardValue = "FOUR";
		break;
	case Value::FIVE:
		cardValue = "FIVE";
		break;
	case Value::SIX:
		cardValue = "SIX";
		break;
	case Value::SEVEN:
		cardValue = "SEVEN";
		break;
	case Value::EIGHT:
		cardValue = "EIGHT";
		break;
	case Value::NINE:
		cardValue = "NINE";
		break;
	case Value::TEN:
		cardValue = "TEN";
		break;
	case Value::JACK:
		cardValue = "JACK";
		break;
	case Value::QUEEN:
		cardValue = "QUEEN";
		break;
	case Value::KING:
		cardValue = "KING";
		break;
	default:
		cardValue = "DEFAULT";
		break;
	}
	switch (suit_)
	{
	case Suit::HEARTS:
		cardSuit = "HEARTS";
		break;
	case Suit::SPADES:
		cardSuit = "SPADES";
		break;
	case Suit::CLUBS:
		cardSuit = "CLUBS";
		break;
	case Suit::DIAMONDS:
		cardSuit = "DIAMONDS";
		break;
	default:
		cardSuit = "DEFAULT";
		break;
	}

	return cardValue + " OF " + cardSuit + "\n";
}

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
void PrintDeck() 
{
	int deckCount = 0;
	for (size_t suit = 0; suit < 4 ; ++suit)
	{
		for (size_t val = 2; val < 14; ++val)
		{
			//std::cout << deck2D[suit][val];
			std::cout << GetCard(deck[deckCount].value, deck[deckCount].suit);
			deckCount++;
		}
		std::cout << std::endl;
	}
}
void DistributeCards(int nbCards_) 
{
	srand(time(0));
	for (int i{ 0 }; i < nbCards_; i++)
	{
		std::cout << GetCard(deck[(rand() % 52 )].value, deck[(rand() % 52)].suit);
	}
}
int main()
{
	CreateDeck();
	//Print Deck
	PrintDeck();
	//Distribute Cards
	DistributeCards(5);
	
}