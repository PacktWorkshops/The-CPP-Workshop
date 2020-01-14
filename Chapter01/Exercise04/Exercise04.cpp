// IO Exercise.
#include <iostream>
#include <string>

int Max(int a, int b) 
{
    if (a > b) 
    {
        return a;
    } 
    else 
    {
        return b;
    }
}

int main() 
{
    int value1 = 0;
    int value2 = 0;
    std::cout << "Please input number 1: ";
    std::cin >> value1;
    std::cout << "Please input number 2: ";
    std::cin >> value2;
    std::cout << "The highest number is " << Max(value1, value2);
}
