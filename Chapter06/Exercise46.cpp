#include <iostream>
using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};

int main()
{
    noisy* p = new noisy[3];
    delete p;
    return 0;
}
