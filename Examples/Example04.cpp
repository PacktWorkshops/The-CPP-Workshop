// Input example.
#include <iostream>
#include <string>

int main()
{
  std::string name;
  int age;
  
  std::cout << "Please enter your name: ";
  std::cin >> name;
  std::cout << "Please enter you age: ";
  std::cin >> age;
  
  std::cout << name << std::endl;
  std::cout << age;
}