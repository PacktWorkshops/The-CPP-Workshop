#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    int& ir = i;
    i = i + 10;
    ir = ir * 10;
    cout << "i = " << i << endl;
    int* ip = &ir;
    *ip = 33;
    
    cout << "i = " << i << ", *ip = " << *ip << ", ir = " << ir << endl;
    return 0;
}

