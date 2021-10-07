#include "AppleTree.h"
#include "CheryTree.h"
#include "PearTree.h"

std::vector<Tree> trees;

int main()
{
	AppleTree appleTree(1000);
	CherryTree cherryTree(1000);
	PearTree pearTree(1000);

	appleTree.PrintWeight();
	cherryTree.PrintWeight();
	pearTree.PrintWeight();
}