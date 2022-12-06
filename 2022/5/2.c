#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #define TEST */
#define BUFF_SIZE 255
#define STACK_CAPACITY 1000

#ifdef TEST
#define STATE_SIZE 3
#else
#define STATE_SIZE 10
#endif
// Track parser state
enum parse_state { initial, moves };

typedef struct parser_t {
  enum parse_state parser_state;
  char input_buffer[10][100]; // big enough to hold cargo bay input
  int size;
} parser_t;

// stack data structure to track cargo bay state
typedef struct stack {
  char *items;
  int size;
  int capacity;
} stack;

// stack functions
stack *stack_constructor(int capacity);
void stack_destructor(stack *stackptr);
int stack_isfull(stack *stackptr);
int stack_isempty(stack *stackptr);
char stack_peek(stack *stackptr);
char stack_pop(stack *stackptr);
void stack_push(stack *stackptr, char elem);
void print_stack(stack *stackptr);
void stack_tostring(stack *stackptr);

// reduces state into char array that contains top of each stack
void reduce_state(stack *state[STATE_SIZE], char *out) {
  for (size_t i = 0; i < STATE_SIZE; i++) {
    out[i] = stack_peek(state[i]);
  }
}

void print_state_reduced(stack *state[STATE_SIZE]) {
  char out[STATE_SIZE] = "";
  reduce_state(state, out);
  printf("reduced state: %s\n", out);
}

void stack_tostring(stack *stackptr) {
  printf("stack size/capacity: %d/%d\n", stackptr->size, stackptr->capacity);
  printf("stack items: %s\n", stackptr->items);
}

void print_stack(stack *stackptr) { printf("%s\n", stackptr->items); }

void print_state(stack *state[STATE_SIZE]) {
  printf("state stack:\n");
  for (size_t i = 0; i < STATE_SIZE; i++) {
    printf("%zu ", i);
    print_stack(state[i]);
  }
  printf("\n");
}

void parse_initial(char *buff, parser_t *parser) {
  strcpy(parser->input_buffer[parser->size], buff);
  printf("buffer : %s\n", parser->input_buffer[parser->size]);
  parser->size++;
}

void parse_moves(char *buff, stack *cargo_state[STATE_SIZE]) {
  printf("parse move line: %s", buff);

  char *rest = buff;
  rest += 4;
  long amount = strtol(rest, &rest, 10);
  rest += 5;
  long source = strtol(rest, &rest, 10) - 1;
  rest += 3;
  long destination = strtol(rest, &rest, 10) - 1;
  printf("amount %ld source %ld destination %ld\n", amount, source,
         destination);
  char move_buffer[amount];
  for (int i = 0; i < amount; i++) {
    move_buffer[i] = stack_pop(cargo_state[source]);
  }
  for (int i = amount - 1; i >= 0; i--) {
    stack_push(cargo_state[destination], move_buffer[i]);
  }
  print_state(cargo_state);
}

void fill_cargo_state_from_parser_buffer(parser_t *parser,
                                         stack *cargo_state[STATE_SIZE]) {
  // reverse iterate input buffer, skip last line, you could parse it to get
  // STATE_SIZE, we hardcode it
  printf("converting input buffer to stack\n");
  for (int i = parser->size - 2; i != -1; i--) {
    printf("new input_buffer line %d: %s\n", i, parser->input_buffer[i]);
    for (int j = 0; j < STATE_SIZE; j++) {
      int index = 1 + 4 * j;
      char elem = parser->input_buffer[i][index];
      if (elem != ' ') {
        stack_push(cargo_state[j], elem);
      }
    }
  }
}

void process_line(char *buff, parser_t *parser,
                  stack *cargo_state[STATE_SIZE]) {
  printf("newline: %s", buff);

  // manage parser state
  if (buff[0] == '\n') {
    fill_cargo_state_from_parser_buffer(parser, cargo_state);

    print_state(cargo_state);

    printf("flipped parser state\n");
    parser->parser_state = moves;
    return;
  }

  // input parsing
  if (parser->parser_state == initial) {
    parse_initial(buff, parser);
  } else {
    parse_moves(buff, cargo_state);
  }
}

int main() {
  // parser state
  parser_t parser = {
      .size = 0,
      .parser_state = initial,
  };

  // cargo state
  stack *cargo_state[STATE_SIZE];

#pragma unroll
  for (int i = 0; i < STATE_SIZE; i++) {
    // init state
    cargo_state[i] = stack_constructor(STACK_CAPACITY);
  }
  print_state(cargo_state);

  // read input
#ifdef TEST
  const char *input_path = "test";
#else
  const char *input_path = "input";
#endif

  FILE *fin = fopen(input_path, "re");
  char buff[BUFF_SIZE];
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    process_line(buff, &parser, cargo_state);
  }

  printf("\n***************** Answer *****************\n");
  char answer[STATE_SIZE + 1] = "";
  reduce_state(cargo_state, answer);
  printf("%s\n", answer);
}

stack *stack_constructor(int capacity) {
  stack *new = malloc(sizeof(stack));
  if (new == NULL) {
    assert(0);
  } // not enough heap space
  new->capacity = capacity;
  new->size = 0;
  new->items = malloc(sizeof(char) * capacity);
  if (new->items == NULL) {
    assert(0);
  } // not enough heap space
  return new;
}

void stack_destructor(stack *stackptr) {
  free(stackptr->items);
  free(stackptr);
}

int stack_isfull(stack *stackptr) {
  return stackptr->size == stackptr->capacity;
}

int stack_isempty(stack *stackptr) { return stackptr->size == 0; }

char stack_peek(stack *stackptr) {
  if (stack_isempty(stackptr)) {
    printf("ERROR: peeked empty stack :(\n");
    assert(0);
  } else {
    return stackptr->items[stackptr->size - 1];
  }
}

char stack_pop(stack *stackptr) {
  if (stack_isempty(stackptr)) {
    printf("ERROR: popped empty stack :(\n");
    assert(0);
  } else {
    char top = stackptr->items[stackptr->size - 1];
    stackptr->items[--stackptr->size] = (char)0;
    return top;
  }
}

void stack_push(stack *stackptr, char elem) {
  if (!stack_isfull(stackptr)) {
    stackptr->items[stackptr->size++] = elem;
  } else {
    printf("ERROR: pushed to full stack :(\n");
    assert(0);
  }
}
