#include <iostream>
void MyFunc()
{
  int myInt1 = 1;
}
int main()
{
  int myInt2 = 2;
   {
     int myInt3 = 3;
   }
// print values
std::cout << myInt1 << std::endl;
std::cout << myInt2 << std::endl;
std::cout << myInt3 << std::endl;
}
