#include "Card.h"

std::vector<Card> deck(52);




class Card
{
	public:
		Value value;
		Suit suit;
	public:
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
					//Add card to deck
					deckCount++;
				}
			}
		}
		void PrintDeck()
		{
			int deckCount = 0;
			for (size_t suit = 0; suit < 4; ++suit)
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
};

