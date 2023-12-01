#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define TEST
#define BUFF_SIZE 255

long process_line(char *buff) {

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
