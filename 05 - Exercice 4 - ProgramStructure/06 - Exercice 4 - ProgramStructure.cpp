// 06 - Program structure - Exercice - Function pointer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

int main()
{

    // Some numbers
    const std::vector<int> numbers = { 12,54,42,42,56,78 };

    // Fill the  gaps in the lambda expression, display the value of an integer
    auto display = [](int num) {std::cout << num << std::endl; };

    // Using the capture by reference :
    // Write a lambda expression substracting a parameter to a captured element in it
    int captured = 10;
    auto substract = [&captured](int num) { return num - captured; };

    // Use the lambda into the for loop below
    for (auto number : numbers)
    {
        // Make the substract
    	// Display the result
        display(substract(number));
    }

    
}
