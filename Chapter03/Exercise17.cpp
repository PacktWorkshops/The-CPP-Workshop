// Vector example.
#include <iostream>
#include <string>
#include <vector>
std::vector<int> myVector {1, 2, 3, 4, 5};
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
    myVector.pop_back();
    PrintVector();
    myVector.push_back(6);
    PrintVector();
    myVector.erase(myVector.begin() + 1);
    PrintVector();
    myVector.insert(myVector.begin() + 3, 8);
    PrintVector();
 }
