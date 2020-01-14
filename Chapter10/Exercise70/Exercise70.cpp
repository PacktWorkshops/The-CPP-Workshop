// Casting example. 
#include <iostream> 
#include <string> 
class Shape 
{ 
public: 
    virtual int CalculateArea() = 0;   
    
protected: 
    int area = 0; 
};  

class Square : public Shape 
{ 
public: 
    int height = 0;          
    int CalculateArea() override 
    { 
        area = height * height; 
        return area; 
    } 
};

class Circle : public Shape 
{ 
public: 
    int radius = 0;             
    int CalculateArea() override
    { 
        area = 3.14 * (radius * radius); 
        return area; 
    } 
}; 

int main() 
{ 
    Shape* square = new Square(); 
    Shape* circle = new Circle();      
    Square* square2 = static_cast<Square*>(square); 
    square2->height = 10;      
    Circle* circle2 = static_cast<Circle*>(circle); 
    circle2->radius = 10;    
    std::cout << "Square Area: " << square->CalculateArea() << std::endl; 
    std::cout << "Circle Area: " << circle->CalculateArea() << std::endl; 
    delete square; 
    square = nullptr; 
    delete circle; 
    circle = nullptr; 
}
