#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* #define TEST */
#define BUFF_SIZE 255

char num2char(int i) {
  if (i >= 26) {
    char out = i - 26 + 'A';
    return out;
  } else {
    char out = i + 'a';
    return out;
  }
}

int char2num(char c) {
  if (isupper(c)) {
    int out = c - 'A' + 26;
    return out;
  } else {
    int out = c - 'a';
    return out;
  }
}

void print_seen(int *seen) {
  for (size_t i = 0; i < 52; i++) {
    if (seen[i] > 0) {
      printf("%c%d ", num2char(i), seen[i]);
    }
  }
  printf("\n");
}
void intersection(int *const line_arr, int *seen) {
  for (size_t i = 0; i < 52; i++) {
    if (line_arr[i] == 0) {
      seen[i] = 0;
    }
  }
}

void process_line(char *buff, int *seen) {
  printf("newline: %s\n", buff);

  int line_arr[52] = {0};
  size_t len = strlen(buff) - 1; // -1 because of newline

  // count char indices in current line
  for (size_t i = 0; i < len; i++) {
    char c = *(buff + i);
    int index = char2num(c);
    printf("char %c, index: %d\n", c, index);
    line_arr[index]++;
  }
  printf("chars in line:\n");
  print_seen(line_arr);
  printf("Pre intersection seen array:");
  print_seen(seen);
  // take intersection with previous seen lines
  printf("shared chars in group\n");
  intersection(line_arr, seen);

  print_seen(seen);
}

void set_array(int *seen, int value) {
  for (size_t i = 0; i < 52; i++) {
    seen[i] = value;
  }
}

int main() {
  int elf = 0;
  int seen[52] = {0}; // Array that tracks seen chars, indexed by char - 'a'
  set_array(seen, 1);
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
    process_line(buff, seen);

    // track group state
    if (++elf == 3) {
      // find only item thats seen 3 times, fill answer
      long group_answer = 0;
      for (size_t i = 0; i < 52; i++) {
        if (seen[i] != 0) {
          group_answer += i + 1;
          break;
        }
      }
      if (group_answer == 0) {
        assert(1);
      }
      answer += group_answer;

      // reset group state
      set_array(seen, 1);
      elf = 0;
      printf("~~~~ new group ~~~~\n");
    }
  }

  printf("\n***************** A *****************\n");
  printf("%ld\n", answer);
}
