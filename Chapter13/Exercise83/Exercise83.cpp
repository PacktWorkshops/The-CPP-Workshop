#include <iostream>
#include <exception>
#include <memory>

using namespace std;

class noisy
{
    char const* s_;
public:
    noisy(char const* s) { cout << "constructing " << (s_ = s) << endl; }
   ~noisy() { cout << "destroying " << s_ << endl; }
};

int deeply_nested()
{
    auto n = make_unique<noisy>("deeply_nested");
    throw logic_error("totally illogical");
    return 0;
}

int intermediate()
{
    noisy n("intermediate");
    int rc = deeply_nested();
    cout << "after calling deeply_nested()" << endl;
    return rc;
    return 0;
}

int main()
{
    try
    {
        auto n = make_unique<noisy>("try in main");
        int rc = intermediate();
        cout << "intermediate() returned " << rc << endl;
    }
    catch (exception& e)
    {
        cout << "in catch: exception: " << e.what() << endl;
    }
    
    cout << "ending main" << endl; 
    
    return 0;
}
