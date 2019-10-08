#include <iostream>
using namespace std;

int main()
{
    char* p = new char[10];
    delete[] p;
    delete[] p;
    return 0;
}

