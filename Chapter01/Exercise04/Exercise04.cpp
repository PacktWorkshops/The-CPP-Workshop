// IO Exercise.
#include <iostream>
#include <string>
using namespce std;

int Max(int a, int b) 
{
    if (a > b) 
    {
        return a;
    } 
    else 
    {
        return b;
    }
}

int main() 
{
    int value1 = 0;
    int value2 = 0;
    cout << "Please input number 1: ";
    cin >> value1;
    cout << "Please input number 2: ";
    cin >> value2;
    cout << "The highest number is " << Max(value1, value2);
}
