#include <iostream>
// need the memory header
#include <memory>

using namespace std;

template<class T>
class Queue
{
    public:
        Queue() { init(); }
        explicit Queue(size_t numElements, const T& initialValue = T())
        {
            init(numElements, initialValue);
        }
    
       ~Queue() { destroy(); }
    
        T* front() { return queueData; }
        const T* front() const { return queueData; }
        T* back() { return queueDataEnd - 1; }
        const T* back() const { return queueDataEnd - 1; }
        size_t size() const { return queueDataEnd - queueData; }
        bool empty() const { return size() == 0; }
        
        void pop()
        {
            if (queueData != 0)
            {
                alloc.destroy(queueData);
                for (int i = 0; i < size(); i++)
                {
                    queueData[i] = queueData[i + 1];
                }
                queueDataEnd -= 1;
             }
         }
    
        void push(const T& element)
        {
            if (queueDataEnd == memLimit)
            resize();
            append(element);
        }
        
    private:
        void init() 
        {
            queueData = queueDataEnd = memLimit = 0;
        }
        void init(size_t numElements, const T& initialValue) 
        {
            queueData = alloc.allocate(numElements);
            queueDataEnd = memLimit = queueData + numElements;
            uninitialized_fill(queueData, queueDataEnd, initialValue);
        }
        
        void destroy()
        {
            if (queueData != 0)
            {
                T* it = queueDataEnd;
                while (it != queueData)
                {
                    alloc.destroy(--it);
                }
                    alloc.deallocate(queueData, memLimit - queueData);
            }
            queueData = queueDataEnd = memLimit = 0;
        }
    
        void resize()
        {
            size_t newSize = max(2 * (queueDataEnd - queueData), ptrdiff_t(1));
            T* newData = alloc.allocate(newSize);
            T* newDataEnd = uninitialized_copy(queueData, queueDataEnd, newData);
            destroy();
            queueData = newData;
            queueDataEnd = newDataEnd;
            memLimit = queueData + newSize;
        }

        void append(const T& newValue)
        {
            alloc.construct(queueDataEnd++, newValue);
        }
    

        void init(T* front, T* back)
        {
            queueData = alloc.allocate(back - front);
            memLimit = queueDataEnd = uninitialized_copy(front, back, queueData);
        }
       
        Queue(const Queue& q) { init(q.front(), q.back()); }
        
        Queue& operator=(const Queue& rhs)
        {
            if (&rhs != this)
            {
                destroy();
                init(rhs.front(), rhs.back());
            }
        return *this;
        }

        // the allocator object
        allocator<T> alloc;
        T* queueData;
        T* queueDataEnd;
        T* memLimit; // one past the end of allocated memory
  };

int main()
{
    Queue<int> testQueue;
    testQueue.push(1);
    testQueue.push(2);
    cout << "queue contains values: ";
    
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;
    testQueue.pop();
    cout << "queue contains values: ";

    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;  
    testQueue.push(9);
    testQueue.push(50);
    
    cout << "queue contains values: ";
    
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;
    testQueue.pop();
    cout << "queue contains values: ";
    
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "Is the Queue empty: " << (testQueue.empty() == 1 ? "YES" :"NO") << endl;
    cout << "value of first element is: " << *testQueue.front() << endl;
    cout << "value of last element is: " << *testQueue.back() << endl;
    
    return 0;
}
