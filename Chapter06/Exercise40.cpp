#include <iostream>
using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};

int main()
{
    cout << "getting a noisy array" << endl;
    noisy* pnoisy = new noisy[3];
    cout << "deleting noisy array" << endl;
    delete[] pnoisy;
    
    return 0;
}

