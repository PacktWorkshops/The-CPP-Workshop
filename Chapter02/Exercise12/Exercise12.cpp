#include <iostream>
#include <string>

int main()
{
    int multiple = 0;
    int count = 0;
    int numbersPrinted = 0;
    std::string input = "";
    
    std::cout << "Enter the value whose multiples will be printed: ";
    getline(std::cin, input);
    multiple = std::stoi(input);
    
    std::cout << "Enter maximum amount of numbers to print: ";
    getline(std::cin, input);
    count = std::stoi(input);
    for (int i = 1; i <= 100; ++i)
    {
        if (numbersPrinted == count)
        {
            break;
        }
        if (i % multiple != 0)
        {
            continue;
        }
        std::cout << i << "\n";
        ++numbersPrinted;
    }
}
