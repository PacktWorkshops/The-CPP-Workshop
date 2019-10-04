Chapter 10 : Exercise 4.1

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Shape
{
public:
   int area = 10;
   int GetArea() { return area; }
};

class Square : public Shape
{
};

class Circle : public Shape
{
};

class Triangle : public Shape
{
};

std::string TestCase() {
   Square mySquare;
   Circle myCircle;
   Triangle myTriangle;
   mySquare.area = 5;
   out << "Square Area: " << mySquare.GetArea() << std::endl;

   myCircle.area = 15;
   out << "Circle Area: " << myCircle.GetArea() << std::endl;

   return out.str();
}

TEST(Chapter10, Exercise1) {

   EXPECT_EQ("Square Area: 5\nCircle Area: 15\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 10: Exercise 4.2

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

class Color
{
public:
   std::string color = "";
   std::string GetColor() { return color; }
};
class Shape
{
public:
   int area = 10;
   int GetArea() { return area; }
};

class Square : public Shape, public Color
{
};
class Circle : public Shape, public Color
{
};
class Triangle : public Shape, public Color
{
};

std::string TestCase() {
   Square mySquare;
   Circle myCircle;
   Triangle myTriangle;

   mySquare.area = 5;
   mySquare.color = "red";
   out << "Square Area: " << mySquare.GetArea() << std::endl;
   out << "Square Color: " << mySquare.GetColor() << std::endl;

   myCircle.area = 10;
   myCircle.color = "blue";
   out << "Circle Area: " << myCircle.GetArea() << std::endl;
   out << "Circle Area: " << myCircle.GetColor() << std::endl;

   myTriangle.area = 15;
   myTriangle.color = "green";
   out << "Triangle Area: " << myTriangle.GetArea() << std::endl;
   out << "Triangle Color: " << myTriangle.GetColor() << std::endl;

   return out.str();
}

TEST(Chapter10, Exercise2) {

   EXPECT_EQ("Square Area: 5\nSquare Color: red\nCircle Area: 10\nCircle Area: blue\nTriangle Area: 15\nTriangle Color: green\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 10 : Exercise 4.3 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

class MyBaseClass
{
public:
   virtual void PrintMessage()
   {
      out << "Hello ";
   }
};

class MyDerivedClass : public MyBaseClass
{
public:
   void PrintMessage() override
   {
      out << "World!";
   }
};

std::string TestCase() {
   MyDerivedClass obj;
   obj.PrintMessage();

   return out.str();
}

TEST(Chapter10, Exercise3) {

   EXPECT_EQ("World!", TestCase());
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

class MyBaseClass
{
public:
   virtual void PrintMessage()
   {
      out << "Hello ";
   }
};

class MyDerivedClass : public MyBaseClass
{
public:
   void PrintMessage() override
   {
      MyBaseClass::PrintMessage();
      out << "World!";
   }
};

std::string TestCase() {
   MyDerivedClass obj;
   obj.PrintMessage();

   return out.str();
}

TEST(Chapter10, Exercise3) {

   EXPECT_EQ("Hello World!", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 10 : Exercise 4.4 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

class Shape
{
public:
   virtual int CalculateArea() = 0;

protected:
   int area = 0;
};
class Square : public Shape
{
public:
   int height = 0;

   int CalculateArea() override
   {
      area = height * height;
      return area;
   }
};
class Circle : public Shape
{
public:
   int radius = 0;

   int CalculateArea() override
   {
      area = 3.14 * (radius * radius);
      return area;
   }
};

std::string TestCase() {
   Square square;
   square.height = 10;
   out << "Square Area: " << square.CalculateArea() << std::endl;

   Circle circle;
   circle.radius = 10;
   out << "Circle Area: " << circle.CalculateArea() << std::endl;

   return out.str();
}

TEST(Chapter10, Exercise4) {

   EXPECT_EQ("Square Area: 100\nCircle Area: 314\n", TestCase());
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

class MyClassA
{
public:
   virtual std::string GetString() = 0;
};

class MyClassB : public MyClassA
{
public:
   std::string GetString() override
   {
      return "Hello ";
   }
};

class MyClassC : public MyClassA
{
public:
   std::string GetString() override
   {
      return " world!";
   }
};

std::string TestCase() {
   MyClassA* myClass = new MyClassB();
   out << myClass->GetString();

   myClass = new MyClassC();
   out << myClass->GetString();

   return out.str();
}

TEST(Chapter10, Exercise4) {

   EXPECT_EQ("Hello  world!", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 10 : Exercise 4.5 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 


class Shape
{
public:
   virtual int CalculateArea() = 0;

protected:
   int area = 0;
};

class Square : public Shape
{
public:
   int height = 10;

   int CalculateArea() override
   {
      area = height * height;
      return area;
   }
};

class Circle : public Shape
{
public:
   int radius = 10;

   int CalculateArea() override
   {
      area = 3.14 * (radius * radius);
      return area;
   }
};


std::string TestCase() {
   Shape* square = new Square();
   Shape* circle = new Circle();

   out << "Square Area: " << square->CalculateArea() << std::endl;
   out << "Circle Area: " << circle->CalculateArea() << std::endl;

   delete square;
   square = nullptr;

   delete circle;
   circle = nullptr;

   return out.str();
}

TEST(Chapter10, Exercise5) {

   EXPECT_EQ("Square Area: 100\nCircle Area: 314\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}





Chapter 10 : Exercise 4.6

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class Shape
{
public:
   virtual int CalculateArea() = 0;

protected:
   int area = 0;
};

class Square : public Shape
{
public:
   int height = 0;

   int CalculateArea() override
   {
      area = height * height;
      return area;
   }
};

class Circle : public Shape
{
public:
   int radius = 0;

   int CalculateArea() override
   {
      area = 3.14 * (radius * radius);
      return area;
   }
};

std::string TestCase() {
   Shape* square = new Square();
   Shape* circle = new Circle();

   Square* square2 = static_cast<Square*>(square);
   square2->height = 10;

   Circle* circle2 = static_cast<Circle*>(circle);
   circle2->radius = 10;

   out << "Square Area: " << square->CalculateArea() << std::endl;
   out << "Circle Area: " << circle->CalculateArea() << std::endl;

   delete square;
   square = nullptr;

   delete circle;
   circle = nullptr;

   return out.str();
}

TEST(Chapter10, Exercise6) {

   EXPECT_EQ("Square Area: 100\nCircle Area: 314\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 10 : Activity 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
struct AnimalInfo
{
   std::string name = "";
   std::string origin = "";
   int lifeExpectancy = 0;
   float weight = 0;
};

void PrintAnimalInfo(AnimalInfo info)
{
   out << "Name: " << info.name << std::endl;
   out << "Origin: " << info.origin << std::endl;
   out << "Life Expectancy: " << info.lifeExpectancy << std::endl;
   out << "Weight: " << info.weight << std::endl;
}

class Animal
{
public:
   AnimalInfo GetAnimalInfo() const { return animalInfo; };

protected:
   AnimalInfo animalInfo;
};

class Lion final : public Animal
{
public:
   Lion()
   {
      animalInfo.name = "Lion";
      animalInfo.origin = "Africa";
      animalInfo.lifeExpectancy = 12;
      animalInfo.weight = 190;
   }
};

class Tiger final : public Animal
{
public:
   Tiger()
   {
      animalInfo.name = "Tiger";
      animalInfo.origin = "Africa";
      animalInfo.lifeExpectancy = 17;
      animalInfo.weight = 220;
   }
};

class Bear final : public Animal
{
public:
   Bear()
   {
      animalInfo.name = "Bear";
      animalInfo.origin = "Eurasia";
      animalInfo.lifeExpectancy = 22;
      animalInfo.weight = 270;
   }
};

std::string TestCase(int userChoice) {
   std::vector<Animal*> animals;
   animals.push_back(new Lion());
   animals.push_back(new Tiger());
   animals.push_back(new Bear());

   for (size_t i = 0; i < animals.size(); ++i)
   {
      out << i << ") " << animals[i]->GetAnimalInfo().name << std::endl;
   }
  
   // Sanity user input
   if (userChoice == -1)
   {
      out << "invalid userChoice \n";
      return out.str();

   }
   else if (userChoice < -1 || userChoice >((int)animals.size() - 1))
   {
      out << "\nInvalid Index. Please enter another.\n";
   }
   else
   {
      // Print animal info
      out << std::endl;
      PrintAnimalInfo(animals[userChoice]->GetAnimalInfo());
   }

   // Cleanup.
   for (size_t i = 0; i < animals.size(); ++i)
   {
      delete animals[i];
      animals[i] = nullptr;
   }
   animals.clear();

   return out.str();
}

TEST(Chapter10, Activiy) {

   EXPECT_EQ("0) Lion\n1) Tiger\n2) Bear\n\nName: Tiger\nOrigin: Africa\nLife Expectancy: 17\nWeight: 220\n", TestCase(1));
   EXPECT_EQ("0) Lion\n1) Tiger\n2) Bear\n\nName: Tiger\nOrigin: Africa\nLife Expectancy: 17\nWeight: 220\n0) Lion\n1) Tiger\n2) Bear\ninvalid userChoice \n", TestCase(-1));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
