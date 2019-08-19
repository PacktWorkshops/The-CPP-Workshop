#include <iostream>

#include <string>

#include <algorithm>

using namespace std;
bool isPalindrome(const string & str) {
  // make a copy of the string
  string s(str.begin(), str.end());
  // remove any spaces or punctuation
  s.erase(remove_if(s.begin(), s.end(), [](const char & c) {
    return
    ispunct(c) || isspace(c);
  }), s.end());
  // lower case what's left
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  // create a reversed version of the string
  string sr(s.rbegin(), s.rend());
  // compare them
  return (s == sr);
}

int main() {
  string str = "Never odd or even";
  cout << "'" << str << "'" << " is a palindrome? " << (isPalindrome(str) ? "YES" : "NO") << endl;

  return 0;
}
