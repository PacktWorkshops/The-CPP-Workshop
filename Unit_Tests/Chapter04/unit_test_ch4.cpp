Chapter 4 : Example 1

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(int numberToCheck) {
   std::ostringstream out;
   if (numberToCheck <= 1)
   {
      out << numberToCheck << " is not prime.";
      return out.str();
   }
   else if (numberToCheck == 2)
   {
      out << numberToCheck << " is prime.";
      return out.str();
   }
   for (int i = 2; i < numberToCheck; ++i)
   {
      if (numberToCheck % i == 0)
      {
         out << numberToCheck << " is not prime.";
         return out.str();
      }
   }
   out << numberToCheck << " is prime.";
 
   return out.str();
}

TEST(Chapter4, Example1) {
   EXPECT_EQ("10 is not prime.", TestCase(10));
   EXPECT_EQ("1 is not prime.", TestCase(1));
   EXPECT_EQ("2 is prime.", TestCase(2));
   EXPECT_EQ("11 is prime.", TestCase(11));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
   std::ostringstream out;
   int myInt1 = 1;
   int myInt2 = 1;
   int myInt3 = 5;

   if (myInt1 == myInt2)
   {
      out << myInt1 << " is equal to " << myInt2 << ".\n";
   }

   if (myInt1 != myInt3)
   {
      out << myInt1 << " is not equal to " << myInt3;
   }
 
   return out.str();
}

TEST(Chapter4, Example1) {
   EXPECT_EQ("1 is equal to 1.\n1 is not equal to 5", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
   std::ostringstream out;
   int myInt1 = 1;
   int myInt2 = 1;
   int myInt3 = 5;

   if (myInt1 > myInt2)
   {
      out << myInt1 << " is greater than" << myInt2 << ".\n";
   }

   if (myInt1 < myInt3)
   {
      out << myInt1 << " is less than " << myInt3 << ".\n";
   }

   if (myInt3 >= myInt2)
   {
      out << myInt3 << " is greater than or equal to " << myInt2 << ".\n";
   }

   if (myInt2 <= myInt1)
   {
      out << myInt2 << " is less than or equal to " << myInt1;
   }

   return out.str();
}

TEST(Chapter4, Example1) {
   EXPECT_EQ("1 is less than 5.\n5 is greater than or equal to 1.\n1 is less than or equal to 1", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 4 : Example 2 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(int time) {
   std::ostringstream out;
   if (time < 0000 || time > 2400)
   {
      out << "Invalid time.";
      return out.str();
   }
   if (time == 0000)
   {
      out << "It's currently midnight.";
   }
   else if (time == 1200)
   {
      out << "It's currently noon.";
   }
   else if (time >= 0600 && time < 1200)
   {
      out << "It's currently morning.";
   }
   else if (time > 1200 && time <= 1700)
   {
      out << "It's currently afternoon.";
   }
   else if (time > 1700 && time <= 2000)
   {
      out << "It's currently evening.";
   }
   else if (time > 2000 || time < 0600)
   {
      out << "It's currently night.";
   }

   return out.str();
}

TEST(Chapter4, Example2) {
   EXPECT_EQ("Invalid time.", TestCase(-2000));
   EXPECT_EQ("Invalid time.", TestCase(3000));
   EXPECT_EQ("It's currently midnight.", TestCase(0000));
   EXPECT_EQ("It's currently noon.", TestCase(1200));
   EXPECT_EQ("It's currently morning.", TestCase(1000));
   EXPECT_EQ("It's currently afternoon.", TestCase(1500));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



Chapter 4 : Example 3

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
   std::ostringstream out;
   int myInt = 5;

   out << ++myInt << std::endl;
   out << myInt << std::endl;
   
   myInt = 5;

   out << myInt++ << std::endl;
   out << myInt << std::endl;
      
   return out.str();
}

TEST(Chapter4, Example3) {
   EXPECT_EQ("6\n6\n5\n6\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}





Chapter 4 : Example 4 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(std::string name1, std::string name2, std::string name3) {
   std::ostringstream out;
   if (name1 == name2 && name2 == name3)
   {
      out << "\nAll the names are the same.";
   }
   else if (name1 == name2 || name2 == name3 || name1 == name3)
   {
      out << "\nSome of the names matched.";
   }
   out << "\nNames 1 and 2 are " << (!(name1 == name2) ? "different." : "the same.") << std::endl;
      
   return out.str();
}

TEST(Chapter4, Example4) {
   EXPECT_EQ("\nAll the names are the same.\nNames 1 and 2 are the same.\n", TestCase("Packt", "Packt", "Packt"));
   EXPECT_EQ("\nSome of the names matched.\nNames 1 and 2 are different.\n", TestCase("Packt", "Name", "Packt"));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
   void operator+ (MyClass const& other)
   {
      out << "Overloaded Operator Called" << std::endl;
      return;
   }
};

std::string TestCase() {
   MyClass A = MyClass();
   MyClass B = MyClass();
   A + B;
   return out.str();
}

TEST(Chapter4, Example4) {
   EXPECT_EQ("Overloaded Operator Called\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 4 : Example 5 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class Person
{
public:

   Person(int age, std::string name) :
      age(age), name(name)
   {
   };

   float age = 0;
   std::string name = "";
   bool operator== (Person const& other)
   {
      return ((age == other.age) && (name == other.name));
   }
};


std::string TestCase() {
   Person PersonA = Person(27, "Lucy");
   Person PersonB = Person(27, "Lucy");
   Person PersonC = Person(27, "Susan");

   out << (PersonA == PersonB) << std::endl;
   out << (PersonB == PersonC) << std::endl;

   return out.str();
}

TEST(Chapter4, Example5) {
   EXPECT_EQ("1\n0\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


#include "pch.h"
#include <iostream>
#include <bitset>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
   std::ostringstream out;

   int myInt1 = 6;     // 00110 when expressed in binary
   int myInt2 = 12;    // 01100 when expressed in binary

                       // Binary AND
   out << std::bitset<5>(myInt1 & myInt2) << std::endl;

   // Binary OR
   out << std::bitset<5>(myInt1 | myInt2) << std::endl;

   // Binary Ones Compliment
   out << std::bitset<5>(~myInt1) << std::endl;

   // Binary Left Shift Operator
   out << std::bitset<5>(myInt1 << 2) << std::endl;

   // Binary Right Shift Operator
   out << std::bitset<5>(myInt2 >> 2) << std::endl;

   return out.str();
}

TEST(Chapter4, Example5) {
   EXPECT_EQ("00100\n01110\n11001\n11000\n00011\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}








Chapter 4 : Activity 

include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
   std::ostringstream out;
   for (int i = 1; i <= 100; ++i)
   {
      bool multiple = false;
      if (i % 3 == 0)
      {
         out << "Fizz";
         multiple = true;
      }
      if (i % 5 == 0)
      {
         out << "Buzz";
         multiple = true;
      }
      if (!multiple)
      {
         out << i;
      }
      if (i < 100)
      {
         out << ", ";
      }
   }

   return out.str();
}

TEST(Chapter4, Activity) {
   EXPECT_EQ("1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16, 17, Fizz, 19, Buzz, Fizz, 22, 23, Fizz, Buzz, 26, Fizz, 28, 29, FizzBuzz, 31, 32, Fizz, 34, Buzz, Fizz, 37, 38, Fizz, Buzz, 41, Fizz, 43, 44, FizzBuzz, 46, 47, Fizz, 49, Buzz, Fizz, 52, 53, Fizz, Buzz, 56, Fizz, 58, 59, FizzBuzz, 61, 62, Fizz, 64, Buzz, Fizz, 67, 68, Fizz, Buzz, 71, Fizz, 73, 74, FizzBuzz, 76, 77, Fizz, 79, Buzz, Fizz, 82, 83, Fizz, Buzz, 86, Fizz, 88, 89, FizzBuzz, 91, 92, Fizz, 94, Buzz, Fizz, 97, 98, Fizz, Buzz", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

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
