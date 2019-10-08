#include <iostream>
using namespace std;

struct mydata
{
    char const* name_;
    bool darkside_;
    mydata (char const* name, bool dark) 
    { 
        name_ = name; darkside_ = dark; 
    }
};
mydata cast[3]
{
    { "Darth Vader", true },
    { "Luke Skywalker", false },
    { "Han Solo", false }
};

void printname(mydata& data)
{
    cout << "Hello. I am " << data.name_ << endl;
    if (data.darkside_)
        cout << "I was seduced by the dark side" << endl;
}

int main()
{
    for (mydata& data : cast)
    {
        printname(data);
    }
    return 0;
}

