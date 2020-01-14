// Vector example.
#include <iostream>
#include <string>
#include <vector>

std::vector<int> myVector;

void PrintVector()
{
   for (int i = 0; i < myVector.size(); ++i)
   {
      std::cout << myVector[i];
   }
   std::cout << "\n\n";
}

int main()
{
   PrintVector();
}
