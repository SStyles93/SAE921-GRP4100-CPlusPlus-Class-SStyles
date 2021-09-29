#include <iostream>
bool test;
bool a = false;
bool b = false;
bool c = false;

void Test(bool test_) 
{
    a = false, b = false;
    std::cout << a << " | " << b;
    std::cout << " =  " << test_ << std::endl;
    a = false, b = true;
    std::cout << a << " | " << b;
    std::cout << " =  " << test_ << std::endl;
    a = true, b = false;
    std::cout << a << " | " << b;
    std::cout << " =  " << test_ << std::endl;
    a = true, b = true;
    std::cout << a << " | " << b;
    std::cout << " =  " << test_ << std::endl;
}
int main()
{

#pragma region Exercice-1.1
    //Exercice-1.1
    //(a&&b)||(!a&&b)
    Test((a && b) || (!a && b));   
    std::cout << std::endl;

#pragma endregion

#pragma region Exercice-1.2-Formative
    //Exercice-1.2-Formative
    //!(a&&!b)||(!a||b)
    Test(!(a && !b) || (!a || b));
    std::cout << std::endl;
#pragma endregion

#pragma region Exercice-1.3-Formative
    //Exercice-1.3-Formative
    //(a&&c)||(!a||b)&&!(c||!b)
    Test((a && c) || (!a || b) && !(c || !b));
    std::cout << std::endl;
#pragma endregion

#pragma region Exercice-2.1
    //Exercice-2.1
    // 0 | 0 = 0
    // 0 | 1 = 1
    // 1 | 0 = 0
    // 1 | 1 = 1

    

#pragma endregion

#pragma region Exercice-2.1-Formative
    //Exercice-2.1-Formative
    // 0 | 0 = 1
    // 0 | 1 = 0
    // 1 | 0 = 1 
    // 1 | 1 = 1 

    //std::cout << test << std::endl;

#pragma endregion

}
