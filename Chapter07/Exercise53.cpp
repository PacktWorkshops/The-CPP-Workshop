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
    unique_ptr<noisy> u1(new noisy);
    unique_ptr<noisy> u2 = make_unique<noisy>();
    auto u3 = make_unique<noisy[]>(4);
    return 0;
}

