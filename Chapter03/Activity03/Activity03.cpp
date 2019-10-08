// Activity 3: SignUp Application.
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
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
     std::cout << "\nUser record added successfully.\n\n";
   };
Person FetchRecord(int userID)
   {
      return records.at(userID);
   };
int main()
  {
     std::cout << "User SignUp Application\n" << std::endl;
     bool bIsRunning = true;
     while (bIsRunning)
       {
          std::cout << "Please select an option:\n";
          std::cout << "1: Add Record\n";
          std::cout << "2: Fetch Record\n";
          std::cout << "3: Quit\n\n";
          std::cout << "Enter option: ";
          std::string inputString;
          std::getline(std::cin, inputString);
          //Determine user selection.
          switch (std::stoi(inputString))
             {
                case 1:
                  {
                     std::string name = "";
                     int age = 0;
                     std::cout << "\nAdd User. Please enter user name and age:\n";
                     std::cout << "Name: ";
                     std::getline(std::cin, name);
                     std::cout << "Age: ";
                     std::getline(std::cin, inputString);
               age = std::stoi(inputString);
               AddRecord(name, age);
             }
          break;
          case 2:
             {
               int userID = 0;
               std::cout << "\nPlease enter user ID:\n";
               std::cout << "User ID: ";
               std::getline(std::cin, inputString);
               userID = std::stoi(inputString);
               Person person;
               try
                 {
                    person = FetchRecord(userID);
                  }
                catch (const std::out_of_range& oor) 
                  {
                     std::cout << "\nError: Invalid UserID.\n\n";
                     break;
                   }
               std::cout << "User Name: " << person.name << "\n";
               std::cout << "User Age: " << person.age << "\n\n";
              }
          break;
          case 3:
            bIsRunning = false;
          break;
          default:
             std::cout << "\n\nError: Invalid option selection.\n\n";
          break;
              }
          }
     }
