#pragma once
#include <iostream>
#include <vector>

enum class Value
{
	TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
};
enum class Suit
{
	HEARTS, SPADES, CLUBS, DIAMONDS,
};

class Card
{
	public:
		Value value;
		Suit suit;
		std::string GetCard(Value value_, Suit suit_);
		void CreateDeck();
		void PrintDeck();
};


