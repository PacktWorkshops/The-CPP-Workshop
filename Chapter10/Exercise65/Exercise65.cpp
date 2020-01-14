#include <iostream>

class Shape
{
public:
    int area = 10;
    int GetArea() { return area; }
};

class Square : public Shape
{
};

class Circle : public Shape
{
};

class Triangle : public Shape
{
};

int main()
{
    Square mySquare;
    Circle myCircle;
    Triangle myTriangle;
    mySquare.area = 5;
    std::cout << "Square Area: " << mySquare.GetArea() << std::endl;
    myCircle.area = 15;
    std::cout << "Circle Area: " << myCircle.GetArea() << std::endl;
    std::cout << "Triangle Area: " << myTriangle.GetArea() << std::endl;
}
