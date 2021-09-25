#include <iostream>
#include <string>

#pragma region Variables

//doubleChecker is used in ReplaceMessage() 
//to check mutiple times the same "[element]"
int doubleChecker = 0;
//Number of characters in the story
const int characterCount = 3;
const int actionCount = 2;


#pragma endregion
#pragma region Structs

struct Character
{
    std::string name[characterCount] = { "Sarah Shepard", "Phil Spector", "Whifghy", };
    std::string planet[characterCount] = { "Earth", "Mars", "the Sector SD / F67" };
    std::string title[characterCount] = { "Captain", "Pilot", "Child" };
    std::string ship[characterCount] = { "the crusader ship", "the H - Hunter n° 3434 - DFG", "the bioship Sxiot" };
    std::string race[characterCount] = { "Human", "Martian", "Bioxis" };
    std::string ally[characterCount] = { "General", "Commander", "Mother" };
    std::string nemesis[characterCount] = { "Martian", "Bioxis", "Human" };
};
struct Decision
{
    std::string action1[actionCount] = { "stay", "leave" };
    std::string adj1[actionCount] = { "best", "worst" };
    std::string adj2[actionCount] = { "Thanks to", "Because of" };
    std::string reaction1[actionCount] =
    {
        "found a source of power ",
        "had no more fuel and was stuck in space alone" 
    };
    std::string finality1[actionCount] = 
    { 
        "could finally start moving to [Planet]", 
        "would probably die there" 
    };

    std::string action2[actionCount] = 
    {
        "fire first and destroy the [Nemesis]'s ship",
        "move slowly, stay calm and hope the [Nemesis]s don't fire" 
    };
    std::string adj3[actionCount] =
    {
        "safe", "under fire"
    };
    std::string finality2[actionCount] =
    {
        "could go back to [Planet] and stop a galactical disaster",
        "ended their life there and were not able to save the galaxy"
    };

};
#pragma endregion
#pragma region Methods

int AskPlayerForInput(int idx_, int maxValue_, bool isSelected_) 
{
    do {
        //Player Input
        std::cin >> idx_;
        //Not a number
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That is not a number...\n" << "Enter a valid index\n";
        }
        //Correct case
        else if (idx_ < maxValue_ && idx_ >= 0)
        {
            isSelected_ = true;
        }
        //Incorrect cases
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Out of range...\n" << "Enter a valid index\n";
        }
    } while (isSelected_ == false);
    return idx_;
}

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
(std::string text_, int characterIndex_,int pathIndex_)
{
    Character character;
    Decision decision;
    //Loop until all elements of text_ are found and replaced
    do
    {
        //Character Replace()
        text_ = Replace(text_, "[Name]", character.name[characterIndex_]);
        text_ = Replace(text_, "[Planet]", character.planet[characterIndex_]);
        text_ = Replace(text_, "[Title]", character.title[characterIndex_]);
        text_ = Replace(text_, "[Ship]", character.ship[characterIndex_]);
        text_ = Replace(text_, "[Race]", character.race[characterIndex_]);
        text_ = Replace(text_, "[Ally]", character.ally[characterIndex_]);
        text_ = Replace(text_, "[Nemesis]", character.nemesis[characterIndex_]);
        //Decision Replace()
        text_ = Replace(text_, "[Action1]", decision.action1[pathIndex_]);
        text_ = Replace(text_, "[Adj1]", decision.adj1[pathIndex_]);
        text_ = Replace(text_, "[Adj2]", decision.adj2[pathIndex_]);
        text_ = Replace(text_, "[Reaction1]", decision.reaction1[pathIndex_]);
        text_ = Replace(text_, "[Finality1]", decision.finality1[pathIndex_]);
        text_ = Replace(text_, "[Action2]", decision.action2[pathIndex_]);
        text_ = Replace(text_, "[Adj3]", decision.adj3[pathIndex_]);
        text_ = Replace(text_, "[Finality2]", decision.finality2[pathIndex_]);

        doubleChecker--;
    } while (doubleChecker > 0);
    //return text after replacement
    return text_;
}

void ClearConsole()
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
{   
    //Struct
    Character character;
    //Variables
    //character selection
    int characterIdx = 0;
    bool characterIsSelected = false;
    //path selection
    int pathIdx = 0;
    bool pathIsSelected = false;

    //Welcoming and character selection
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
    characterIdx = AskPlayerForInput(characterIdx, characterCount, characterIsSelected);
    ClearConsole();

    /*
    ___________________________________________________________________________
                                        
                                        TEXT
    ___________________________________________________________________________
    Text has to be entered in "". Add "[Name]", "[Title]", "[Planet]" or "[Ship]"
    to replace the strings by chosen character's ones.
    text = ""; is to empty text if it is too long to fit 
    ___________________________________________________________________________
    */
    //§1
    std::string text = "Hello [Title], The 9th Galactical Empire has struc once again.\n";
    text += "If we don't do something about it, a war might be declared!\n";
    text += "Go back to [Planet] as quickly as possible. The [Ally] will wait for you there!\n";
    text += "Be as quick as possible. Our entire species is at risk!\n";
    text += "Due to the situation, you migth encounter problems on the road to [Planet]!\n";
    text += "End of transmission...\n\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    
    //§2
    text = "";
    text += "That was the final transmission from [Planet]. ";
    text += "[Name] the [Title] had to find a way home as soon as possible.\n";
    text += "[Name] was stuck somewhere in space on [Ship] and would probably\n";
    text += "have to travel for a very long time before even seeing [Planet]. \n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    
    text = "";
    text += "But after all that was just a minor problem. \n\n";
    //§3
    text += "[Name] the [Title] of [Ship] was in the middle of an unknown territory with \n";
    text += "not much fuel and no way to reach out for help.\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    
    text = "";
    text += "At that moment, [Name] had only two options...\n\n";
    text += "[0] Searching for a source of power in the middle of nowhere.\n";
    text += "                           or                                  ";
    text += "\n[1] Taking the risk of leaving to join the [Ally] on [Planet].\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);

    /*
    ___________________________________________________________________________
    
                                   Path selection
    ___________________________________________________________________________
    */
    pathIdx = AskPlayerForInput(pathIdx, 2, pathIsSelected);
    ClearConsole();

    //§4
    text = "";
    text += "After a moment of reflexion, without being influenced by anything, the [Title] decided to [Action1].\n";
    text += "The fact that [Name] decided to [Action1] was probably the [Adj1] idea.\n";
    text += "[Adj2] that decision the [Title], [Name], [Reaction1]\nand [Finality1].\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    //path 0 == success | path 1 == fail
    if (pathIdx == 1)
        return EXIT_SUCCESS;
    //§5
    text = "\n";
    text += "On the way to [Planet] the [Title] encoutered a [Nemesis] fleet.\n";
    text += "At first sight that may not seem like a problem but the [Nemesis]s\n";
    text += "where actually the Archenemies of the [Race] race.\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    //§6
    text = "\n";
    text += "For a [Race], the [Nemesis]s are considered as the worst creation in the entire universe.\n";
    text += "Since the 3rd Galactical Empire consitution was signed a big part of the [Race]s where\n";
    text += "dispossessed of their land by the [Nemesis]s due to equality reasons...\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    //§7
    text = "\n";
    text += "For that reason, encoutering a [Nemesis] ship was always a very tense moment.\n";
    text += "No one could be blamed if by error, some [Nemesis] ship, opened fire on\n";
    text += "a poor [Race] ship lost somewhere in the middle of nowhere.\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    //§8
    text = "";
    text += "The [Title] of [Ship] had to decide very quickly what to do.\n\n";
    text += "[0] Order to fire first and be sure to not die.\n";
    text += "                      or                       \n";
    text += "[1] Move slowly, stay calm and hope [Nemesis] will not fire either\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    /*
   ___________________________________________________________________________

                                  Path selection 2
   ___________________________________________________________________________
   */
    pathIdx = AskPlayerForInput(pathIdx, 2, pathIsSelected);
    ClearConsole();

    text = "";
    text += "[Name] the [Title] of [Ship] ordered to\n";
    text += "[Action2].\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    //re-use the decision adj and finality by inverting pathIdx
    switch (pathIdx)
    {
    case 0:
        pathIdx = 1;
        break;
    case 1:
        pathIdx = 0;
        break;
    default:
        break;
    }
    text = "";
    text += "[Adj2] that decision, [Name] and [Ship] where [Adj3] and\n";
    text += "[Finality2].\n";
    std::cout << ReplaceMessage(text, characterIdx, pathIdx);
    /*
    ___________________________________________________________________________

                                        END
    ___________________________________________________________________________
    */
    return EXIT_SUCCESS;
}