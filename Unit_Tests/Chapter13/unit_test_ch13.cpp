Chapter 13 : Exercise 2

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
int deeply_nested()
{
   throw 123;
   return 0;
}
std::string TestCase() {
   try
   {
      deeply_nested();
   }
   catch (...)
   {
      out << "in catch ..." << endl;
   }

   out << "in main(), after try/catch" << endl;

   return out.str();
}

TEST(Chapter13, Exercise2) {

   EXPECT_EQ("in catch ...\nin main(), after try/catch\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 13 : Exercise 3

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
int deeply_nested()
{
   string("xyzzy").at(100);
   return 0;
}
std::string TestCase() {
   try
   {
      deeply_nested();
   }
   catch (exception& e)
   {
      out << "caught " << e.what() << endl;
   }
   catch (...)
   {
      out << "in catch ..." << endl;
   }

   out << "in main(), after try/catch" << endl;

   return out.str();
}

TEST(Chapter13, Exercise3) {

   EXPECT_EQ("", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 13 : Exercise 4 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class noisy
{
   char const* s_;
public:
   noisy(char const* s) { out << "constructing " << (s_ = s) << endl; }
   ~noisy() { out << "destroying " << s_ << endl; }
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
   out << "after calling deeply_nested()" << endl;
   return rc;
}

std::string TestCase() {
   try
   {
      auto n = make_unique<noisy>("try in main");

      int rc = intermediate();
      out << "intermediate() returned " << rc << endl;
   }
   catch (exception& e)
   {
      out << "in catch: exception: " << e.what() << endl;
   }
   out << "ending main" << endl;

   return out.str();
}

TEST(Chapter13, Exercise4) {

   EXPECT_EQ("constructing try in main\nconstructing intermediate\nconstructing deeply_nested\ndestroying deeply_nested\ndestroying intermediate\ndestroying try in main\nin catch: exception: totally illogical\nending main\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 13 : Activity 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
void SCRAM()
{
   out << "SCRAM! I mean it. Get away from here!" << endl;
}

bool reactor_safety_check()
{
   static int count = 0;
   ++count;
   if (count % 17 == 0)
   {
      throw runtime_error("Sensor glitch");
   }
   else if (count % 69 == 0)
   {
      throw 123;
      //    throw exception();
   }
   else if (count % 199 == 0)
   {
      return false;
   }

   return true;
}

std::string TestCase() {
   bool continue_flag;
   do
   {
      try
      {
         continue_flag = reactor_safety_check();
      }
      catch (runtime_error& e)
      {
         out << "caught runtime error " << e.what() << endl;
      }
      catch (exception& e)
      {
         out << "caught exception " << e.what() << endl;
         SCRAM();
         break;
      }
      catch (...)
      {
         out << "caught unknown exception type" << endl;
         SCRAM();
         break;
      }
   } while (continue_flag == true);
   out << "shutting down" << endl;

   return out.str();
}

TEST(Chapter13, Activity) {

   EXPECT_EQ("caught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught unknown exception type\nSCRAM! I mean it. Get away from here!\nshutting down\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
