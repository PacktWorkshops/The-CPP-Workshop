Chapter 11 : Exercise 1 
 
#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
template<typename T, typename U>
class Position
{
public:

   Position(T x, T y, U zRot)
   {
      m_x = x;
      m_y = y;
      m_zRotation = zRot;
   }

   T const getX() { return m_x; }
   T const getY() { return m_y; }
   U const getZRotation() { return m_zRotation; }

private:

   T m_x;
   T m_y;

   U m_zRotation;
};

std::string TestCase() {
   Position<int, float> intPosition(1, 3, 80.0f);
   Position<float, int> floatPosition(1.0f, 3.0f, 80);
   Position<long, float> longPosition(1.0, 3.0, 80.0f);

   out << "type: " << typeid(intPosition.getX()).name() << " X: " << intPosition.getX() << " Y: " << intPosition.getY() << endl;
   out << "type: " << typeid(floatPosition.getX()).name() << " X: " << floatPosition.getX() << " Y: " << floatPosition.getY() << endl;
   out << "type: " << typeid(longPosition.getX()).name() << " X: " << longPosition.getX() << " Y: " << longPosition.getY() << endl;

   out << "type: " << typeid(intPosition.getZRotation()).name() << " Z Rot: " << intPosition.getZRotation() << endl;
   out << "type: " << typeid(floatPosition.getZRotation()).name() << " Z Rot: " << floatPosition.getZRotation() << endl;
   out << "type: " << typeid(longPosition.getZRotation()).name() << " Z Rot: " << longPosition.getZRotation() << endl;

   return out.str();
}

TEST(Chapter11, Exercise1) {

   EXPECT_EQ("type: int X: 1 Y: 3\ntype: float X: 1 Y: 3\ntype: long X: 1 Y: 3\ntype: float Z Rot: 80\ntype: int Z Rot: 80\ntype: float Z Rot: 80\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 11 : Exercise 2 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
template<typename T, typename U>
class Position
{
public:

   Position(T x, T y, U zRot)
   {
      m_x = x;
      m_y = y;
      m_zRotation = zRot;
   }

   T const getX() { return m_x; }
   T const getY() { return m_y; }
   U const getZRotation() { return m_zRotation; }

private:

   T m_x;
   T m_y;

   U m_zRotation;
};
template<typename T>
T getLargest(T t1, T t2)
{
   if (t1 > t2)
   {
      return t1;
   }
   else
   {
      return t2;
   }
}

std::string TestCase() {
   Position<int, float> intPosition(1, 3, 80.0f);
   Position<float, int> floatPosition(2.0f, 3.0f, 80);
   Position<long, float> longPosition(5.0, 3.0, 200.0);

   out << "largest is: " << getLargest(intPosition.getX(), intPosition.getY()) << endl;
   out << "largest is: " << getLargest(floatPosition.getX(), floatPosition.getY()) << endl;
   out << "largest is: " << getLargest(longPosition.getX(), longPosition.getY()) << endl;
   out << "largest ZRot is:" << getLargest(intPosition.getZRotation(), longPosition.getZRotation()) << endl;

   return out.str();
}

TEST(Chapter11, Exercise2) {

   EXPECT_EQ("largest is: 3\nlargest is: 3\nlargest is: 5\nlargest ZRot is:200\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
