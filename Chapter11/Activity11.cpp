#include <iostream> 

#include <memory> 

 

using namespace std; 

 

template<class T>    

class Stack    

{    

    public:    

  

        Stack() { init(); }  

        explicit Stack(size_t numElements, const T& initialValue = T())  

        {   

            init(numElements, initialValue);  

        } 

         

        Stack(const Stack& q) { init(q.bottom(), q.top()); } 

        Stack& operator=(const Stack& rhs) 

        { 

            if (&rhs != this) 

            { 

                destroy(); 

                init(rhs.bottom(), rhs.top()); 

            } 

            return *this; 

        } 

 

        ~Stack() { destroy(); } 

  

        T* top() { return stackDataEnd - 1; }   

        const T* top() const { return stackDataEnd - 1; }   

          

        T* bottom() { return stackData; }   

        const T* bottom() const { return stackData; }   

          

        size_t size() const { return stackDataEnd - stackData; }   

        bool empty() const { return size() == 0; }  
  void pop() 

        { 

            if (top() != 0) 

            { 

                alloc.destroy(top()); 

  

                stackDataEnd -= 1; 

            } 

        } 
}
  int main() 

{ 

    Stack<int> testStack; 

  

    testStack.push(1); 

    testStack.push(2); 

  

    cout << "stack contains values: "; 

    for (auto it = testStack.bottom(); it != testStack.top() + 1; ++it) 

    { 

        cout << *it << " "; 

    } 

  

    cout << endl; 

    cout << "stack contains " << testStack.size() << " elements" << endl; 

  

    testStack.pop(); 

  

    cout << "stack contains values: "; 

    for (auto it = testStack.bottom(); it != testStack.top() + 1; ++it) 

    { 

        cout << *it << " "; 

    } 

  

    cout << endl; 

    cout << "stack contains " << testStack.size() << " elements" << endl; 

  

    testStack.push(9); 

    testStack.push(50); 

  

    cout << "stack contains values: "; 

    for (auto it = testStack.bottom(); it != testStack.top() + 1; ++it) 

    { 

        cout << *it << " "; 

    } 

  

    cout << endl; 

    cout << "stack contains " << testStack.size() << " elements" << endl; 

  

    testStack.pop(); 

  

    cout << "stack contains values: "; 

    for (auto it = testStack.bottom(); it != testStack.top() + 1; ++it) 

    { 

        cout << *it << " "; 

    } 

  

    cout << endl; 

    cout << "Is the Stack empty: " << (testStack.empty() == 1 ? "YES" : "NO") << endl; 

  

    cout << "value of top element is: " << *testStack.top() << endl; 

    cout << "value of bottom element is: " << *testStack.bottom() << endl; 

  

    return 0; 

} 
