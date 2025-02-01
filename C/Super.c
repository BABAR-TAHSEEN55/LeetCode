#include <stdio.h>

int counter = 0;
int CallMe() {
  printf("Hello");
  if (counter == 2) {
    return 0;
  }

  counter++;
  return CallMe();
}

int main() { CallMe(); }
