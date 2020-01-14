// Logical Operators Exercise.
#include <iostream>
#include <string>

int main()
{
    std::string name1;
    std::string name2;
    std::string name3;
    
    std::cout << "Please enter name 1: ";
    std::cin >> name1;
    
    std::cout << "Please enter name 2: "; 
    std::cin >> name2;
    
    std::cout << "Please enter name 3: ";
    std::cin >> name3;
    
    // Check if all or any of the names match.
    if (name1 == name2 && name2 == name3)
    {
        std::cout << "\nAll the names are the same.";
    }
    else if (name1 == name2 || name2 == name3 || name1 == name3)
    {
        std::cout << "\nSome of the names matched.";
    }
    
    // Check if names 1 and 2 are different.
    std::cout << "\nNames 1 and 2 are " << (!(name1 == name2) ? "different." : "the same.") << std::endl;
}
