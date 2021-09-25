#include <iostream>
#include <string>

//Variables
const int characterCount = 3;
int doubleChecker = 0;

#pragma region Structs

struct Character
{
    std::string name[characterCount] = { "Sarah Shepard", "Phil Spector", "Whifghy", };
    std::string planet[characterCount] = { "Earth", "Mars", "Sector SD / F67" };
    std::string title[characterCount] = { "Captain", "Pilot", "Child" };
    std::string ship[characterCount] = { "the crusader ship", "the H - Hunter n° 3434 - DFG", "the bioship Sxiot" };
    std::string ally[characterCount] = { "General", "Commander", "Mother" };
};
#pragma endregion
#pragma region Methods

std::string Replace(std::string str, const std::string from, const std::string to)
{
    //find(the wanted keyword) if no keyword found return 
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
    return str;
    //if found replace with (to)
    str.replace(start_pos, from.length(), to);
    doubleChecker++;
    return str;
}

std::string ReplaceMessage
(std::string text_, int characterIndex_)
{   
    Character character;
    //Loop until all elements of text_ are found and replaced
    do
    {
        text_ = Replace(text_, "[Name]", character.name[characterIndex_]);
        text_ = Replace(text_, "[Planet]", character.planet[characterIndex_]);
        text_ = Replace(text_, "[Title]", character.title[characterIndex_]);
        text_ = Replace(text_, "[Ship]", character.ship[characterIndex_]);
        text_ = Replace(text_, "[Ally]", character.ally[characterIndex_]);

        doubleChecker--;
    } while (doubleChecker > 0);
    
    //return text after replacement
    return text_;
}

void ConsoleClear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

#pragma endregion

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
    ConsoleClear();
    /*TEXT
    Text has to be entered in "". Add "[Name]", "[Title]", "[Planet]" or "[Ship]"
    to replace the strings by chosen character's ones.
    text = ""; is to empty text if it is too long to fit 
    */
    std::string text = "Hello [Title], The galactical empire has struc once again.\n";
    text += "If we don't do something about it, a war might be declared!\n";
    text += "Go back to [Planet] as quickly as possible. The [Ally] will wait for you there!\n";
    text += "Be as quick as possible. Our entire species is at risk!\n";
    text += "Due to the situation, you migth encounter problems on the road to [Planet]!\n";
    text += "End of transmission...\n\n";
    std::cout << ReplaceMessage(text, idx);

    text = "";
    text += "That was the final transmission from [Planet].";
    text += "[Name] the [Title] had to find a way home as soon as possible.\n";
    text += "[Name] was stuck somewhere in space on [Ship] and would probably\n";
    text += "have to travel for a very long time before even seeing [Planet]. \n";
    std::cout << ReplaceMessage(text, idx);
    text = "";
    text += "But after all that was just the begining of the [Title]'s problems.\n";
    text += "[Name] the [Title] of [Ship] was in the middle of a Civil war  \n";
    std::cout << ReplaceMessage(text, idx);
    

    return EXIT_SUCCESS;
}