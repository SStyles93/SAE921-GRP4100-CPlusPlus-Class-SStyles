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
		std::string GetCard(Value value_, Suit suit_);
};


