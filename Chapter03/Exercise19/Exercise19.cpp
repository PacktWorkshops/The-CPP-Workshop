// Classes/struct exercise.
#include <iostream>
#include <string>
class MyClass
{
   public:
     int myInt = 0;
     bool myBool = false;
   std::string GetString()
     {
       return "Hello World!";
     }
 };
struct MyStruct
 {
    int myInt = 0;
    bool myBool = false;
    std::string GetString()
     {
       return "Hello World!";
     }
};

int main()
{
  MyClass classObject;
  std::cout << "classObject::myInt: " << classObject.myInt << "\n";
  std::cout << "classObject::myBool: " << classObject.myBool << "\n";
  std::cout << "classObject::GetString: " << classObject.GetString() <<"\n";
  MyStruct structObject;
  std::cout << "\nstructObject::myInt: " << structObject.myInt << "\n";
  std::cout << "structObject::myBool: " << structObject.myBool << "\n";
  std::cout << "structbject::GetString: " << structObject.GetString() <<"\n";
}
