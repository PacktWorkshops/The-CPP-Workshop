// Pass by value-by-reference example.
#include <iostream>
#include <string>

void Modify(int a)
{
  a = a - 1;
}

int main()
{
 int a = 10;
 
 Modify(a);
 
 std::cout << a;
}