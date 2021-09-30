#include <iostream>
#include <iostream>
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

		std::cout << "Do you want to continue adding people to the list ? [n] to exit";
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
void FindUser() 
{

}
int main()
{
	AskForKeyValuePair();
}
