#include <stdio.h>  // reading input file
#include <stdlib.h> // strtol
#include <string.h> // strcmp

#define SIZE 3

void check_insert(long *current_max, long *current_calories) {
  for (size_t i = 0; i < SIZE; i++) {
    printf("checking current max %ld against %ld\n", current_max[i],
           *current_calories);
    if (*current_calories > current_max[i]) {
      printf("found new max\n");
      current_max[i] = *current_calories;
      break;
    }
  }
}

void print_stuff(long *current_max) {
  printf("current max: ");
  for (size_t i = SIZE - 1; i != -1; i--) {
    printf(" %ld", current_max[i]);
  }
  printf("\n");
}

long long_sum(long a, long b) {
  return a + b;
}

// might overflow?
long reduce(long * current_max, long (*fun)(long, long)) {
  long out = 0;
  for (size_t i = SIZE - 1; i != -1; i--) {
    out = fun(out, current_max[i]);
  }
  return out;
}

int main() {
  long current_calories = 0;
  // made this track 3 values small -> big
  long current_max[SIZE] = {0, 0, 0};

  // read input
  const char *input_path = "input";
  FILE *fin = fopen(input_path, "r");
  char buff[255];
  while (fgets(buff, 255, fin) != NULL) {
    // buff holds every line
    if (strcmp(buff, "\n") == 0) {
      // newline
      current_calories = 0;
    } else {
      current_calories += strtol(buff, NULL, 10);
      check_insert(current_max, &current_calories);
    }
    print_stuff(current_max);
    /* printf("current calories: %ld - max: %ld\n", current_calories,
     * calories_max); */
  }

  printf("\n***************** B *****************\n");
  printf("%ld\n", reduce(current_max, long_sum));
}
