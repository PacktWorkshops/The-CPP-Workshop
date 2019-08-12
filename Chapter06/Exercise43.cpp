#include <iostream>
using namespace std;

int main()
{
    char* p = new char[10];
    p[0] = '!';
    cout << "p[0] = " << p[0] << endl;
    return 0;
}

