#include <iostream>
#include <string>
#include <map>

char exitChar;
std::string firstName;
std::string familyName;

std::string concatNames;
std::string phoneNumber;
std::map<std::string, std::string> map;

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

		firstName.clear();
		familyName.clear();
		concatNames.clear();
		phoneNumber.clear();

		std::cout << "Do you want to continue adding people to the list ? [n] to exit\n";
		std::cin >> exitChar;
	}
}
void PrintMap() 
{
	for (auto mapIt = map.begin(); mapIt != map.end(); mapIt++)
	{
		std::cout << mapIt->first << " : " << mapIt->second << std::endl;
	}
}
void FindNumberInMap(std::string name_)
{
	std::map<std::string, std::string>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		if (it->first == name_) 
		{
			std::cout << it->second << std::endl;
		}
		else
		{
			std::cout << "Nothing was found" << std::endl;
		}
	}
}

int main()
{
	
	AskForKeyValuePair();
	PrintMap();

	std::string name = "Default";
	std::cout << "Who's number are you looking for ? \n";
	std::cin.ignore();
	std::getline(std::cin, name);
	

	FindNumberInMap(name);
}
