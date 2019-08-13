#include <iostream> 
#include <cstring> 
using namespace std; 
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
        if(this != &rhs) 
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
        if(this != &rhs) 
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
        m_attacksLength = sizeof(attacks)/sizeof(&attacks[0]); 
        m_itemsLength = sizeof(items)/sizeof(&items[0]);       
        m_attacks = new Attack*[m_attacksLength]; 
        m_items = new Item*[m_itemsLength];         
        int i = 0; 
        for(i = 0; i < m_attacksLength; i++) 
        { 
            Attack* attack = new Attack(attacks[i]); 
            m_attacks[0] = attack; 
        }        
        for(i = 0; i < m_itemsLength; i++) 
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
        if(this != &rhs) 
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
       cout << m_name << " attacks " << other.getName() << " with " << moveName << endl; 
       other.DoDefend(GetAttackAmount(moveName) * m_strengthMultiplier); 
    }      
    void UseItem(string itemName) 
    { 
        m_health += GetItemValue(itemName); 
    }    
    void Display() 
    { 
        cout << m_name << endl; 
        cout << "Health = " << m_health << endl; 
        cout << "Strength Multiplier = " << m_strengthMultiplier << endl; 
        cout << "Defence Multiplier = " << m_defenceMultiplier << endl; 
        cout << "Attacks:" << endl;          
        for(int i = 0; i < m_attacksLength; i++) 
            cout << m_attacks[i]->getName() << " : " << m_attacks[i]->getAttackStat() << endl; 
            cout << "Items:" << endl; 
        for(int i = 0; i < m_itemsLength; i++) 
            cout << m_items[i]->getName() << " : " << m_items[i]->getHealStat() << endl; 
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
        for(int i = 0; i < m_attacksLength; i++) 
        { 
            if(m_attacks[i]->getName() == attackName) 
            { 
                return m_attacks[i]->getAttackStat(); 
            } 
        } 
        
        return 0; 
    }    
    int GetItemValue(string itemName) 
    { 
        for(int i = 0; i < m_itemsLength; i++) 
        { 
            if(m_items[i]->getName() == itemName) 
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

int main() 
{ 
    Attack billAttacks[] = { {"Sword To The Face", 20} }; 
    Item billItems[] = { {"Old Grog", 20} };    
    Attack dragonAttacks[] = {{"Flame Breath", 50}}; 
    Item dragonItems[] = {{"Scale Oil", 20}};    
    Character bill("Bill", 10, 5, billAttacks, billItems); 
    bill.Display();     
    Character dragon("Dragon", 10, 5, dragonAttacks, dragonItems); 
    dragon.Display(); 
    bill.Display(); 
    bill.DoAttack("Sword To The Face", dragon); 
    dragon.Display(); 
    dragon.DoAttack("Flame Breath", bill); 
    bill.Display(); 
    return 0; 
} 
