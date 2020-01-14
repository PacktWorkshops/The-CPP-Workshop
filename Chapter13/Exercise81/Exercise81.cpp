#include <iostream>

using namespace std;

int deeply_nested() 
{
    throw 123;
    return 0;
}

int main() 
{
    try 
    {
        deeply_nested();
    } 
    catch (...) 
    {
        cout << "in catch ..." << endl;
    }
    cout << "in main(), after try/catch" << endl;
    
    return 0;
}
