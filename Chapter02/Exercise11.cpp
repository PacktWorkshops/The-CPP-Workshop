
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

int main()
{
    bool bIsRunning = true;
    std::string input = "";
    int count = 0;
    std::cout << "***Random number generator***\n";
    
    while (bIsRunning)
    {
        std::cout << "Enter amount of numbers to generate, or 0 to exit: ";
        
        // Get count from user.
        getline(std::cin, input); 
        count = std::stoi(input);
        // Check if user wants to quit application.
        if (count == 0)
          {
            break;
          }
        
        // Generate and output random numbers.
        srand((unsigned)time(0));
        for (int i = 0; i < count; ++i)
        {
            std::cout << rand() % 10;  
            if (i == count - 1)
            {
                continue; 
            }
            
            std::cout << ", ";
         }
       std::cout << "\n\n";
    }
}
