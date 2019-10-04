Chapter 12 : Exercise 1

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

std::string TestCase() {
   string str;
   string str1("Hello, I'm a string!");
   string str2(str1);
   string str3(str1, 0, 5);
   string str4("Hello, I'm a string!", 0, 5);
   string str5(10, 'x');
   string str6(str4.begin() + 1, str4.end() - 1);

   out << str << endl;
   out << str1 << endl;
   out << str2 << endl;
   out << str3 << endl;
   out << str4 << endl;
   out << str5 << endl;
   out << str6 << endl;

   return out.str();
}

TEST(Chapter12, Exercise1) {

   EXPECT_EQ("\nHello, I'm a string!\nHello, I'm a string!\nHello\nHello\nxxxxxxxxxx\nell\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 12 : Exercise 2 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

bool isPalindrome(const string& str)
{
   // make a copy of the string
   string s(str.begin(), str.end());

   // remove any spaces or punctuation
   s.erase(remove_if(s.begin(), s.end(), [](const char& c) { return ispunct(c) || isspace(c); }), s.end());
   // lower case what's left
   transform(s.begin(), s.end(), s.begin(), ::tolower);
   // create a reversed version of the string
   string sr(s.rbegin(), s.rend());

   // compare them
   return (s == sr);
}

std::string TestCase() {
   string str = "Never odd or even";

   out << "'" << str << "'" << " is a palindrome? " << (isPalindrome(str) ? "YES" : "NO") << endl;

   return out.str();
}

TEST(Chapter12, Exercise2) {

   EXPECT_EQ("'Never odd or even' is a palindrome? YES\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 12 : Exercise 3
 
#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

std::string TestCase() {
   vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };

   for (auto v : vec)
   {
      out << v << " ";
   }

   out << vec[3];

   return out.str();
}

TEST(Chapter12, Exercise3) {

   EXPECT_EQ("1 2 3 4 5 6 7 8 9 10 4", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 12 : Exercise 4
#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class Track
{
public:

   Track(float length, string name, int popularity) : m_trackLength(length), m_trackName(name), m_popularityRating(popularity) {}

   float getLength() const { return m_trackLength; }
   string getName() const { return m_trackName; }
   int getPopularity() const { return m_popularityRating; }

private:

   float m_trackLength;
   string m_trackName;
   int m_popularityRating;
};
bool trackLengthCompare(const Track& t1, const Track& t2)
{
   return (t1.getLength() < t2.getLength());
}

std::string TestCase() {
   vector<Track> tracks;

   tracks.push_back(Track(199.0f, "God's Plan", 100));
   tracks.push_back(Track(227.0f, "Hold On, We're Going Home", 95));
   tracks.push_back(Track(182.0f, "The Motto", 80));

   sort(tracks.begin(), tracks.end(), trackLengthCompare);

   for (auto t : tracks)
   {
      out << t.getName() << endl;
   }

   return out.str();
}

TEST(Chapter12, Exercise4) {

   EXPECT_EQ("The Motto\nGod's Plan\nHold On, We're Going Home\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}


Chapter 12 : Exercise 5

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class Question
{
public:

   Question(int questionNumber, string question, int answerIndex) : m_questionNumber(questionNumber), m_question(question), m_answerIndex(answerIndex) {}

   int getQuestionNumber() const { return m_questionNumber; }
   string getQuestion() const { return m_question; }
   int getAnswerIndex() const { return m_answerIndex; }

private:

   int m_questionNumber;
   string m_question;
   int m_answerIndex;
};
struct QuestionCompare
{
   bool operator() (const Question& lhs, const Question& rhs) const
   {
      return lhs.getQuestionNumber() < rhs.getQuestionNumber();
   }
};

std::string TestCase(int answer) {
   map<Question, vector<string>, QuestionCompare> quiz;
   Question question1(1, "Which two actors directed themselves in movies and won Oscars for Best Actor?", 2);
   vector<string> question1Answers =
   {
      "Al Pacino and Timothy Hutton",
      "Jack Nicholson and Kevin Spacey",
      "Laurence Olivier and Roberto Benigni",
      "Tom Hanks and Paul Newman"
   };
   Question question2(2, "\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?", 0);
   vector<string> question2Answers =
   {
      "Gone With the Wind",
      "Great Expectations",
      "Harold and Maude",
      "The Matrix"
   };

   quiz.insert(make_pair(question1, question1Answers));
   quiz.insert(make_pair(question2, question2Answers));
   out << "Welcome to the movie quiz" << endl;
   out << "Type your answer between 1-4 and press enter:" << endl;

   map<Question, vector<string>>::iterator quizIterator = quiz.begin();

   vector<bool> correctAnswers;

   while (quizIterator != quiz.end())
   {
      out << quizIterator->first.getQuestion() << endl;

      int answerIndex = 1;
      for (auto answer : quizIterator->second)
      {
         out << answerIndex << " : " << answer << endl;
         answerIndex++;
      }

      int correctAnswer = quizIterator->first.getAnswerIndex();
      bool wasCorrect = answer - 1 == correctAnswer;

      out << (wasCorrect ? "CORRECT!" : "INCORRECT!") << " Correct answer is: " << quizIterator->second[correctAnswer] << endl;

      if (wasCorrect)
         correctAnswers.push_back(answer);

      quizIterator++;
   }

   out << "Your score was " << correctAnswers.size() << " out of " << quiz.size() << endl;
   out << "done";

   return out.str();
}

TEST(Chapter12, Exercise5) {

   EXPECT_EQ("Welcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nINCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 0 out of 2\ndone", TestCase(2));
   EXPECT_EQ("Welcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nINCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 0 out of 2\ndoneWelcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 1 out of 2\ndone", TestCase(3));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
Chapter 12 : Exercise 6 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 
class Person
{
public:

   Person(string name, int age)
   {
      m_name = name;
      m_age = age;
   }

   string getName() const { return m_name; }
   int getAge() const { return m_age; }

private:

   string m_name;
   int m_age;
};
struct customComparator
{
   bool operator() (const Person& a, const Person& b) const
   {
      return (a.getAge() > b.getAge());
   }
};

std::string TestCase() {
   set<Person, customComparator> personSet;

   Person a("bob", 35);
   Person b("bob", 25);

   personSet.insert(a);
   personSet.insert(b);

   for (auto person : personSet)
   {
      out << person.getAge() << endl;
   }

   return out.str();
}

TEST(Chapter12, Exercise6) {

   EXPECT_EQ("35\n25\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 12 : Exercise 7

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out; 

std::string TestCase() {
   set<int> intSet;
   multiset<int> intMultiset;
   for (unsigned int i = 0; i < 100; i++)
   {
      intMultiset.insert(1 + rand() % 100);
   }
   for (auto i : intMultiset)
   {
      intSet.insert(i);
   }
   out << "there are " << intSet.size() << " unique elements in the multiset";

   return out.str();
}

TEST(Chapter12, Exercise7) {

   EXPECT_EQ("there are 65 unique elements in the multiset", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
