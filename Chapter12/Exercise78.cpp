#include <iostream>

#include <string>

#include <set>

using namespace std;
class Person {
  public:
    Person(string name, int age) {
      m_name = name;
      m_age = age;
    }
  string getName() const {
    return m_name;
  }
  int getAge() const {
    return m_age;
  }
  private:
    string m_name;
  int m_age;
};
struct customComparator {
  bool operator()(const Person & a,
    const Person & b) const {
    return (a.getAge() > b.getAge());
  }
};
int main() {
  set < Person, customComparator > personSet;
  Person a("bob", 35);
  Person b("bob", 25);
  personSet.insert(a);
  personSet.insert(b);
  for (auto person: personSet) {
    cout << person.getAge() << endl;
  }
}
