#include <iostream>
using namespace std;

int main()
{
   int a[7]{ 1, 3, 5, 4, 2, 9, -1 };
   int *p = nullptr;
   
   p = &a[2];
   cout << "*p = " << *p << ", a[2] = " << a[2] << endl;
   
   cout << "p[3] = " << p[3] << ", a[5] = " << a[5] << endl;

   return 0;
}

