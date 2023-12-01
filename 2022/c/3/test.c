#include <stdio.h>

int main() {
  for(size_t i =0; i < 255; i++) {
    printf("%zu - %c\n", i, (char) i);
  }

}
