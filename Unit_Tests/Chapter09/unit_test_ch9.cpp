Chapter 9 : Exercise 2

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

   // declare a constant value for maximum track length
   const float MAX_TRACK_LENGTH = 600.0f;

   Track(float lengthInSeconds, string trackName)
   {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
   }

   float getLength() { return m_lengthInSeconds; }
   string getName() { return m_trackName; }

   void setName(string newTrackName)
   {
      // if S-Club is not found set the track name - otherwise do nothing
      if (newTrackName.find("S-Club") == string::npos)
      {
         m_trackName = newTrackName;
      }
   }

   void setLength(float newTrackLength)
   {
      if (newTrackLength < MAX_TRACK_LENGTH && newTrackLength > 0) // no prog metal for us!
      {
         m_lengthInSeconds = newTrackLength;
      }
   }

private:

   float m_lengthInSeconds;
   string m_trackName;
};

std::string TestCase() {
   // create
   Track t(260.0f, "Still Alive");

   out << "My Favourite Song is: " << t.getName() << endl;
   out << "It is :" << t.getLength() / 60.0f << " minutes long" << endl;

   t.setName("S-Club Party"); // this again!
   t.setLength(315576000000.0f); // 10 milennia

   out << "My Favourite Song is: " << t.getName() << endl;
   out << "It is :" << t.getLength() / 60.0f << " minutes long";

   return out.str();
}

TEST(Chapter9, Exercise2) {

   EXPECT_EQ("My Favourite Song is: Still Alive\nIt is :4.33333 minutes long\nMy Favourite Song is: Still Alive\nIt is :4.33333 minutes long", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



Chapter 9 : Exercise 3

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include <cmath>
using namespace std;

std::ostringstream out;
class Position
{
public:
   Position(float x, float y) : m_x(x), m_y(y) {}

   float distance(float x, float y)
   {
      float xDiff = x - m_x;
      float yDiff = y - m_y;

      return std::sqrt(((xDiff * xDiff) + (yDiff * yDiff)));
   }
   float getX() { return m_x; }
   float getY() { return m_y; }

   void setX(float x) { m_x = x; }
   void setY(float y) { m_y = y; }

private:

   float m_x;
   float m_y;
};

std::string TestCase() {
   float maxDistance = 500.0f;

   Position pos(10.0f, 20.0f);
   Position pos2(100.0f, 200.0f);

   bool validDistance = true;
   int numberOfTimesMoved = 0;

   while (validDistance)
   {
      float distance = pos.distance(pos2.getX(), pos2.getY());

      if (distance > maxDistance)
      {
         validDistance = false;
         break;
      }
      // get direction
      float xDirection = pos2.getX() - pos.getX();
      float yDirection = pos2.getY() - pos.getY();

      // normalize
      float normalizedX = xDirection / distance;
      float normalizedY = yDirection / distance;

      pos.setX(pos.getX() - normalizedX);
      pos.setY(pos.getY() - normalizedY);

      numberOfTimesMoved++;
   }

   out << "Too far apart." << " Moved " << numberOfTimesMoved << " times";

   return out.str();
}

TEST(Chapter9, Exercise3) {

   EXPECT_EQ("Too far apart. Moved 299 times", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}

Chapter 9 : Activity 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Attack
{
public:

   Attack(const char* name, int attackStat)
   {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_attackStat = attackStat;
   }

   Attack(const Attack& other)
   {
      m_attackStat = other.m_attackStat;

      m_name = new char[strlen(other.m_name) + 1];
      strcpy(m_name, other.m_name);
   }

   Attack& operator=(const Attack& rhs)
   {
      if (this != &rhs)
      {
         m_attackStat = rhs.m_attackStat;

         char* newName = new char[strlen(rhs.m_name) + 1];
         strcpy(newName, rhs.m_name);

         delete[] m_name;

         m_name = newName;
      }

      return *this;
   }


   ~Attack()
   {
      delete[] m_name;
   }

   int getAttackStat() const { return m_attackStat; }
   char* getName() const { return m_name; }

private:

   char* m_name;
   int m_attackStat;
};

class Item
{
public:

   Item(const char* name, int healStat)
   {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_healStat = healStat;
   }

   Item(const Item& other)
   {
      m_healStat = other.m_healStat;

      m_name = new char[strlen(other.m_name) + 1];
      strcpy(m_name, other.m_name);
   }

   Item& operator=(const Item& rhs)
   {
      if (this != &rhs)
      {
         m_healStat = rhs.m_healStat;

         char* newName = new char[strlen(rhs.m_name) + 1];
         strcpy(newName, rhs.m_name);

         delete[] m_name;
         m_name = newName;
      }

      return *this;
   }

   ~Item()
   {
      delete[] m_name;
   }

   int getHealStat() const { return m_healStat; }
   char* getName() const { return m_name; }

private:

   char* m_name;
   int m_healStat;

};

class Character
{
public:

   Character(const char* name, int strengthMultiplier, int defenceMultiplier, Attack* attacks, Item* items)
   {
      m_health = 100;

      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_strengthMultiplier = strengthMultiplier;
      m_defenceMultiplier = defenceMultiplier;

      m_attacksLength = sizeof(attacks) / sizeof(&attacks[0]);
      m_itemsLength = sizeof(items) / sizeof(&items[0]);

      m_attacks = new Attack*[m_attacksLength];
      m_items = new Item*[m_itemsLength];

      int i = 0;
      for (i = 0; i < m_attacksLength; i++)
      {
         Attack* attack = new Attack(attacks[i]);
         m_attacks[0] = attack;
      }

      for (i = 0; i < m_itemsLength; i++)
      {
         Item* item = new Item(items[i]);
         m_items[0] = item;
      }
   }

   Character(const Character& other)
   {
      m_health = other.m_health;
      m_strengthMultiplier = other.m_strengthMultiplier;
      m_defenceMultiplier = other.m_defenceMultiplier;

      m_attacksLength = other.m_attacksLength;
      m_itemsLength = other.m_itemsLength;

      m_name = new char[strlen(other.m_name) + 1];
      strcpy(m_name, other.m_name);

      m_attacks = new Attack*[m_attacksLength];
      m_items = new Item*[m_itemsLength];

      memcpy(m_attacks, other.m_attacks, sizeof(Attack) * m_attacksLength);
      memcpy(m_items, other.m_items, sizeof(Item) * m_itemsLength);
   }

   Character& operator=(const Character& rhs)
   {
      if (this != &rhs)
      {
         m_health = rhs.m_health;
         m_strengthMultiplier = rhs.m_strengthMultiplier;
         m_defenceMultiplier = rhs.m_defenceMultiplier;

         m_attacksLength = rhs.m_attacksLength;
         m_itemsLength = rhs.m_itemsLength;

         char* newName = new char[strlen(rhs.m_name) + 1];
         strcpy(newName, rhs.m_name);

         delete[] m_name;
         m_name = newName;

         Attack** newAttacks = new Attack*[m_attacksLength];
         Item** newItems = new Item*[m_itemsLength];

         memcpy(newAttacks, rhs.m_attacks, sizeof(Attack) * m_attacksLength);
         memcpy(newItems, rhs.m_items, sizeof(Item) * m_itemsLength);

         delete[] m_attacks;
         delete[] m_items;

         m_attacks = newAttacks;
         m_items = newItems;
      }

      return *this;
   }


   ~Character()
   {
      delete[] m_name;
      delete[] m_attacks;
      delete[] m_items;
   }

   const char* getName() { return m_name; }

   void DoAttack(string moveName, Character& other)
   {
      out << m_name << " attacks " << other.getName() << " with " << moveName << endl;
      other.DoDefend(GetAttackAmount(moveName) * m_strengthMultiplier);
   }

   void UseItem(string itemName)
   {
      m_health += GetItemValue(itemName);
   }

   void Display()
   {
      out << m_name << endl;
      out << "Health = " << m_health << endl;
      out << "Strength Multiplier = " << m_strengthMultiplier << endl;
      out << "Defence Multiplier = " << m_defenceMultiplier << endl;
      out << "Attacks:" << endl;

      for (int i = 0; i < m_attacksLength; i++)
         out << m_attacks[i]->getName() << " : " << m_attacks[i]->getAttackStat() << endl;

      out << "Items:" << endl;
      for (int i = 0; i < m_itemsLength; i++)
         out << m_items[i]->getName() << " : " << m_items[i]->getHealStat() << endl;
   }


private:

   void DoDefend(int attackValue)
   {
      int damage = attackValue / m_defenceMultiplier;
      m_health -= damage;

      out << m_name << " takes " << damage << " damage" << endl;
   }

   int GetAttackAmount(string attackName)
   {
      for (int i = 0; i < m_attacksLength; i++)
      {
         if (m_attacks[i]->getName() == attackName)
         {
            return m_attacks[i]->getAttackStat();
         }
      }

      return 0;
   }

   int GetItemValue(string itemName)
   {
      for (int i = 0; i < m_itemsLength; i++)
      {
         if (m_items[i]->getName() == itemName)
         {
            return m_items[i]->getHealStat();
         }
      }

      return 0;
   }

   char* m_name;
   Attack** m_attacks;
   Item** m_items;
   int m_health;
   int m_strengthMultiplier;
   int m_defenceMultiplier;

   int m_attacksLength;
   int m_itemsLength;
};

std::string TestCase() {
   Attack billAttacks[] = { { "Sword To The Face", 20 } };
   Item billItems[] = { { "Old Grog", 20 } };

   Attack dragonAttacks[] = { { "Flame Breath", 50 } };
   Item dragonItems[] = { { "Scale Oil", 20 } };

   Character bill("Bill", 10, 5, billAttacks, billItems);
   bill.Display();

   Character dragon("Dragon", 10, 5, dragonAttacks, dragonItems);
   dragon.Display();

   bill.Display();

   bill.DoAttack("Sword To The Face", dragon);

   dragon.Display();

   dragon.DoAttack("Flame Breath", bill);

   bill.Display();

   return out.str();
}

TEST(Chapter9, Activity) {

   EXPECT_EQ("Bill\nHealth = 100\nStrength Multiplier = 10\nDefence Multiplier = 5\nAttacks:\nSword To The Face : 20\nItems:\nOld Grog : 20\nDragon\nHealth = 100\nStrength Multiplier = 10\nDefence Multiplier = 5\nAttacks:\nFlame Breath : 50\nItems:\nScale Oil : 20\nBill\nHealth = 100\nStrength Multiplier = 10\nDefence Multiplier = 5\nAttacks:\nSword To The Face : 20\nItems:\nOld Grog : 20\nBill attacks Dragon with Sword To The Face\nDragon takes 40 damage\nDragon\nHealth = 60\nStrength Multiplier = 10\nDefence Multiplier = 5\nAttacks:\nFlame Breath : 50\nItems:\nScale Oil : 20\nDragon attacks Bill with Flame Breath\nBill takes 100 damage\nBill\nHealth = 0\nStrength Multiplier = 10\nDefence Multiplier = 5\nAttacks:\nSword To The Face : 20\nItems:\nOld Grog : 20\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
