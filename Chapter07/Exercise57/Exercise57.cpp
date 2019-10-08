#include <iostream>
#include <memory>

using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};
 
int main()
{
    shared_ptr<noisy> u1(new noisy);
    shared_ptr<noisy> u2 = make_shared<noisy>();
    shared_ptr<noisy> u3 = u2;
    u2.reset();
    return 0;
}

