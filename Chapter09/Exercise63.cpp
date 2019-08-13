#include <iostream> 
#include <cmath> 
class Position 
{ 
    public: 
        Position(float x, float y) : m_x(x), m_y(y) {}          
        float distance(float x, float y) 
        { 
            float xDiff = x - m_x; 
            float yDiff = y - m_y; 
            return std::sqrt(((xDiff * xDiff) + (yDiff * yDiff))); 
        }        
    private:         
        float m_x; 
        float m_y; 
}; 
int main() 
{ 
    Position pos(10.0f, 20.0f);     
    std::cout << "The distance from pos to (100, 40) is:" << pos.distance(100.0f, 40.0f) << std::endl;     
    return 0; 
} 
