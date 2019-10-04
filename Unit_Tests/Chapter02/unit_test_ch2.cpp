Chapter 2 : Exercise 5
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string GetNumber(int number) {

   if (number < 10)
   {
      return "The number you entered was less than 10!\n";
   }
   else if (number > 10)
   {
      return "The number you entered was greater than 10!\n";
   }
}


TEST(Chapter2, Exercise5) {
   
   EXPECT_EQ("The number you entered was less than 10!\n", GetNumber(2));
   EXPECT_EQ("The number you entered was greater than 10!\n", GetNumber(34));
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 2 : Exercise 6

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Menu(int number) {
   std::ostringstream out;
   if (number == 1)
   {
      out << "Fries: $0.99\n";
   }
   else if (number == 2)
   {
      out << "Burger: $1.25\n";
   }
   else if (number == 3)
   {
      out << "Shake: $1.50\n";
   }
   else
   {
      out << "Invalid choice.";
   }
   return out.str();
}


TEST(Chapter2, Exercise6) {
   
   EXPECT_EQ("Fries: $0.99\n", Menu(1));
   EXPECT_EQ("Burger: $1.25\n", Menu(2));
   EXPECT_EQ("Shake: $1.50\n", Menu(3));
   EXPECT_EQ("Invalid choice.", Menu(4));
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 2 : Exercise 7

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Menu(int number) {
   std::ostringstream out;
   switch (number)
   {
   case 1:
      out << "Fries: $0.99\n";
      break;

   case 2:
      out << "Burger: $1.25\n";
      break;

   case 3:
      out << "Shake: $1.50\n";
      break;

   default:
      out << "Invalid choice.";
      break;
   }

   return out.str();
}


TEST(Chapter2, Exercise7) {
   
   EXPECT_EQ("Fries: $0.99\n", Menu(1));
   EXPECT_EQ("Burger: $1.25\n", Menu(2));
   EXPECT_EQ("Shake: $1.50\n", Menu(3));
   EXPECT_EQ("Invalid choice.", Menu(4));
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 2 : Exercise 9

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
   std::ostringstream out;
   while (false)
   {
      out << "Hello World!";
   }

   return out.str();
}


TEST(Chapter2, Exercise9) {
   
   EXPECT_EQ("", WhileLoop());
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
   std::ostringstream out;

   do
   {
      out << "Hello World!";
   } while (false);


   return out.str();
}


TEST(Chapter2, Exercise9) {
   
   EXPECT_EQ("Hello World!", WhileLoop());
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 2 : Exercise 10

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string ForLoop() {
   std::ostringstream out;

   for (int i = 0; i < 5; ++i)
   {
      out << i;
   }


   return out.str();
}


TEST(Chapter2, Exercise10) {
   
   EXPECT_EQ("01234", ForLoop());
}
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 2 : Exercise 11

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
   std::ostringstream out;

   int count = 0;

   while (count < 5)
   {
      ++count;
      out << "\n" << count;
   }
   return out.str();
}

TEST(Chapter2, Exercise11) {
   
   EXPECT_EQ("\n1\n2\n3\n4\n5", WhileLoop());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

Chapter 2 : Activity 1

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Loop(int multiple, int count) {
   std::ostringstream out;
   int numbersPrinted = 0;

   for (int i = 1; i <= 100; ++i)
   {
      if (numbersPrinted == count)
      {
         break;
      }

      if (i % multiple != 0)
      {
         continue;
      }
      out << i << "\n";
      ++numbersPrinted;
   }
   return out.str();
}

TEST(Chapter2, Activity1) {

   EXPECT_EQ("4\n8\n12\n16\n20\n24\n28\n32\n36\n40\n", Loop(4, 10));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 2 : Activity 2

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string GuessNumber(int guess, int minNumber, int maxNumber) {
   std::ostringstream out;

   int randomNumber = 0;
   // Generate random number within range.
   srand((unsigned)time(0));
   randomNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

   if (guess == randomNumber)
   {
      out << "Well done, you guessed the number!\n";
      return out.str();
   }

   out << "Your guess was too " << (guess < randomNumber ? "low. " : "high. ");

   return out.str();
}

TEST(Chapter2, Activity2) {

   EXPECT_EQ("Your guess was too high. ", GuessNumber (11, 10, 12));
   EXPECT_EQ("Well done, you guessed the number!\n", GuessNumber (11, 10, 11));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}
