#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T>

class Position
{
public:
    Position(T x, T y)
    {
        m_x = x;
        m_y = y;
    }
    
    T const getX() { return m_x; }
    T const getY() { return m_y; }

private:
    T m_x;
    T m_y;
};

int main()
{
    Position<int> intPosition(1, 3);
    Position<float> floatPosition(1.5f, 3.14f);
    Position<long> longPosition(1, 3);
    
    cout << "type: " << typeid(intPosition.getX()).name() << " X: " << intPosition.getX() << " Y: " << intPosition.getY() << endl; 
    cout << "type: " << typeid(floatPosition.getX()).name() << " X: " << floatPosition.getX() << " Y: " << floatPosition.getY() << endl;
    cout << "type: " << typeid(longPosition.getX()).name() << " X: " << longPosition.getX() << " Y: " << longPosition.getY() << endl;
   
    return 0;
}
