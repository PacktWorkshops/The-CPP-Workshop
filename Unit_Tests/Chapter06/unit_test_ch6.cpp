Chapter 6 : Exercise 1 

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Pointer(bool checkAddress) {
   std::ostringstream out;
   int* pint = nullptr;
   pint = new int;
   if(checkAddress) out << "pint = " << pint << endl;
   delete pint;
   if (checkAddress) out << "pint = " << pint << endl;

   pint = new int{ 33333 };
   out << "*pint = " << *pint << endl;
   delete pint;

   return out.str();
}

TEST(Chapter6, Exercise1) {

   EXPECT_EQ("*pint = 33333\n", Pointer(false));
   EXPECT_EQ("*pint = 33333\n", Pointer(true));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 2

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class noisy
{
   int i_;
public:
   noisy(int i) : i_(i)
   {
      out << "constructing noisy " << i << endl;
   }
   ~noisy()
   {
      out << "destroying noisy " << i_ << endl;
   }
};
std::string ClassDynamicCreation () {
   
   noisy N(1);
   noisy* p = new noisy(2);
   delete p;
   return out.str();
}

TEST(Chapter6, Exercise2) {

   EXPECT_EQ("constructing noisy 1\nconstructing noisy 2\ndestroying noisy 2\n", ClassDynamicCreation());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 3

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string ArrayDynamicCreation () {
   std::ostringstream out;

   char const* cp = "arbitrary null terminated text string";
   char* buffer = new char[strlen(cp) + 1];
   strcpy(buffer, cp);
   out << "buffer = " << buffer << endl;
   delete[] buffer;

   return out.str();
}

TEST(Chapter6, Exercise3) {

   EXPECT_EQ("buffer = arbitrary null terminated text string\n", ArrayDynamicCreation());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}


Chapter 6 : Exercise 4

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};

std::string DynamicArrayOfClass () {

   out << "getting a noisy array" << endl;
   noisy* pnoisy = new noisy[3];
   out << "deleting noisy array" << endl;
   delete[] pnoisy;
   return out.str();
}

TEST(Chapter6, Exercise4) {

   EXPECT_EQ("getting a noisy array\nconstructing noisy\nconstructing noisy\nconstructing noisy\ndeleting noisy array\ndestroying noisy\ndestroying noisy\ndestroying noisy\n", DynamicArrayOfClass());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 6

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out;

   char* p = new char[10];
   p[0] = '!';
   delete[] p;
   out << "p[0] = " << p[0] << endl;
   
   return out.str();
}

TEST(Chapter6, Exercise6) {

   EXPECT_EQ("p[0] = \xDD\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 7

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase () {
   std::ostringstream out;

   char* p = new char[10];
   p[0] = '!';
   out << "p[0] = " << p[0] << endl;
   
   return out.str();
}

TEST(Chapter6, Exercise7) {

   EXPECT_EQ("p[0] = !", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 8

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class noisy
{
   int i_;
public:
   noisy(int i) : i_(i)
   {
      out << "constructing noisy " << i << endl;
   }
   ~noisy()
   {
      out << "destroying noisy " << i_ << endl;
   }
};

std::string TestCase () {
   noisy N(1);
   noisy* p = new noisy(2);
   p = new noisy(3);
   delete p;

   return out.str();
}

TEST(Chapter6, Exercise8) {

   EXPECT_EQ("constructing noisy 1\nconstructing noisy 2\nconstructing noisy 3\ndestroying noisy 3\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 11

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct noisy
{
   noisy() { out << "constructing noisy" << endl; }
   ~noisy() { out << "destroying noisy" << endl; }
};


std::string TestCase () {
   noisy* p = new noisy;
   delete[] p;
   return out.str();
}

TEST(Chapter6, Exercise11) {

   EXPECT_EQ("constructing noisy 1\nconstructing noisy 2\nconstructing noisy 3\ndestroying noisy 3\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Exercise 12

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct numeric_item
{
   int value_;
   numeric_item* next_;
};

numeric_item* head = nullptr;

void add(int v, numeric_item** pp)
{
   numeric_item* newp = new numeric_item;
   newp->value_ = v;
   newp->next_ = *pp;
   *pp = newp;
}

numeric_item** find(int v, numeric_item** pp)
{
   while ((*pp) != nullptr && (*pp)->value_ != v)
   {
      pp = &((*pp)->next_);
   }
   return pp;
}

void print()
{
   for (numeric_item* p = head; p != nullptr; p = p->next_)
   {
      out << p->value_ << " ";
   }
   out << endl;
}
std::string TestCase () {
   for (int i = 1; i < 10; i = i + 2)
   {
      add(i, &head);
   }
   print();

   numeric_item** pp;
   pp = find(7, &head);
   add(8, pp);
   print();

   add(0, find(-1, &head));
   print();

   while (head != nullptr)
   {
      numeric_item* p = head;
      head = head->next_;
      out << "deleting " << p->value_ << endl;
      delete p;
   }

   return out.str();
}

TEST(Chapter6, Exercise12) {

   EXPECT_EQ("9 7 5 3 1 \n9 8 7 5 3 1 \n9 8 7 5 3 1 0 \ndeleting 9\ndeleting 8\ndeleting 7\ndeleting 5\ndeleting 3\ndeleting 1\ndeleting 0\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}

Chapter 6 : Activity 1

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct numeric_tree
{
   int value_;
   numeric_tree* left_;
   numeric_tree* right_;
};

numeric_tree* root = nullptr;

void add(int v, numeric_tree** pp)
{
   *pp = new numeric_tree;
   (*pp)->value_ = v;
   (*pp)->left_ = (*pp)->right_ = nullptr;
}

void delete_tree(numeric_tree* item)
{
   if (item == nullptr)
   {
      return;
   }
   else
   {
      delete_tree(item->left_);
      delete_tree(item->right_);
      out << "deleting " << item->value_ << endl;
      delete item;
   }
}

numeric_tree** find(int v, numeric_tree** pp)
{
   if (*pp == nullptr)
   {
      return pp;
   }
   else if (v < (*pp)->value_)
   {
      return find(v, &((*pp)->left_));
   }
   else
   {
      return find(v, &((*pp)->right_));
   }
}

void print(numeric_tree* item)
{
   if (item == nullptr)
   {
      return;
   }
   else
   {
      print(item->left_);
      out << item->value_ << " ";
      print(item->right_);
   }
}

std::string TestCase () {
   int insert_order[]{ 4, 2, 1, 3, 6, 5 };
   for (int i = 0; i < 6; ++i)
   {
      int v = insert_order[i];
      add(v, find(v, &root));
   }

   print(root);
   out << endl;

   delete_tree(root);

   return out.str();
}

TEST(Chapter6, Acitivity1) {

   EXPECT_EQ("1 2 3 4 5 6 \ndeleting 1\ndeleting 3\ndeleting 2\ndeleting 5\ndeleting 6\ndeleting 4\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}
