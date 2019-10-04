Chapter 3 : Example 4 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

void PrintVector()
{
   std::vector<int> myVector;
   for (int i = 0; i < myVector.size(); ++i)
   {
      out << myVector[i];
   }

   out << "\n\n";
}
std::string TestCase() {
   PrintVector();
   return out.str();
}

TEST(Chapter3, Example4) {
   EXPECT_EQ("\n\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



Chapter 3 : Example 5 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
std::vector<int> myVector{ 1, 2, 3, 4, 5 };
void PrintVector()
{
   for (int i = 0; i < myVector.size(); ++i)
   {
      out << myVector[i];
   }

   out << "\n\n";
}
std::string TestCase() {
   myVector.pop_back();
   PrintVector();

   myVector.push_back(6);
   PrintVector();

   myVector.erase(myVector.begin() + 1);
   PrintVector();

   myVector.insert(myVector.begin() + 3, 8);
   PrintVector();

   return out.str();
}

TEST(Chapter3, Example5) {
   EXPECT_EQ("1234\n\n12346\n\n1346\n\n13486\n\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}




Chapter 3 : Example 6 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
   MyClass()
   {
      out << "My Class Constructor Called\n";
      myPublicInt = 5;
   }

   int myPublicInt = 0;    
   ~MyClass()
   {
      out << "My Class Destructor Called\n";
   }
};

std::string TestCase() { 
   {
      out << "Application started\n";

      MyClass testClass;

      out << testClass.myPublicInt << "\n";
   }
   return out.str();
}

TEST(Chapter3, Example6) {
   EXPECT_EQ("Application started\nMy Class Constructor Called\n5\nMy Class Destructor Called\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}




Chapter 3 : Example 7 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
   int myInt = 0;
   bool myBool = false;

   std::string GetString()
   {
      return "Hello World!";
   }
};

struct MyStruct
{
   int myInt = 0;
   int myBool = 0;

   std::string GetString()
   {
      return "Hello World!";
   }
};

std::string TestCase() {
   MyClass classObject;
   out << "classObject::myInt: " << classObject.myInt << "\n";
   out << "classObject::myBool: " << classObject.myBool << "\n";
   out << "classObject::GetString: " << classObject.GetString() << "\n";

   MyStruct structObject;
   out << "\nstructObject::myInt: " << structObject.myInt << "\n";
   out << "structObject::myBool: " << structObject.myBool << "\n";
   out << "structbject::GetString: " << structObject.GetString() << "\n";

   return out.str();
}

TEST(Chapter3, Example7) {
   EXPECT_EQ("classObject::myInt: 0\nclassObject::myBool: 0\nclassObject::GetString: Hello World!\n\nstructObject::myInt: 0\nstructObject::myBool: 0\nstructbject::GetString: Hello World!\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



Chapter 3 : Example 8 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

int MyInt()
{
   int myInt = 0;
   return ++myInt;
}

std::string TestCase() {
   for (int i = 0; i < 5; ++i)
   {
      out << MyInt();
   }
   return out.str();
}

TEST(Chapter3, Example8) {
   EXPECT_EQ("11111", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}





Chapter 3 : Activity 


#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
struct Person
{
   int age = 0;
   std::string name = "";
};

std::vector<Person> records;

void AddRecord(std::string newName, int newAge)
{
   Person newRecord;
   newRecord.name = newName;
   newRecord.age = newAge;

   records.push_back(newRecord);
};

Person FetchRecord(int userID)
{
   return records.at(userID);
};


std::string TestCase(std::string inputString, std::string name, std::string age) {

   std::ostringstream out;
   // Determine user selection.
   switch (std::stoi(inputString))
   {
   case 1:
   {
      AddRecord(name, std::stoi(age));
   }
   break;

   case 2:
   {
      int userID = 0;
      userID = std::stoi(name);

      Person person;
      try
      {
         person = FetchRecord(userID);
      }
      catch (const std::out_of_range& oor) {
         out << "\nError: Invalid UserID.\n\n";
         break;
      }

      out << "User Name: " << person.name << "\n";
      out << "User Age: " << person.age << "\n\n";
   }
   break;
   
   default:
      out << "\n\nError: Invalid option selection.\n\n";
      break;
   }
   return out.str();
}

TEST(Chapter3, Activity) {

   EXPECT_EQ("", TestCase("1", "Mukesh", "28"));
   EXPECT_EQ("", TestCase("1", "Rakesh", "40"));
   EXPECT_EQ("", TestCase("1", "Prakash", "12"));
   EXPECT_EQ("User Name: Prakash\nUser Age: 12\n\n", TestCase("2", "2", ""));
   EXPECT_EQ("User Name: Mukesh\nUser Age: 28\n\n", TestCase("2", "0", ""));
   EXPECT_EQ("\n\nError: Invalid option selection.\n\n", TestCase("5", "Prakash", "12"));
   EXPECT_EQ("\nError: Invalid UserID.\n\n", TestCase("2", "10", ""));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
