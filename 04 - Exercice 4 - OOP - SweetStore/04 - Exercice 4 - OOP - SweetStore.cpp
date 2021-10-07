#include "SweetPack.h"
#include <vector>

int main()
{
	std::vector<SweetPack> store;
	int quantity = 10;
	store.push_back(SweetPack(SweetPack::SweetType::Lolipop, quantity));
	store.push_back(SweetPack(SweetPack::SweetType::Tagada, quantity));
	store.push_back(SweetPack(SweetPack::SweetType::Bubblegum, quantity));

	for (size_t i = 0; i < store.size(); i++)
	{
		store[i].PrintAmount();
	}

	store[static_cast<int>(SweetPack::SweetType::Lolipop)].SellSweet(2);
	store[static_cast<int>(SweetPack::SweetType::Tagada)].SellSweet(-3);
	store[static_cast<int>(SweetPack::SweetType::Bubblegum)].SellSweet(3);

	for (size_t i = 0; i < store.size(); i++)
	{
		store[i].PrintAmount();
	}
}