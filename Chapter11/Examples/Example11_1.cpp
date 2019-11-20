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
 
    private:  
     
        void init() {} 
        void init(size_t numElements, const T& initialValue) {} 
        
        void destroy() {}
        
        // the allocator object
        allocator<T> alloc;
      
        T* queueData;  
        T* queueDataEnd;
        T* memLimit; // one past the end of allocated memory
};
