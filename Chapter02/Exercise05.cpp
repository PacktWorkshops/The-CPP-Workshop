// if/else example 1.
#include <iostream>
#include <string>

int main()
{
    std::string input;
    int number;
    std::cout << "Please enter a number: ";
    getline (std::cin, input);
    number = std::stoi(input);
    if (number < 10)
    {
        std::cout << "The number you entered was less than 10!\n";
    }
    else if (number > 10) 
    {
        std::cout << "The number you entered was greater than 10!\n";
    }
    
    return 0;
}

