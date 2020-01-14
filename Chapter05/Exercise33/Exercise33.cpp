#include<iostream>

using namespace std;

int main()
{
    char* p = nullptr;
    char& r = *p;
    r = '!';
    return 0;
}
