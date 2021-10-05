#pragma once
#include "Value.h"
#include "Suit.h"
#include <iostream>
#include <vector>

class Card
{
	public:
		Suit suit;
		Value value;
		std::vector<Card> deck{ 52 };
		std::string GetCard(Value value_, Suit suit_);
		void CreateDeck();
		void PrintDeck();
};


