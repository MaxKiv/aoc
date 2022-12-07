#include <assert.h>
#include <stdio.h>
#include <string.h>

/* #define TEST */
#define BUFF_SIZE 5000
#define WINDOW_SIZE 14

int chars_in_window_unique(char moving_window[WINDOW_SIZE]) {
  int out = 0;
  for (size_t i = 0; i < WINDOW_SIZE; i++) {
    for (size_t j = 0; j < WINDOW_SIZE; j++) {
      /* printf("%c == %c -> %d\n", moving_window[i], moving_window[j],
       * moving_window[i] == moving_window[j]); */
      out += moving_window[i] == moving_window[j];
    }
  }
  return out == WINDOW_SIZE;
}

void move_window(char moving_window[WINDOW_SIZE], char item) {
  // copy moving_window into tmp
  char tmp[WINDOW_SIZE];
  for(size_t i = 0; i < WINDOW_SIZE; i++) {
    tmp[i] = moving_window[i];
  }
  // move chars in window 1 to left
  for (size_t i = 0; i < WINDOW_SIZE - 1; i++) {
    moving_window[i] = tmp[i + 1];
  }
  // set last char in moving_window to new entry
  moving_window[WINDOW_SIZE - 1] = item;
}

long process_line(char *buff, char moving_window[WINDOW_SIZE]) {
  long answer = 0;
  int init_cnt = 0;

  // init window
  while (init_cnt < WINDOW_SIZE) {
    moving_window[init_cnt] = buff[init_cnt];
    init_cnt++;
  }

  for (size_t i = init_cnt; i < strlen(buff) - 1; i++) {
    // check if unique
    if (chars_in_window_unique(moving_window)) {
      // found answer
      answer = i;
      break;
    }
    // if not: move window along
    printf("item: %c\n", buff[i]);
    move_window(moving_window, buff[i]);
  }

  if (answer == 0) {
    assert(0);
  }

  return answer;
}

int main() {
  // init
  long answer = 0;
  char moving_window[WINDOW_SIZE];

  // read input
#ifdef TEST
  const char *input_path = "test2";
#else
  const char *input_path = "input";
#endif

  FILE *fin = fopen(input_path, "re");
  char buff[BUFF_SIZE];
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    answer = process_line(buff, moving_window);
    printf("\n***************** Answer *****************\n");
    printf("%ld\n", answer);
  }
}
