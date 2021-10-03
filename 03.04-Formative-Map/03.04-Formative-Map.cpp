#include <iostream>
#include <string>
#include <map>

char exitChar;
std::string firstName;
std::string familyName;

std::string concatNames;
std::string phoneNumber;
std::map<std::string, std::string> map;

void ClearValues() 
{
	firstName.clear();
	familyName.clear();
	concatNames.clear();
	phoneNumber.clear();
}

void AskForKeyValuePair() 
{
	while (exitChar != 'n' && exitChar != 'N')
	{
		std::cout << "Enter first name : " << std::endl;
		std::cin >> firstName;
		std::cout << "Enter family name : " << std::endl;
		std::cin >> familyName;
		std::cout << "You have entered first name and family name" << std::endl;
		concatNames = firstName + " " + familyName;
		std::cout << "Enter a phone number : " << std::endl;
		std::cin >> phoneNumber;
		
		map.emplace(concatNames, phoneNumber);

		ClearValues();

		std::cout << "Do you want to continue adding people to the list ? [n] to exit\n";
		std::cin >> exitChar;
	}
}
void PrintMap() 
{
	int mapIndex = 0;
	std::cout << "The map contains : \n";
	for (auto mapIt = map.begin(); mapIt != map.end(); mapIt++)
	{

		std::cout << "[" << mapIndex << "] " << mapIt->first << " : " << mapIt->second << std::endl;
		mapIndex++;
	}
}
void FindNumberInMap()
{
	std::string name = "Default";
	std::cout << "Who's number are you looking for ? \n";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::map<std::string, std::string>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		if (it->first == name) 
		{
			std::cout << it->second << std::endl;
		}
	}
}

int main()
{
	char keepGoing = 'y';
	
	AskForKeyValuePair();
	PrintMap();
	
	do
	{
		FindNumberInMap();
		
		std::cout << "Do you want to find an other number ? [Y] / [N] \n";
		std::cin >> keepGoing;
	
	} while (keepGoing != 'n' && keepGoing != 'N');
}
