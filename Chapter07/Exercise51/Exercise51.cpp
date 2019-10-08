#include <iostream>
#include <cstring>

using namespace std;

struct noisy_and_big
{
    noisy_and_big() { cout << "constructing noisy" << endl; }
   ~noisy_and_big() { cout << "destroying noisy" << endl; }
    char big_buffer_[10000];
};

noisy_and_big* get_noisy_and_big(char const* str)
{
    noisy_and_big* ownedp = new noisy_and_big;
    strcpy(ownedp->big_buffer_, str);
}

int main()
{
    noisy_and_big* newownedp = get_noisy_and_big("a big, big buffer");
    cout << "noisy and big: " << newownedp->big_buffer_ << endl;
    
    delete newownedp;

    return 0;
}

