Chapter 5 : Exercise 2

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

std::string TestCase () {
   int a[7]{ 1, 3, 5, 4, 2, 9, -1 };
   int *p = nullptr;

   p = &a[2];
   out << "*p = " << *p << ", a[2] = " << a[2] << endl;

   out << "p[3] = " << p[3] << ", a[5] = " << a[5] << endl;

   return out.str();
}

TEST(Chapter5, Exercise2) {

   EXPECT_EQ("*p = 5, a[2] = 5\np[3] = 9, a[5] = 9\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 3

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out; 
   int a[7]{ 1, 3, 5, 4, 2, 9, -1 };
   int *p = nullptr;

   p = &a[2];
   out << "*p = " << *p << ", a[2] = " << a[2] << endl;
   out << "p[3] = " << p[3] << ", a[5] = " << a[5] << endl;
   return out.str();
}

TEST(Chapter5, Exercise3) {

   EXPECT_EQ("*p = 5, a[2] = 5\np[3] = 9, a[5] = 9\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 4 

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out; 
   int numbers[5]{ 0, 100, 200, 300, 400 };
   int* pint = numbers;
   int* p2 = &numbers[3];

   out << "pint = " << pint << ", pint+1 = " << pint + 1
      << ", sizeof(int) = " << sizeof(int) << endl;

   out << "*(pint+1) = " << *(pint + 1)
      << ", pint[1] = " << pint[1] << endl;

   out << "*(pint+4) = " << *(pint + 4)
      << ", pint[4] = " << pint[4] << endl;

   out << "p2 - pint = " << p2 - pint << endl;

   out << "p2 == pint = " << boolalpha << (p2 == pint) << endl;
   out << "p2 > pint = " << boolalpha << (p2 > pint) << endl;

   return out.str();
}

TEST(Chapter5, Exercise4) {

   EXPECT_EQ("pint = 001BFA84, pint\n1 = 001BFA88, sizeof(int) = 4\n*(pint\n1) = 100, pint[1] = 100\n*(pint\n4) = 400, pint[4] = 400\np2 - pint = 3\np2 == pint = false\np2 > pint = true\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 5 

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out; 
   int a[]{ 10, 20, 30, 40, 50 };
   int* p;
   for (p = a; p < a + sizeof(a) / sizeof(a[0]); ++p)
   {
      out << *p << " ";
   }
   return out.str();
}

TEST(Chapter5, Exercise5) {

   EXPECT_EQ("10 20 30 40 50 ", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 6

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out; 
   char* alphabet[26]
   {
      "alpha",
      "bravo",
      "charlie",
      "delta",
      "echo",
      "foxtrot"
   };
   for (char **p = alphabet; *p != nullptr; ++p)
   {
      out << *p << " ";
   }

   return out.str();
}

TEST(Chapter5, Exercise6) {

   EXPECT_EQ("alpha bravo charlie delta echo foxtrot ", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 7 

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out; 
   int i = 10;
   int& ir = i;
   i = i + 10;
   ir = ir * 10;
   out << "i = " << i << endl;
   int* ip = &ir;
   *ip = 33;
   out << "i = " << i << ", *ip = " << *ip << ", ir = " << ir << endl;

   return out.str();
}

TEST(Chapter5, Exercise7) {

   EXPECT_EQ("i = 200\ni = 33, *ip = 33, ir = 33\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 5 : Exercise 9

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

void copychars(char* from, char* to, int count)
{
   if (from == nullptr || to == nullptr)
      return;

   while (count-- > 0)
   {
      *to++ = *from++;
   }
}

std::string TestCase () {
   std::ostringstream out;
   char string[]{ "uvwxyz" };
   char buffer[10];
   copychars(string, buffer, 7);
   out << buffer << endl;
   return out.str();
}

TEST(Chapter5, Exercise9) {

   EXPECT_EQ("uvwxyz\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 5 : Exercise 10

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
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
   out << "Hello. I am " << (*p).name_ << ". ";
   if (p->hero_)
      out << "I am a hero." << endl;
   else
      out << "I am a villain." << endl;
}

std::string TestCase () {    
   out << sizeof(mydata) << " " << sizeof(mydata*) << endl;

   for (mydata* p = heroes; p < heroes + 6; ++p)
   {
      printdata(p);
   }

   return out.str();
}

TEST(Chapter5, Exercise10) {

   EXPECT_EQ("8 4\nHello. I am Spider Man. I am a hero.\nHello. I am The Joker. I am a villain.\nHello. I am Doctor Octopus. I am a villain.\nHello. I am Thor. I am a hero.\nHello. I am Batman. I am a hero.\nHello. I am Loki. I am a villain.\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 5 : Exercise 11 

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct mydata
{
   char const* name_;
   bool darkside_;
   mydata(char const* name, bool dark)
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
   out << "Hello. I am " << data.name_ << endl;
   if (data.darkside_)
      out << "I was seduced by the dark side" << endl;
}

std::string TestCase () {    
   for (mydata& data : cast)
   {
      printname(data);
   }
   return out.str();
}

TEST(Chapter5, Exercise11) {

   EXPECT_EQ("Hello. I am Darth Vader\nI was seduced by the dark side\nHello. I am Luke Skywalker\nHello. I am Han Solo\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 5 : Acitivity 1

#include <iostream>
#include <string>
#include "gtest/gtest.h"

std::ostringstream out;
char const* array[26]
{ "alpha", "bravo", "charlie", "delta", "echo" };

int printarray(char const** begin, char const** end, int& count)
{
   if (begin == nullptr || end == nullptr ||
      begin > end || end - begin > 26)
   {
      return 0;
   }

   for (count = 0; begin < end; ++begin)
   {
      if (*begin != nullptr)
      {
         ++count;
         out << *begin << std::endl;
      }
   }
   return 1;
}

std::string TestCase () {    
   int count;
   if (printarray(nullptr, nullptr, count) == 0 || count != 0)
   {
      out << "error in printarray() call 1" << std::endl;
   }
   else
   {
      out << "count = " << count << std::endl;
   }

   if (printarray(array, &array[4], count) == 0 || count != 4)
   {
      out << "error in printarray() call 2" << std::endl;
   }
   else
   {
      out << "count = " << count << std::endl;
   }

   if (printarray(&array[4], &array[3], count) == 0 || count != 0)
   {
      out << "error in printarray() call 3" << std::endl;
   }
   else
   {
      out << "count = " << count << std::endl;
   }

   if (printarray(&array[4], &array[10], count) == 0 || count != 1)
   {
      out << "error in printarray() call 4" << std::endl;
   }
   else
   {
      out << "count = " << count << std::endl;
   }

   if (printarray(&array[0], &array[100], count) == 0 || count != 0)
   {
      out << "error in printarray() call 5" << std::endl;
   }
   else
   {
      out << "count = " << count << std::endl;
   }

   return out.str();
}

TEST(Chapter5, Activity1) {

   EXPECT_EQ("error in printarray() call 1\nalpha\nbravo\ncharlie\ndelta\ncount = 4\nerror in printarray() call 3\necho\ncount = 1\nerror in printarray() call 5\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}
