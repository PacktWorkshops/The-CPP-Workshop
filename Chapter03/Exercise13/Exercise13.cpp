#include<iostream>
using namespace std;
int main()
{
   int myInt = 1;
   bool myBool = false;
   char myChar = 'a';
   std::cout << "The size of an int is " << sizeof(myInt) << ".\n";
   std::cout << "The size of a bool is " << sizeof(myBool) << ".\n";
   std::cout << "The size of a char is " << sizeof(myChar) << ".\n";
   return 0;
}

