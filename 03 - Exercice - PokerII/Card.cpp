#include "Card.h"

std::string Card::GetCard(Value value_, Suit suit_)
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
