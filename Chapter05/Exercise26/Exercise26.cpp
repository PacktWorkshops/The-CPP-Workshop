#include <iostream>

using namespace std;
int main()
{
   int i = 12345;
   int *p = &i;
   cout << "p = " << p << ", &i = " << &i << endl;

   cout << "i = " << i << endl;
   *p = *p + 2;
   cout << "i = " << i << endl; 
   
   return 0;
}
