#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

#define TABLE_SIZE 1000

set_node *table[TABLE_SIZE];

int set_hash(int key) { return key % TABLE_SIZE; }

void set_insert(int key) {
  int index = set_hash(key);

  set_node *new_node = (set_node *)malloc(sizeof(set_node));
  new_node->key = key;
  new_node->next = NULL;

  if (table[index] == NULL) {
    table[index] = new_node;
    return;
  }

  set_node *curr = table[index];
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

int set_contains(int key) {
  int index = set_hash(key);

  set_node *curr = table[index];
  while (curr != NULL) {
    if (curr->key == key) {
      return 1;
    }
    curr = curr->next;
  }

  return 0;
}

void set_remove_key(int key) {
  int index = set_hash(key);

  if (table[index] == NULL) {
    return;
  }

  if (table[index]->key == key) {
    set_node *temp = table[index];
    table[index] = table[index]->next;
    free(temp);
    return;
  }

  set_node *prev = table[index];
  set_node *curr = table[index]->next;
  while (curr != NULL) {
    if (curr->key == key) {
      prev->next = curr->next;
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void set_print() {
  printf("Set: ");
  for (int i = 0; i < TABLE_SIZE; i++) {
    set_node *curr = table[i];
    while (curr != NULL) {
      printf("%d ", curr->key);
      curr = curr->next;
    }
  }
  printf("\n");
}

