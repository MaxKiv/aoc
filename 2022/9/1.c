#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define TEST 1
#define BUFF_SIZE 256

#define INPUT_PATH (TEST ? "test" : "input")

u_int64_t get_idx(const int x, const int y) {
  u_int64_t index = (u_int64_t)y;
  index <<= 32;
  index += x;
  return index;
}

void get_coordinate(const u_int64_t idx, int coordinates[2]) {
  coordinates[0] = idx >> 32;
  coordinates[1] = idx & INT_MAX;
}

int int_nonzero(int a) { return a != 0; }

int count_if(int *arr, size_t arr_size, int (*predicate)(int)) {
  int cnt = 0;
  for (size_t i = 0; i < arr_size; ++i) {
    if (predicate(arr[i])) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  // answer of this question: amount of positions rope tail visited
  int out = 0;

  // Previously positions, array index is x pos bits [0-31], [31-63] for y
  int previous_positions[sizeof(u_int64_t)] = {};

  // Current position in x y coordinate
  int last_position[2] = {};

  FILE *fin = fopen(INPUT_PATH, "re");
  char buff[BUFF_SIZE];
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    char direction = buff[0];
    int steps = buff[2] - '0';
    printf("input line: direction %c steps %d\n", direction, steps);

    int current_position[2] = {};
    current_position[0] = last_position[0];
    current_position[1] = last_position[1];

    for (int i = 0; i < steps; ++i) {
      switch (direction) {
      case 'R':
        ++current_position[0];
        break;
      case 'L':
        --current_position[0];
        break;
      case 'U':
        ++current_position[1];
        break;
      case 'D':
        --current_position[1];
        break;
      default:
        printf("switch error, hit default!\n");
        exit(1);
      }

      // skip first and last update
      if (i == 0) {
        continue;
      } else if (i == steps - 1) {
        continue;
      }

      // save tail pos in weird hashmap
      printf("current_position: %d %d\n", current_position[0],
             current_position[1]);
      uint64_t idx = get_idx(current_position[0], current_position[1]);
      previous_positions[idx]++;
    }
  }

  // count all nonzero entries in previous_positions
  out = count_if(previous_positions,
                 sizeof(previous_positions) / sizeof(previous_positions[0]),
                 int_nonzero);

  printf("answer 1: %d\n", out);
}
