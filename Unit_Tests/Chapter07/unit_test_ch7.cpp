Chapter 7 : Example 1

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class noisy
{
   char const* s_;
public:
   noisy(char const* s)
   {
      out << "constructing " << s << endl; s_ = s;
   }
   ~noisy()
   {
      out << "destroying " << s_ << endl;
   }
};

void func(char const* s)
{
   noisy func(s);
}

noisy f("global 1");
noisy ff("global 2");

std::string TestCase () {
   
   noisy n1("main() function local 1");
   func("function local 2");

   {
      noisy n("block local");
      func("function local 3");
   }

   return out.str();
}

TEST(Chapter7, Example1) {

   EXPECT_EQ("constructing global 1\nconstructing global 2\nconstructing main() function local 1\nconstructing function local 2\ndestroying function local 2\nconstructing block local\nconstructing function local 3\ndestroying function local 3\ndestroying block local\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}





Chapter 7 : Example 2

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct numeric_item
{
   int value_;
   numeric_item* next_;
};

class numeric_list
{
   numeric_item* head_;
public:
   numeric_list() : head_(nullptr) {}
   ~numeric_list();
   void print();
   void add(int v);
   numeric_item* find(int v);
};
numeric_list::~numeric_list()
{
   while (head_ != nullptr)
   {
      numeric_item* p = head_;
      head_ = head_->next_;
      out << "deleting " << p->value_ << endl;
      delete p;
   }
}

void numeric_list::print()
{
   for (numeric_item* p = head_; p != nullptr; p = p->next_)
   {
      out << p->value_ << " ";
   }
   out << endl;
}

void numeric_list::add(int v)
{
   numeric_item* newp = new numeric_item;
   newp->value_ = v;
   newp->next_ = head_;
   head_ = newp;
}

numeric_item* numeric_list::find(int v)
{
   for (numeric_item* p = head_; p != nullptr; p = p->next_)
   {
      if (p->value_ == v)
         return p;
   }
   return nullptr;
}


std::string TestCase () {
   
   numeric_list l;
   for (int i = 1; i < 6; ++i)
   {
      l.add(i);
   }
   l.print();

   numeric_item* p = l.find(4);
   if (p != nullptr)
      out << "found numeric_item 4" << endl;

   return out.str();
}

TEST(Chapter7, Example2) {

   EXPECT_EQ("5 4 3 2 1 \nfound numeric_item 4\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 7 : Example 3 (Problem with the code, a return value is missing, Pls see the text in bold and italic)

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy_and_big
{
   noisy_and_big() { out << "constructing noisy" << endl; }
   ~noisy_and_big() { out << "destroying noisy" << endl; }
   char big_buffer_[10000];
};

noisy_and_big* get_noisy_and_big(char const* str)
{
   noisy_and_big* ownedp = new noisy_and_big;
   strcpy(ownedp->big_buffer_, str);
   return ownedp;
}

std::string TestCase () {
   
   noisy_and_big* newownedp = get_noisy_and_big("a big, big buffer");
   out << "noisy and big: " << newownedp->big_buffer_ << endl;

   delete newownedp;

   return out.str();
}

TEST(Chapter7, Example3) {

   EXPECT_EQ("constructing noisy\nnoisy and big: a big, big buffer\ndestroying noisy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 7 : Example 3.1 (Answer has address so result will vary every iteration)

#include "pch.h"
#include <iostream>
#include <memory>
#include <cstring>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy
{
   noisy() { out << "default constructing noisy" << endl; }
   noisy(int i) { out << "constructing noisy: arg " << i << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};

std::string TestCase () {
   
   unique_ptr<noisy> u1(new noisy);
   unique_ptr<noisy> u2;
   u2.reset(new noisy(100));
   unique_ptr<noisy[]> u3(new noisy[3]);
   unique_ptr<noisy[]> u4(new noisy[2]{ 1 });
   unique_ptr<noisy> u5;

   out << "before transfer of ownership u1 = " << u1.get()
      << ", u5 = " << u5.get() << endl;
   u5.reset(u1.release());
   out << "after transfer of ownership u1 = " << u1.get()
      << ", u5 = " << u5.get() << endl;
   u1 = move(u5);
   out << "after second transfer u1 = " << u1.get()
      << ", u5 = " << u5.get() << endl;

   unique_ptr<char[]> buf(new char[20]);
   strcpy(buf.get(), "xyzzy");
   out << "buf = " << buf.get() << endl;

   return out.str();
}

TEST(Chapter7, Example3.1) {

   EXPECT_EQ("default constructing noisy\nconstructing noisy: arg 100\ndefault constructing noisy\ndefault constructing noisy\ndefault constructing noisy\nconstructing noisy: arg 1\ndefault constructing noisy\nbefore transfer of ownership u1 = 00F70B40, u5 = 00000000\nafter transfer of ownership u1 = 00000000, u5 = 00F70B40\nafter second transfer u1 = 00F70B40, u5 = 00000000\nbuf = xyzzy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 7 : Example 4

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};

std::string TestCase () {
   unique_ptr<noisy> u1(new noisy);
   unique_ptr<noisy> u2 = make_unique<noisy>();
   auto u3 = make_unique<noisy[]>(4);

   return out.str();
}

TEST(Chapter7, Example4) {
   EXPECT_EQ("constructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 7 : Example 5 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
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

void UnitMainTest() {
   autobuf buffer("my favorite test string");
   out << "Hello World! " << buffer.get() << endl;
}

std::string TestCase () {
   UnitMainTest();
   return out.str();
}

TEST(Chapter7, Example5) {
   EXPECT_EQ("constructing noisy\nHello World! my favorite test string\ndestroying noisy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 7 : Example 6 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};

unique_ptr<noisy> func()
{
   return make_unique<noisy>();
}

void UnitMainTest() {
   auto u1 = func();
}

std::string TestCase () {
   UnitMainTest();
   return out.str();
}

TEST(Chapter7, Example6) {
   EXPECT_EQ("constructing noisy\ndestroying noisy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 7 : Example 7 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

shared_ptr<char[]> func(shared_ptr<char[]> str)
{
   if (!str)
   {
      str.reset(new char[1]);
      str[0] = '\0';
   }
   return str;
}

std::string TestCase () {
   shared_ptr<char[]> null;
   if (null.get() == nullptr)
      out << "null is equal to nullptr" << endl;
   auto result1 = func(null);
   if (result1.get() == nullptr)
      out << "result1 is equal to nullptr" << endl;
   result1 = func(result1);

   return out.str();
}

TEST(Chapter7, Example7) {
   EXPECT_EQ("null is equal to nullptr\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 7 : Example 8 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};

void UnitMainTest()
{
   shared_ptr<noisy> u1(new noisy);
   shared_ptr<noisy> u2 = make_shared<noisy>();
   shared_ptr<noisy> u3 = u2;
   u2.reset();
}

std::string TestCase () {
   UnitMainTest();
   return out.str();
}

TEST(Chapter7, Example8) {
   EXPECT_EQ("constructing noisy\nconstructing noisy\ndestroying noisy\ndestroying noisy\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 7 : Activity 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
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
   : ptr_(make_unique<char[]>(l + 1)),
   letters_(l),
   spaces_(spaces)
{
   char* dstp;
   for (dstp = ptr_.get(); l > 0; --l)
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
      append(new word(bp, ewp - bp, esp - ewp));
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
   while ((*wpp) != nullptr)
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
   while ((*lpp) != nullptr)
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
      out << '\'' << buffer.get() << '\'' << endl;
   }
}

char const* book[]{
   "What a piece of work is man, ",
   "   How noble in reason, how infinite in faculty,",
   "In form and moving how express and admirable, ",
   "   In action how like an Angel, In apprehension how like a god.",
   "The beauty of the world.  The paragon of animals.",
};

std::string TestCase() {
   page pg;
   for (auto* p : book)
   {
      out << '\'' << p << '\'' << endl;
      auto l = make_unique<line>(p);
      pg.append(l.release());
   }
   out << endl;
   pg.print();
   return out.str();
}

TEST(Chapter7, Activity) {

   EXPECT_EQ("'What a piece of work is man, '\n'   How noble in reason, how infinite in faculty,'\n'In form and moving how express and admirable, '\n'   In action how like an Angel, In apprehension how like a god.'\n'The beauty of the world.  The paragon of animals.'\n'What a piece of work is man, '\n'   How noble in reason, how infinite in faculty,'\n'In form and moving how express and admirable, '\n'   In action how like an Angel, In apprehension how like a god.'\n'The beauty of the world.  The paragon of animals.'", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
