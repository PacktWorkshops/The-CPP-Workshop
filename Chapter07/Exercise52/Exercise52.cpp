#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

struct noisy
{
    noisy() { cout << "default constructing noisy" << endl; }
    noisy(int i) { cout << "constructing noisy: arg " << i << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};
 
int main()
{
    unique_ptr<noisy> u1(new noisy);
    unique_ptr<noisy> u2;
    u2.reset(new noisy(100));
    unique_ptr<noisy[]> u3(new noisy[3]);
    unique_ptr<noisy[]> u4(new noisy[2]{1});
    unique_ptr<noisy> u5;

    cout << "before transfer of ownership u1 = " << u1.get() 
         << ", u5 = " << u5.get() << endl;
    u5.reset(u1.release());
    cout << "after transfer of ownership u1 = " << u1.get() 
         << ", u5 = " << u5.get() << endl;
    u1 = move(u5);
    cout << "after second transfer u1 = " << u1.get() 
         << ", u5 = " << u5.get() << endl;

    unique_ptr<char[]> buf(new char[20]);
    strcpy(buf.get(), "xyzzy");
    cout << "buf = " << buf.get() << endl;
    return 0;
}

