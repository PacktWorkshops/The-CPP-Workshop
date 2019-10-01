// Function overloading example.
#include <iostream>
#include <string>

int Multiply(int a, int b)
{
  std::cout << "Called the int overload." << std::endl;
  return a * b;
}
  
float Multiply(float a, float b)
{
  std::cout << "Called the float overload." << std::endl;
  return a * b;
}

double Multiply(double a, double b)
{
  std::cout << "Called the double overload." << std::endl;
  return a * b;
}
int main()
{
  Multiply(3, 4);
  Multiply(4.f, 6.f);
  Multiply(5.0, 3.0);
  
  return 0;
}