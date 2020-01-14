// Activity 1.
#include <iostream>
#include <string>

#define GROUP_1_THRESHOLD 12
#define GROUP_2_THRESHOLD 28
#define GROUP_1_NAME "Group A"
#define GROUP_2_NAME "Group B"
#define GROUP_3_NAME "Group C"

std::string GetGroup(int age);

int main()
{
    std::string name = "";
    int age = 0;
    std::string group = "";
    std::cout << "Please enter your name: ";
    getline(std::cin, name);
    std::cout << "And please enter your age: ";
    std::cin >> age;
    group = GetGroup(age);
    std::cout << "Welcome "<< name << ". You are in " << group << ".\n";
}

std::string GetGroup(int age)
{
    if (age <= GROUP_1_THRESHOLD)
    {
        return GROUP_1_NAME;
    }
    else if (age <= GROUP_2_THRESHOLD)
    {
        return GROUP_2_NAME;
    }
    else
    {
        return GROUP_3_NAME;
    }
}
