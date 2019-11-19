// continue example.
#include <iostream>

#include <string>

int main() {
  std::cout << "Loop Starting ...\n";

  int count = 0;

  while (count < 5) {
    ++count;

    if (count == 3) {
      continue;
    }

    std::cout << "\n" << count;
  }

  std::cout << "\n\nLoop finished.";
}
