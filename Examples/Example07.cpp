// Break example.
#include <iostream>
#include <string>

int main()
{
    std::cout << "Loop Starting ...\n";
    
    int count = 0;
    
    while (count < 5)
    {
        ++count;
        std::cout << "\n" << count;
    }
    
    std::cout << "\n\nLoop finished.";
}