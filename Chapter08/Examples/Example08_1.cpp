#include <iostream>

using namespace std;

union Backpack
{
   int contents[4];
   struct
   {
       int food, water, key, flashlight;
   } 
   data;
};

void DisplayContents(Backpack& backpack)
{
   cout << "Has Food = " << backpack.data.food << endl;
   cout << "Has Water = " << backpack.data.water << endl;
   cout << "Has Key = " << backpack.data.key << endl;
   cout << "Has Flashlight = " << backpack.data.flashlight << endl;
}

void UpdateBackpack(Backpack& backpack, int contents[4])
{
   for(int i = 0; i < 4; i++)
   {
       backpack.contents[i] = contents[i] > backpack.contents[i]
       ? contents[i] : backpack.contents[i];
   }
}

void RemoveFromBackpack(Backpack& backpack, int idx)
{
   backpack.contents[idx] = 0;
}

int main()
{
   Backpack backpack;
  
   int defaultContents[4] = {1,1,0,0};
   int firstRoomContents[4] = {0,0,0,1};
   int secondRoomContents[4] = {0,0,1,0};
  
   for(int i = 0; i < 4; i++)
   {
       backpack.contents[i] = defaultContents[i];
   }
  
   DisplayContents(backpack);
  
   cout << "You enter the first room" << endl;
  
   UpdateBackpack(backpack, firstRoomContents);
  
   DisplayContents(backpack);
  
   cout << "You eat some food before continuing" << endl;
  
   RemoveFromBackpack(backpack, 0); // food is index 0
  
   DisplayContents(backpack);
  
   cout << "You enter the second room" << endl;
  
   UpdateBackpack(backpack, secondRoomContents);
  
   DisplayContents(backpack);
  
   return 0;
}
