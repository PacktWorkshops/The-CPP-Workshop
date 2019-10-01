// Keywords example.
#include <iostream>
#include <string>

int main()
{
  // Data type keywords.
  int myInt = 1;
  double myDouble = 1.5;
  char myChar = 'c';
  bool myBool = true;
  
  // Program flow keywords.
  if (myBool)
  {
    std::cout << "true";
  }
  else
  {
    std::cout << "false";
  }
  
  struct myStruct {
    int myInt = 1;
  };
}