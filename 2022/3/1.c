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

void process_line(char *buff, long *answer) {
  printf("newline: %s\n", buff);
  long line_score = 0;
  int seen[52] = {0}; // Array that tracks seen chars, indexed by char - 'a'
  size_t len = strlen(buff) - 1; // -1 because of newline

  // Assemble array of chars in first half of string
  for (size_t i = 0; i < len / 2; i++) {
    char c = *(buff + i);
    int index = char2num(c);
    printf("char %c, index: %d\n", c, index);
    seen[index]++;
  }
  print_seen(seen);

  // Find duplicate char in second half of string
  for (size_t i = len / 2; i < len; i++) {
    char c = *(buff + i);
    int index = char2num(c);
    if (seen[index] != 0) {
      line_score += index + 1;
      printf("found duplicate in 2nd half: %c\n", c);
      break;
    }
  }
  if (line_score == 0) {
    assert(0);
  }
  *answer += line_score;
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
    process_line(buff, &answer);
  }

  printf("\n***************** A *****************\n");
  printf("%ld\n", answer);
}
