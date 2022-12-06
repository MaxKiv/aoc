#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = "move 1111 from 2222 to 3333";
  char *rest = str;
  rest += 4;
  long amount = strtol(rest, &rest, 10);
  rest += 5;
  long source = strtol(rest, &rest, 10);
  rest += 3;
  long destination = strtol(rest, &rest, 10);
  printf("found: %ld\n", amount);
  printf("found: %ld\n", source);
  printf("found: %ld\n", destination);
}
