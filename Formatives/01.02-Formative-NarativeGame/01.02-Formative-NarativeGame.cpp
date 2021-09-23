#include <iostream>
#include <string>
/*
Sarah Shepard, Born on planet Earth at 24 / 08 / 2087. Captain of the crusader ship The Explorer
Phil spector, Born on planet Mars at 26 / 08 / 2038. Pilot of the H - Hunter n° 3434 - DFG
Whifghy, the metamorph.Created  in Sector SD / F67.Child of the bioship Sxiot
*/
const int characterCount = 3;
struct Character
{
    std::string name[characterCount] = { "Sarah Shepard", "Phil Spector", "Whifghy", };
    std::string planet[characterCount] = { "Earth", "Mars", "Sector SD / F67" };
    std::string title[characterCount] = { "Captain", "Pilot", "Child" };
    std::string ship[characterCount] = { "the crusader ship", "the H - Hunter n° 3434 - DFG", "the bioship Sxiot" };
};

int main()
{
    Character character;

    int idx;

    std::cout << "Welcome to the narative game" << std::endl;
    std::cout << "Select your character: " << std::endl;
    for (int i = 0; i < characterCount; i++)
    {
        std::cout << "[" << i << "]" << character.name[i] << ", ";
        switch (i)
        {
        case 0:
            std::cout << "Born on " << character.planet[i] << " at 24 / 08 / 2087. \n";
            break;
        case 1:
            std::cout << "Born on " << character.planet[i] << " at 26 / 08 / 2038. \n";
            break;
        case 2:
            std::cout << "Created in " << character.planet[i] << ". \n";
            break;
        default:
            std::cout << "NO VALUE *" << std::endl;
            break;
        }
        std::cout << character.title[i] << " of " << character.ship[i];
        std::cout << std::endl;
    }
    do 
    {
        std::cin.clear();
        std::cin.ignore();

        std::cin >> idx;

    } while (idx >= characterCount && idx < 0);

    
}