#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #define TEST */

// Represent the gamestate using two ints because why not
// Rock = 0
// Paper = 1
// Scissor = 2
typedef struct gamestate {
  int my_move;
  int their_move;
} gamestate;

// Print bits in the gamestate
void print_gamestate(gamestate *gs) {
  printf("gamestate: ");
  printf("my_move: %d their_move: %d", gs->my_move, gs->their_move);
  printf("\n");
}

int winning_move(int their_move) {
  int out = (their_move + 1) % 3;
  printf("wining move for %d is %d\n", their_move, out);
  return out;
}

int draw_move(int their_move) {
  int out = their_move;
  printf("draw move for %d is %d\n", their_move, out);
  return out;
}

int losing_move(int their_move) {
  int out = (their_move + 2) % 3;
  printf("losing move for %d is %d\n", their_move, out);
  return out;
}

gamestate moves_to_gamestate(char their_move, char strategy) {
  gamestate gs = {.my_move = 0, .their_move = 0};
  gs.their_move = their_move - 'A';
  // translate strategy to my move
  printf("strategy %c\n", strategy);
  switch (strategy) {
    case 'X':
      // Lose -> opposite move
      gs.my_move = losing_move(gs.their_move);
      break;
    case 'Y':
      gs.my_move = draw_move(gs.their_move);
      break;
    case 'Z':
      gs.my_move = winning_move(gs.their_move);
      break;
    default:
      assert(0);
  }

  print_gamestate(&gs);
  return gs;
}

/* A X 3 */
/* A Y 6 */
/* A Z 0 */
/* B X 0 */
/* B Y 3 */
/* B Z 6 */
/* C X 6 */
/* C Y 0 */
/* C Z 3 */
long big_scoring_algo(gamestate *gs) {
  long out = 0;
  const int score[7] = {3, 6, 0, 3, 6, 0, 3};
  int base_index = 2 * gs->their_move;
  printf("index: %d\n", 2 * gs->their_move);
  out += score[base_index + gs->my_move];
  printf("big score papi says %d %d = %ld\n", gs->their_move, gs->my_move, out);
  return out;
}

long gamestate_to_points(gamestate *gs) {
  long points = 0;
  // Score based on move type
  points += gs->my_move + 1;
  // Score based on win/loss
  points += big_scoring_algo(gs);
  printf("total points: %ld\n", points);
  return points;
}

// Translate moves into gamestate, count points
long play_round(char their_move, char my_move) {
  // Translate moves into gamestate
  gamestate gs = moves_to_gamestate(their_move, my_move);
  // Count points
  return gamestate_to_points(&gs);
}

int main() {
  long total_score = 0;

  // read input
#ifdef TEST
  const char *input_path = "test2";
#else
  const char *input_path = "input";
#endif

  FILE *fin = fopen(input_path, "r");
  char buff[255];
  while (fgets(buff, 255, fin) != NULL) {
    // we obviously hardcode this and spent an hour figuring out we switched inputs...
    char their_move = buff[0];
    char my_move = buff[2];
    printf("\nnew input line: %c %c\n", their_move, my_move);
    // Translate moves into gamestate, count points
    long current_score = play_round(their_move, my_move);
    total_score += current_score;

#ifdef TEST
    // check score
    long correct = strtol(buff + 4, NULL, 10);
    if (current_score != correct) {
      printf("!!!current score is not correct!!! LINE: %s\nIS: %ld, SHOULD BE "
             "%ld\n",
             buff, current_score, correct);
      exit(1);
    } else {
      printf("CORRECT ANSWER: %ld = %ld\n", current_score, correct);
    }
#endif
  }

  printf("\n***************** A *****************\n");
  printf("%ld\n", total_score);
}
