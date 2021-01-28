#include <iostream>
#include <string>
class Shape
{
  public:
    int area = 0;
    protected:
    std::string color = "";
private:
    bool hasOutline = false;
};
class Square : public Shape
{
public:
  Square()
{
  area = 5;
  color = "red";
  hasOutline = true;
};
};
int main()
{
  Square mySquare;
  std::cout << "Square Area: " << mySquare.area << std::endl;
  std::cout << "Square Color: " << mySquare.color << std::endl;
  std::cout << "Square Has Outline: " << mySquare.hasOutline <<
  std::endl;
}
