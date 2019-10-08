#include <iostream>
using namespace std;

struct mydata
{
    char const* name_;
    bool hero_;
};
mydata heroes[]
{
    { "Spider Man", true },
    { "The Joker", false },
    { "Doctor Octopus", false },
    { "Thor", true },
    { "Batman", true },
    { "Loki", false }
};

void printdata(mydata* p)
{
    cout << "Hello. I am " << (*p).name_ << ". ";
    if (p->hero_)
        cout << "I am a hero." << endl;
    else
        cout << "I am a villain." << endl;
}

int main()
{
    cout << sizeof(mydata) << " " << sizeof(mydata*) << endl;
    
    for (mydata* p = heroes; p < heroes + 6; ++p)
    {
        printdata(p);
    }
    return 0;
}

