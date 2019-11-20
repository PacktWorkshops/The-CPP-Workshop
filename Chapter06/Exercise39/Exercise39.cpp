#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char const* cp = "arbitrary null terminated text string";
    char* buffer = new char[ strlen(cp)+1 ];
    strcpy(buffer, cp);
    cout << "buffer = " << buffer << endl;
    delete[] buffer;
    
    return 0;
}


