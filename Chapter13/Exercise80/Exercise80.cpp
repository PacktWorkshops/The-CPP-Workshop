#include <iostream>
using namespace std;
int deeply_nested()
{
    throw 123;
    cout << "in deeply_nested() after throw" << endl;
    return 0;
}
int intermediate()
{
    int rc = deeply_nested();
    cout << "in intermediate(), after deeply_nested()";
    return rc;
}
int main()
{
    intermediate();
    return 0;
}
