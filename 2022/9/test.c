#include <stdio.h>
#include <string.h>

#include "set.h"

#define TABLE_SIZE 1000

extern set_node *table[TABLE_SIZE];

int main() {
  memset(table, 0, sizeof(set_node *) * TABLE_SIZE);

  set_insert(5);
  set_insert(8);
  set_insert(3);
  set_insert(10);

  set_print();

  printf("Set contains 5: %d\n", set_contains(5));
  printf("Set contains 7: %d\n", set_contains(7));

  set_remove_key(5);

  set_print();

  return 0;
}
