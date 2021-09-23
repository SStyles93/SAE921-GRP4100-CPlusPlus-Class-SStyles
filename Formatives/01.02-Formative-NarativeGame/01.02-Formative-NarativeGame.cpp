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

std::string Replace(std::string str, const std::string from, const std::string to)
{
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return str;
    str.replace(start_pos, from.length(), to);
    return str;
    
}

std::string ReplaceMessage
(std::string text_, int characterIndex_)
{
    Character character;
 
    text_ = Replace(text_, "[Name]", character.name[characterIndex_]);
    text_ = Replace(text_, "[Planet]", character.planet[characterIndex_]);
    text_ = Replace(text_, "[Title]", character.title[characterIndex_]);
    text_ = Replace(text_, "[Ship]", character.ship[characterIndex_]);

    return text_;
}
int main()
{   //Variables
    Character character;
    int idx;
    bool characterSelected = false;
    //Welcoming and selection
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
    /*TEXT
    Text has to be entered in "". Add "[Name]", "[Title]", "[Planet]" or "[Ship]"
    to replace the string by chosen character's one.*/
    std::string text = "Hello [Title], The galactical empire has struc once again.\n";
    text += "If we don't do anything, a war might be declared!\n";
    text += "Go back to [Planet] with [Ship]. A galactical embassador will wait for you there!\n";
    text += "Don't worry if he is not there straight away, he will come sooner or later.\n";
    text += "Stay safe [Name], your journey has just started. ";
    text += "Due to the situation,\nyou migth encounter problems on the road to [Planet]\n";
    std::cout << ReplaceMessage(text, idx) << std::endl;
    
    return EXIT_SUCCESS;
}