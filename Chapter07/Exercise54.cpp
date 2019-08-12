#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
   ~noisy() { cout << "destroying noisy" << endl; }
};

class autobuf
{
    unique_ptr<noisy> np_;
    unique_ptr<char[]> ptr_;
public:
    autobuf(char const* str);
    char* get();
};

autobuf::autobuf(char const* str)
  : np_(make_unique<noisy>()),
    ptr_(make_unique<char[]>(strlen(str) + 1))
{
    strcpy(ptr_.get(), str);
}

char* autobuf::get() 
{
    return ptr_.get();
}

int main()
{
   autobuf buffer("my favorite test string");
   cout << "Hello World! " << buffer.get() << endl; 
   
   return 0;
}

