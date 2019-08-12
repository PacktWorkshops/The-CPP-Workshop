// Activity 11: Envyclopedia Application. 

#include <iostream> 

#include <string> 

#include <vector> 

 

struct AnimalInfo 

{ 

    std::string name = ""; 

    std::string origin = ""; 

    int lifeExpectancy = 0; 

    float weight = 0; 

}; 

 

void PrintAnimalInfo(AnimalInfo info) 

{ 

    std::cout << "Name: " << info.name << std::endl; 

    std::cout << "Origin: " << info.origin << std::endl; 

    std::cout << "Life Expectancy: " << info.lifeExpectancy << std::endl; 

    std::cout << "Weight: " << info.weight << std::endl; 

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

 

int main() 

{ 

    std::vector<Animal*> animals; 

    animals.push_back(new Lion()); 

    animals.push_back(new Tiger()); 

    animals.push_back(new Bear()); 

     

    std::cout << "**Animal Encyclopedia**\n"; 

     

    bool bIsRunning = true; 

    while (bIsRunning) 

    { 

        std::cout << "\nSelect animal for more information\n\n"; 

         

        for (size_t i = 0; i < animals.size(); ++i) 

        { 

            std::cout << i << ") " << animals[i]->GetAnimalInfo().name << std::endl; 

        } 

         

        std::cout << "\n-1) Quit Application\n"; 

         

        // Get user input 

        std::string input; 

        int userChoice; 

         

        getline(std::cin, input); 

        userChoice = std::stoi(input); 

         

        // Sanity user input 

        if (userChoice == -1) 

        { 

            bIsRunning = false; 

        } 

        else if (userChoice < -1 || userChoice > ((int)animals.size() - 1)) 

        { 

            std::cout << "\nInvalid Index. Please enter another.\n"; 

        } 

        else 

        { 

            // Print animal info 

            std::cout << std::endl; 

            PrintAnimalInfo(animals[userChoice]->GetAnimalInfo()); 

        } 

    } 

     

    // Cleanup. 

    for (size_t i = 0; i < animals.size(); ++i) 

    { 

        delete animals[i]; 

        animals[i] = nullptr; 

    } 

    animals.clear(); 

} 
