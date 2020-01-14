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
    
    void push(const T& element)
    {
        if (stackDataEnd == memLimit)
            resize();
        append(element);
    }
 
private:  
    void init()
    {
        stackData = stackDataEnd = memLimit = 0;
    }
    
    void init(size_t numElements, const T& initialValue)
    {
        stackData = alloc.allocate(numElements);
        stackDataEnd = memLimit = stackData + numElements;
        uninitialized_fill(stackData, stackDataEnd, initialValue);
    }
    
    void init(T* front, T* back)
    {
        stackData = alloc.allocate(back - front);
        memLimit = stackDataEnd = uninitialized_copy(front, back, stackData);
    }
        
    void destroy()
    {
        if (stackData != 0)
        {
            T* it = stackDataEnd;
         
            while (it != stackData)
            {
                alloc.destroy(--it);
            }
                alloc.deallocate(stackData, memLimit - stackData);
        }
        
        stackData = stackDataEnd = memLimit = 0;
    }        
    
    void resize()
    {
        size_t newSize = max(2 * (stackDataEnd - stackData), ptrdiff_t(1));
        T* newData = alloc.allocate(newSize);
        T* newDataEnd = uninitialized_copy(stackData, stackDataEnd, newData);
        destroy();
        stackData = newData;
        stackDataEnd = newDataEnd;
        memLimit = stackData + newSize;
    }
    
    void append(const T& newValue)
    {
        alloc.construct(stackDataEnd++, newValue);
    }
    
        // the allocator object
        allocator<T> alloc;
        T* stackData;  
        T* stackDataEnd;
        T* memLimit; // one past the end of allocated memory
};

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
