#include <stdio.h>
#include <string.h>

#define TEST 0
#define BUFF_SIZE 256

#define INPUT_PATH (TEST ? "test" : "input")
#define STATE_SIZE (TEST ? 5 : 99)

static int state[STATE_SIZE][STATE_SIZE] = {};
static int linenumber = 0;

void print_state() {
  for (size_t i = 0; i < (sizeof(state) / sizeof(state[0])); ++i) {
    for (size_t j = 0; j < (sizeof(state[0]) / sizeof(state[0][0])); ++j) {
      printf("%d ", state[i][j]);
    }
    printf("\n");
  }
}

// tree is visible if derivative is positive
void process_to_right(int row[STATE_SIZE]) {
  // algo here
  int max = row[0];
  for (size_t i = 1; i < STATE_SIZE; i++) {
    int current = row[i];
    if (current - max > 0) {
      printf("process_to_right: current %d max %d, tree visible!\t", current, max);
      max = current;
      printf("new max:%d\n", max);
    } else {
      printf("process_to_right: current %d max %d, tree hidden\n", current, max);
      state[linenumber][i]--;
    }
  }
}

// tree is visible if derivative is positive
void process_to_bottom(int column[STATE_SIZE]) {
  // algo here
  int max = column[0];
  for (size_t i = 1; i < STATE_SIZE; i++) {
    int current = column[i];
    if (current - max > 0) {
      printf("process_to_bottom: current %d max %d, tree visible!\t", current, max);
      max = current;
      printf("new max:%d\n", max);
    } else {
      printf("process_to_bottom: current %d max %d, tree hidden\n", current, max);
      state[i][linenumber]--;
    }
  }
}

void process_to_top(int column[STATE_SIZE]) {
  int max = column[STATE_SIZE - 1];
  for (int i = STATE_SIZE - 2; i >= 0; --i) {
    int current = column[i];
    if (current - max > 0) {
      printf("process_to_top: current %d max %d, tree visible!\t", current, max);
      max = current;
      printf("new max:%d\n", max);
    } else {
      printf("process_to_top: current %d max %d, tree hidden\n", current, max);
      state[i][linenumber]--;
    }
  }
}

void process_to_left(int row[STATE_SIZE]) {
  int max = row[STATE_SIZE - 1];
  for (int i = STATE_SIZE - 2; i >= 0; --i) {
    int current = row[i];
    if (current - max > 0) {
      printf("process_left: current %d max %d, tree visible!\t", current, max);
      max = current;
      printf("new max:%d\n", max);
    } else {
      printf("process_left: current %d max %d, tree hidden\n", current, max);
      state[linenumber][i]--;
    }
  }
}

void print_input(int input[STATE_SIZE][STATE_SIZE]) {
  printf("\n*** puzzel input ***\n");
  for (size_t i = 0; i < STATE_SIZE; i++) {
    for (size_t j = 0; j < STATE_SIZE; j++) {
      printf("%d ", input[i][j]);
    }
    printf("\n");
  }
}

void copy_input(int input[STATE_SIZE][STATE_SIZE]) {
  FILE *fin = fopen(INPUT_PATH, "re");
  char buff[BUFF_SIZE];
  int line = 0;
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    for (size_t i = 0; i < STATE_SIZE; i++) {
      input[line][i] = buff[i] - '0';
    }
    line++;
  }
}

// make trees visible by default
void state_init() {
  for (size_t i = 0; i < STATE_SIZE; i++) {
    for (size_t j = 0; j < STATE_SIZE; j++) {
      state[i][j] = 4;
    }
  }
  print_state();
}

int is_zero(int a) {
  return a == 0;
}

int state_count_if(int (*predicate)(int)) {
  int count = 0;
  for (size_t i = 0; i < STATE_SIZE; i++) {
    for (size_t j = 0; j < STATE_SIZE; j++) {
      if(predicate(state[i][j])) {
        ++count;
      }
    }
  }
  return count;
}

void print_row(int row[STATE_SIZE]) {
  for (size_t i = 0; i < STATE_SIZE; i++) {
    printf("%d ", row[i]);
  }
  printf("\n");
}

int main() {
  state_init();

  int input[STATE_SIZE][STATE_SIZE] = {};
  copy_input(input);

  printf("*** starting horizontal scan ***\n");
  for (size_t i = 0; i < STATE_SIZE; i++) {
    int row[STATE_SIZE] = {};
    for (size_t j = 0; j < STATE_SIZE; j++) {
      row[j] = input[i][j];
    }
    printf("row: \n");
    print_row(row);

    process_to_right(row);
    printf("*** process_to_right ***\n");
    print_state();

    process_to_left(row);
    printf("*** process_to_left ***\n");
    print_state();

    linenumber++;
  }

  linenumber = 0;
  printf("*** starting vertical scan ***\n");
  for (size_t i = 0; i < STATE_SIZE; i++) {
    int column[STATE_SIZE] = {};
    for (size_t j = 0; j < STATE_SIZE; j++) {
      column[j] = input[j][i];
    }
    printf("column: \n");
    print_row(column);

    process_to_bottom(column);
    printf("*** process_to_bottom \n");
    print_state();

    process_to_top(column);
    printf("*** process_to_top ***\n");
    print_state();

    linenumber++;
  }

  // print input yea
  print_input(input);

  int (*is_zero_ptr)(int) = is_zero;
  int count = state_count_if(is_zero_ptr);
  printf("\ninvisible trees: %d\n", count);
  printf("visible trees: %d\n", STATE_SIZE*STATE_SIZE - count);
}
