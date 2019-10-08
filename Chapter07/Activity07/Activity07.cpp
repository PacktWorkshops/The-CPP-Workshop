#include <iostream>
#include <memory>

using namespace std;

class word
{
    friend class line;
    unique_ptr<char[]> ptr_;
    int letters_;
    int spaces_;
    word* next_;
public:
    word(char const* srcp, int l, int spaces);
    
    void to_string(char* dstp);
    
    int size();
};// end word

word::word(char const* srcp, int l, int spaces)
  : ptr_(make_unique<char[]>(l+1)),
    letters_(l),
    spaces_(spaces)
{
    char* dstp;
    for(dstp = ptr_.get(); l > 0; --l)
    {
        *dstp++ = *srcp++;
    }
    *dstp = '\0';
}

void word::to_string(char* dstp)
{
    char* srcp = ptr_.get();
    for (int letters = letters_; letters > 0; --letters)
    {
        *dstp++ = *srcp++;
    }
    for (int spaces = spaces_; spaces > 0; --spaces)
    {
        *dstp++ = ' ';
    }
    *dstp = '\0';
}

int word::size()
{
    return letters_ + spaces_;
}

// class line

class line
{
    friend class page;
    word* head_;
    line* next_;
public:
    line(char const* str);
    
   ~line();
    
    void append(word* w);
    
    void to_string(char* dstp);
    
    int size();
};// end line

line::line(char const* str)
  : head_(nullptr), 
    next_(nullptr)
{
    char const* bp; // pointer to beginning
    char const* ewp;// pointer to end of word
    char const* esp;// pointer to end of spaces
    for (bp = str; *bp != '\0'; bp = esp)
    {
        for (ewp = bp; *ewp != '\0' && *ewp != ' '; ++ewp)
        {
            // empty
        }
        for (esp = ewp; *esp != '\0' && *esp == ' '; ++esp)
        {
            // empty
        }
        append(new word(bp, ewp-bp, esp-ewp));
    }
}

line::~line()
{
    while (head_ != nullptr)
    {
        auto wp = head_;
        head_ = head_->next_;
        delete wp;
    }
}

void line::append(word* w)
{
    word** wpp = &head_;
    while((*wpp) != nullptr)
    {
        wpp = &((*wpp)->next_);
    }
    *wpp = w;
}

void line::to_string(char* dstp)
{
    for (word* wp = head_; wp != nullptr; wp = wp->next_)
    {
        wp->to_string(dstp);
        dstp = dstp + wp->size();
    }
    *dstp = '\0';
}

int line::size()
{
    int size = 1;// for null terminator
    for (word* wp = head_; wp != nullptr; wp = wp->next_)
    {
        size = size + wp->size();
    }
    return size;
}

//  class page

class page
{
    line* head_;
public:
    page();
    
   ~page();
    
    void append(line* lp);
    
    void print();
};// end page

page::page() 
  : head_(nullptr) 
{
    // empty
}

page::~page()
{
    while (head_ != nullptr)
    {
        auto lp = head_;
        head_ = head_->next_;
        delete lp;
    }
}

void page::append(line* lp)
{
    line** lpp = &head_;
    while((*lpp) != nullptr)
    {
        lpp = &((*lpp)->next_);
    }
    *lpp = lp;
}

void page::print()
{
    for (line* lp = head_; lp != nullptr; lp = lp->next_)
    {
        auto buffer = make_unique<char[]>(lp->size());
        lp->to_string(buffer.get());
        cout << '\'' << buffer.get() << '\'' << endl;
    }
}

char const* book[] {
    "What a piece of work is man, ",
    "   How noble in reason, how infinite in faculty,",
    "In form and moving how express and admirable, ",
    "   In action how like an Angel, In apprehension how like a god.",
    "The beauty of the world.  The paragon of animals.",
};

int main()
{
    page pg;
    for (auto* p : book)
    {
        cout << '\'' << p << '\'' << endl;
        auto l = make_unique<line>(p);
        pg.append(l.release());
    }
    cout << endl;
    pg.print();
    return 0;
}
