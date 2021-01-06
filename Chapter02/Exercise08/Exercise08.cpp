#include <iostream>
#include <string>

int main() 

{
    bool bIsRunning = true;
    while (bIsRunning) 
    {
        std::string input;
        int number;
        std::cout << "Menu\n";
        std::cout << "1: Fries\n";
        std::cout << "2: Burger\n";
        std::cout << "3: Shake\n";
        std::cout << "Please enter a number 1-3 to view an item price: ";
        getline(std::cin, input);
        number = std::stoi(input);

        switch (number) 
        {
            case 1:
                std::cout << "Fries: $0.99\n";
            break;

            case 2: 
                std::cout << "Burger: $1.25\n";
            break;

            case 3: 
                std::cout << "Shake: $1.50\n";
            break;

            default:
                std::cout << "Invalid choice.";
            break;
        }
    }
}
