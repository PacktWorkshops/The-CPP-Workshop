#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string str;
    string str1("Hello, I'm a string!");
    string str2(str1);
    string str3(str1, 0, 5);
    string str4("Hello, I'm a string!", 0, 5);
    string str5(10, 'x');
    string str6(str4.begin() + 1, str4.end() - 1);
   
    cout << str << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    cout << str6 << endl;
 
    return 0;
}

