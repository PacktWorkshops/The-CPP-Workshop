// IO Exercise.
#include <iostream>
#include <string>

int main() 
{
    std::string firstName;
    std::string lastName;
    int age;
    std::cout << "Please enter your first name(s): ";
    getline(std::cin, firstName);
    std::cout << "Please enter your surname: ";
    getline(std::cin, lastName);
    std::cout << "Please enter your age: ";
    std::cin >> age;
    std::cout << std::endl;
    std::cout << "Welcome " << firstName << " " << lastName << std::endl;
    std::cout << "You are " << age << " years old." << std::endl;
}
