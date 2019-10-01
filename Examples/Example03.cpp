// Conditional compilation example.
#include <iostream>

#define LEVEL 3

int main()
{
  #if LEVEL == 0
    #define SCORE 0
  #else
  #if LEVEL == 1
    #define SCORE 15
  #endif
  #endif
  
  #if LEVEL == 2
    #define SCORE 30
  #elif LEVEL == 3
    #define SCORE 45
  #endif

   #ifdef SCORE
     std::cout << SCORE;
   #endif
}