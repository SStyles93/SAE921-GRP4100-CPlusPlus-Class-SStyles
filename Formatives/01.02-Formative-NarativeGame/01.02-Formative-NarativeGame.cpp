#include <iostream>
#include <string>

const int characterCount = 3;
struct Character
{
    std::string name[characterCount] = { "Sarah Shepard", "Phil Spector", "Whifghy", };
    std::string planet[characterCount] = { "Earth", "Mars", "Sector SD / F67" };
    std::string title[characterCount] = { "Captain", "Pilot", "Child" };
    std::string ship[characterCount] = { "the crusader ship", "the H - Hunter n° 3434 - DFG", "the bioship Sxiot" };
};
std::string ReplaceMessage
(std::string text_, std::string name_, std::string planet_, std::string title_, std::string ship_)
{
    text_.replace(text_.find("[Name]"), name_.length(), name_);
    text_.replace(text_.find("[Title]"), title_.length(), title_);
    text_.replace(text_.find("[Planet]"), planet_.length(), planet_);
    text_.replace(text_.find("[Ship]"), ship_.length(), ship_);
    return text_;
}
int main()
{
    Character character;
    int idx;
    bool characterSelected = false;

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
            std::cout << "NO VALUE !" << std::endl;
            break;
        }
        std::cout << character.title[i] << " of " << character.ship[i];
        std::cout << std::endl;
    }
    do{
        //Player Input
        std::cin >> idx;
        //Not a number
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That is not a number...\n" << "Enter a valid index\n";
        }
        //Correct case
        else if (idx < characterCount && idx >= 0)
        {
            characterSelected = true;
        }
        //Incorrect cases
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Out of range...\n" << "Enter a valid index\n";
        }
    } while (characterSelected == false);

    std::cout << "Great, you are now [Name], [Title] of [Ship] \n";
    std::cout << ReplaceMessage("Great, you are now [Name], [Title] of [Ship]", 
        character.name[idx], character.planet[idx], character.title[idx], character.ship[idx]);
    return EXIT_SUCCESS;
}