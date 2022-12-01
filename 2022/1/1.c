#include <stdio.h>  // reading input file
#include <stdlib.h> // strtol
#include <string.h> // strcmp

int main() {
  long calories_max = 0;
  long current_calories = 0;

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
      if (current_calories > calories_max) {
        calories_max = current_calories;
      }
    }
    /* printf("current calories: %ld - max: %ld\n", current_calories, calories_max); */
  }

  printf("\n***************** A *****************\n");
  printf("%ld", calories_max);
}
