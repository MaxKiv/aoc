#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #define TEST */
#define BUFF_SIZE 255
const char *delim_outer = ",";
const char *delim_inner = "-";

void print_state(long line_array[2][2]) {
  printf("state: ");
  for (size_t x = 0; x < 2; x++) {
    printf("[");
    for (size_t y = 0; y < 2; y++) {
      printf("%ld ", line_array[x][y]);
    }
    printf("], ");
  }
  printf("\n");
}

void parse_to_arrays(char *buff, long line_array[2][2]) {
  // We could use strtok but is parsing this really interesting?
  char *remainder;
  line_array[0][0] = strtol(buff, &remainder, 10);
  remainder++;
  line_array[0][1] = strtol(remainder, &remainder, 10);
  remainder++;
  line_array[1][0] = strtol(remainder, &remainder, 10);
  remainder++;
  line_array[1][1] = strtol(remainder, &remainder, 10);

  print_state(line_array);
}

int range_overlaps(long subject[2], long target[2]) {
  // [2-4], [6-8] -> 0
  // [2-7], [6-8] -> 1!
  // [5-6], [4-6] -> 1
  // [6-6], [4-6] -> 1
  // [4-6], [4-6] -> 1
  return subject[0] <= target[0] && subject[1] >= target[0];
}

int overlap_detected(long line_array[2][2]) {
  if (range_overlaps(line_array[0], line_array[1])) {
    return 1;
  } else if (range_overlaps(line_array[1], line_array[0])) {
    return 1;
  } else {
    return 0;
  }
}

long process_line(char *buff) {
  printf("newline: %s", buff);
  long line_answer = 0;
  long line_array[2][2];

  // input parsing
  parse_to_arrays(buff, line_array);

  if (overlap_detected(line_array)) {
    printf("overlap detected!\n");
    line_answer += 1;
  }

  return line_answer;
}

int main() {
  long answer = 0;

  // read input
#ifdef TEST
  const char *input_path = "test";
#else
  const char *input_path = "input";
#endif

  FILE *fin = fopen(input_path, "r");
  char buff[BUFF_SIZE];
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    answer += process_line(buff);
  }

  printf("\n***************** Answer *****************\n");
  printf("%ld\n", answer);
}
