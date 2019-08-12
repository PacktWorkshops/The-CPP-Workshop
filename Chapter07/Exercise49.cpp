#include <iostream>
using namespace std;

class noisy
{
    char const* s_;
public:
    noisy(char const* s) 
    { cout << "constructing " << s << endl; s_ = s; }
   ~noisy()
    { cout << "destroying " << s_ << endl; }
};

void func(char const* s)
{
    noisy func(s);
}

noisy f("global 1");
noisy ff("global 2");

int main()
{
    noisy n1("main() function local 1");
    func("function local 2");

    {
        noisy n("block local");
        func("function local 3");
    }

    return 0;
}

