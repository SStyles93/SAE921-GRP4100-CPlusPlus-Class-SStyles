// 06 - Program structure - Exercice - Function pointer.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // Some numbers
    const std::vector<int> numbers = { 12,54,42,42,56,78 };

    // Use what you learned fromm previous exercice
    // Use another lambda to substract and display into a for_each algorithm
    int capture = 10;
    // Fill brackets with some code
    std::for_each(numbers.begin(), numbers.end(), [capture](int n)
    {
	    std::cout << n - capture << std::endl;
    });

}
