#include <iostream>
#include <memory>

using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};

unique_ptr<noisy> func()
{
    return make_unique<noisy>();
}
 
int main()
{
    auto u1 = func();
    return 0;
}

