#include <iostream>
#include <string>
//UNCOMMENT REGIONS TO USE THEM
int main()
{
#pragma region StringEx1
/*
    std::string name;
    std::string firstName;
    int age;
    std::cout << "Hello," << std::endl;
    std::cout << "What is your name ?" << std::endl;
    std::cin >> name;
    std::cout << "What is your surname ?" << std::endl;
    std::cin >> firstName;
    std::cout << "What is your age?" << std::endl;
    std::cin >> age;

    std::cout << "Welcome " << firstName << " " << name << std::endl;
    std::cout << "Your are : " << age << " years old." << std::endl;

    */
#pragma endregion

#pragma region StringEx2
/*
    std::cout << "Entre a text line to count vowels in it" << std::endl;
    std::string text;
    std::getline(std::cin, text);

    int vowelCount = 0;

    for(int i = 0; i < text.length(); i++)
    {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'y')
        {
            vowelCount++;
        }
    }

    std::cout << vowelCount;

    */
#pragma endregion


}