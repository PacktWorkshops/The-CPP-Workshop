// Activity 4: Fizz Buzz.
#include <iostream>

int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        bool multiple = false;
        if (i % 3 == 0)
        {
            std::cout << "Fizz";
            multiple = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz";
            multiple = true;
        }
        if (!multiple)
        {
            std::cout << i;
        }
        if (i < 100)
        {
            std::cout << ", ";
        }
    }
}
