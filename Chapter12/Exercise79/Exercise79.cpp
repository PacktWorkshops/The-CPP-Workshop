#include <iostream>

#include <string>

#include <set>

#include <stdlib.h>

using namespace std;
int main() {
  set < int > intSet;
  multiset < int > intMultiset;
  for (unsigned int i = 0; i < 100; i++) {
    intMultiset.insert(1 + rand() % 100);
  }
  for (auto i: intMultiset) {
    intSet.insert(i);
  }
  cout << "there are " << intSet.size() << " unique elements in the multiset";
}
