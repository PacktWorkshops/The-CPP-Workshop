// Time of Day Calculator.
#include <iostream>
#include <string>

int main() 
{
    std::cout << "***Time of Day Calculator***\n";
    std::cout << "Enter time in military format. eg. (1800, 1430)\n\n";
    std::cout << "Enter time: ";
    std::string input;
    getline(std::cin, input);
    int time = std::stoi(input);
    
    if (time < 0000 || time > 2400)
    {
        std::cout << "Invalid time.";
        return 0; 
    }
    if (time == 0000)
    {
        std::cout << "It's currently midnight.";
    }
    else if (time == 1200)
    {
        std::cout << "It's currently noon.";
    }
    else if (time >= 0600 && time < 1200)
    {
        std::cout << "It's currently morning.";
    }
    else if (time > 1200 && time <= 1700)
    {
        std::cout << "It's currently afternoon.";
    }
    else if (time > 1700 && time <= 2000)
    {
        std::cout << "It's currently evening.";
    }
    else if (time > 2000 || time < 0600)
    {
        std::cout << "It's currently night.";
    }
}
