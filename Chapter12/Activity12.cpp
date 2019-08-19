#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Attack
{
public:
    
    Attack(string name, int attackStat)
    {
        m_name = name;
        m_attackStat = attackStat;
    }
    
    int getAttackStat() const { return m_attackStat; }
    string getName() const { return m_name; }
    
private:
    
    string m_name;
    int m_attackStat;
};

class Item
{
public:
    
    Item(string name, int healStat)
    {
        m_name = name;
        m_healStat = healStat;
    }
    
    int getHealStat() const { return m_healStat; }
    string getName() const { return m_name; }
    
private:
    
    string m_name;
    int m_healStat;

};

class Character
{
public:
    
    Character(string name, int strengthMultiplier, int defenceMultiplier, vector<Attack> attacks, vector<Item> items, int indexOfDefaultAttack = 0)
    {
        m_health = 100;
        m_name = name;
        
        m_strengthMultiplier = strengthMultiplier;
        m_defenceMultiplier = defenceMultiplier;
        m_indexOfDefaultAttack = indexOfDefaultAttack;
        
        m_attacks.insert(m_attacks.begin(), attacks.begin(), attacks.end());
        m_items.insert(m_items.begin(), items.begin(), items.end());
    }
    
    string getName() const { return m_name; }
    int getHealth() const { return m_health; }
    
    void DoAttack(string moveName, Character& other)
    {
        cout << m_name << " attacks " << other.getName() << " with " << moveName << endl;
        other.DoDefend(GetAttackAmount(moveName) * m_strengthMultiplier);
    }
    
    void DoAttack(Character& other)
    {
        string attackName = m_attacks[m_indexOfDefaultAttack].getName();
        cout << m_name << " attacks " << other.getName() << " with " << attackName << endl;
        other.DoDefend(GetAttackAmount(attackName) * m_strengthMultiplier);
    }
    
    void UseItem(string itemName)
    {
        int itemValue = GetItemValue(itemName);
        cout << m_name << " uses " << itemName << " and gains " << itemValue << " health" << endl;
        m_health += itemValue;
    }
    
    bool isDead() { return m_health <= 0; }
    
    void Display()
    {
        cout << m_name << endl;
        cout << "Health = " << m_health << endl;
        cout << "Strength Multiplier = " << m_strengthMultiplier << endl;
        cout << "Defence Multiplier = " << m_defenceMultiplier << endl;
        cout << "Attacks:" << endl;
        
        for(auto attack : m_attacks)
            cout << attack.getName() << " : " << attack.getAttackStat() << endl;
        
        cout << "Items:" << endl;
        
        for(auto item : m_items)
            cout << item.getName() << " : " << item.getHealStat() << endl;
    }

    
private:
    
    void DoDefend(int attackValue)
    {
        int damage = attackValue / m_defenceMultiplier;
        m_health -= damage;
        
        cout << m_name << " takes " << damage << " damage" << endl;
    }
    
    int GetAttackAmount(string attackName)
    {
        auto it = find_if(m_attacks.begin(), m_attacks.end(), [attackName](const Attack& attack){ return attack.getName() == attackName; });
        
        return (it != m_attacks.end()) ? (*it).getAttackStat() : 0;
    }
    
    int GetItemValue(string itemName)
    {
        auto it = find_if(m_items.begin(), m_items.end(), [itemName](const Item& item){ return item.getName() == itemName; });
        
        return (it != m_items.end()) ? (*it).getHealStat() : 0;
    }
    
    string m_name;
    vector<Attack> m_attacks;
    vector<Item> m_items;
    
    int m_health;
    int m_strengthMultiplier;
    int m_defenceMultiplier;
    int m_indexOfDefaultAttack;
};


int main()
{
    // Bill the player
    vector<Attack> billAttacks = { {"Sword To The Face", 20} };
    vector<Item> billItems = { {"Old Grog", 50} };
    Character bill("Bill", 2, 2, billAttacks, billItems);
    
    // Dragon
    vector<Attack> dragonAttacks = {{"Flame Breath", 20}};
    vector<Item> dragonItems = {{"Scale Oil", 20}};
    Character dragon("Dragon", 2, 1, dragonAttacks, dragonItems);
    
    // Zombie
    vector<Attack> zombieAttacks = {{"Bite", 50}};
    vector<Item> zombieItems = {{"Rotten Flesh", 20}};
    Character zombie("Zombie", 1, 3, zombieAttacks, zombieItems);
    
    // Witch
    vector<Attack> witchAttacks = {{"Super Spell", 50}};
    vector<Item> witchItems = {{"Cure Potion", 20}};
    Character witch("Witch", 1, 5, witchAttacks, witchItems);
    
    queue<Character> monsters;
    monsters.push(dragon);
    monsters.push(zombie);
    monsters.push(witch);
    
    bool playerTurn = true; 
    bool gameOver = false;
    cout << "Bill finds himself trapped in a scary dungeon! There seems to be a series of rooms, he enters the first room..." << endl;
    while(!monsters.empty() && !gameOver)
    {
        Character currentMonster = monsters.front();
        cout << "A monster appears, it looks like a " << currentMonster.getName() << endl;
        while(!currentMonster.isDead())
        {
            cout << endl;
            if(playerTurn)
            {
                cout << "bill's turn" << endl;
                cout << "Bill can press 1 and enter to use an item and 2 and enter to attack the monster." << endl;
                
                bool madeChoice = false;
                while(!madeChoice)
                {
                    int choice;
                    cin >> choice;
                    
                    switch(choice)
                    {
                        case 1:
                            bill.UseItem("Old Grog");
                            madeChoice = true;
                            break;
                            
                        case 2:
                            bill.DoAttack(currentMonster);
                            madeChoice = true;
                            break;
                            
                        default:
                            break;
                    }
                }
            }
            else
            {
                cout << currentMonster.getName() << "'s turn" << endl;
                currentMonster.DoAttack(bill);
            }
            
            cout << "Bills health is " << bill.getHealth() << endl;
            cout << currentMonster.getName() << "'s health is " << currentMonster.getHealth() << endl;
            
            if(currentMonster.isDead())
            {
                cout << currentMonster.getName() << " is defeated" << endl;
                monsters.pop();
            }
                
            if(bill.isDead())
            {
                gameOver = true;
                break;
            }
            
            
            playerTurn = !playerTurn;
        }
    }
    
    if(monsters.empty())
    {
        cout << "You win";
    }
    
    if(gameOver)
    {
        cout << "You lose";
    }
    return 0;
}
