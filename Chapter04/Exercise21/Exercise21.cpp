// Exercise 21: Prime number checker.
#include <iostream>
#include <string>

int main()
{
    int numberToCheck = 0; 
    std::cout << "Prime number checker\n";
    std::cout << "Enter the number you want to check: ";
    std::cin >> numberToCheck;
    
    if (numberToCheck <= 1)
    {
        std::cout << numberToCheck << " is not prime.";
        return 0;
    }
    else if (numberToCheck == 2)
    {
        std::cout << numberToCheck << " is prime.";
        return 0;
    }
    
    for (int i = 2; i < numberToCheck; ++i)
    {
        if (numberToCheck % i == 0)
        {
            std::cout << numberToCheck << " is not prime.";
            return 0;
        }
     }
    std::cout << numberToCheck << " is prime.";
}
