Chapter 1 : Exercise 1

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"

std::string TestCase () {    
   std::ostringstream out;
   out << "Hello World!";
   return out.str();
}

TEST(Chapter1, Example1) {

   EXPECT_EQ("Hello World!", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 1 : Exercise 2

#include <iostream>
#include <string>
#include "gtest/gtest.h"

#define GRADE_C_THRESHOLD 25
#define GRADE_B_THRESHOLD 50
#define GRADE_A_THRESHOLD 75

std::string TestCase (int value) {
   std::ostringstream out;
   if (value < GRADE_C_THRESHOLD)
   {
      out << "Fail";
   }
   else if (value < GRADE_B_THRESHOLD)
   {
      out << "Pass: Grade C";
   }
   else if (value < GRADE_A_THRESHOLD)
   {
      out << "Pass: Grade B";
   }
   else
   {
      out << "Pass: Grade A";
   }
   return out.str();
}

TEST(Chapter1, Example2) {

   EXPECT_EQ("Fail", TestCase(20));
   EXPECT_EQ("Pass: Grade C", TestCase(40));
   EXPECT_EQ("Pass: Grade B", TestCase(60));
   EXPECT_EQ("Pass: Grade A", TestCase(80));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 1 : Exercise 4

#include <iostream>
#include <string>
#include "gtest/gtest.h"

using namespace std;

int Max(int a, int b)
{
   if (a > b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

TEST(Chapter1, Exercise4) {

   EXPECT_EQ(10, Max(10, 1));
   EXPECT_EQ(100, Max(10, 100));
   EXPECT_EQ(20, Max(10, 20));
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 1 : Activity 

#include <iostream>
#include <string>
#include "gtest/gtest.h"

using namespace std;

#define GROUP_1_THRESHOLD 12
#define GROUP_2_THRESHOLD 28

#define GROUP_1_NAME "Group A"
#define GROUP_2_NAME "Group B"
#define GROUP_3_NAME "Group C"

std::string GetGroup(int age)
{
   if (age <= GROUP_1_THRESHOLD)
   {
      return GROUP_1_NAME;
   }
   else if (age <= GROUP_2_THRESHOLD)
   {
      return GROUP_2_NAME;
   }
   else
   {
      return GROUP_3_NAME;
   }
}

TEST(Chapter1, Activity) {
   
   EXPECT_EQ("Group A", GetGroup(10));
   EXPECT_EQ("Group B", GetGroup(25));
   EXPECT_EQ("Group C", GetGroup(34));
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
