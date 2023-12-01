#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fs_tree.h"

/* #define TEST */
#define BUFF_SIZE 5000
#define MAX_DIR_SIZE 100000

/* $ cd / */
/* $ ls */
/* dir a */
/* 14848514 b.txt */
/* 8504156 c.dat */
/* dir d */
/* $ cd .. */
/* $ cd phslrcw */
fs_tree_t *process_line(char *buff, fs_tree_t *tree) {
  // parsing
  if (buff[0] == '$') {
    // command
    if (buff[2] == 'c') {
      // cd
      if (buff[5] == '.') {
        // cd ..
        /* printf("cd to parent %s\n", tree->parent->name); */
        tree = tree->parent;
        if (tree == NULL) {
          /* printf("ERROR: tree parent not found when cd .. directive was " */
                 /* "present\n"); */
          assert(0);
        }

        return tree;
      } else {
        // cd dirname, find dirname
        buff[strlen(buff) - 1] = (char)0; // skip newline
        char *dirname = buff + 5;
        /* printf("cd to dir: %s\n", dirname); */
        tree = fs_tree_search_child(tree, dirname);
        if (tree == NULL) {
          /* printf("ERROR: tree child not found after searching, impossible\n"); */
          assert(0);
        }
        // right tree found

        return tree;
      }
    } else {
      // ls -> ignore

      return tree;
    }
  } else {
    // result
    if (isdigit(buff[0])) {
      // size filename, create file
      size_t filesize = strtol(buff, &buff, 10);
      buff++;                           // skip space
      buff[strlen(buff) - 1] = (char)0; // skip newline
      char *filename = buff;
      /* printf("create file: %s size: %zu\n", filename, filesize); */
      fs_tree_insert(tree, filename, fs_file, filesize);

      return tree;
    } else {
      // dir, create dir
      buff[strlen(buff) - 1] = (char)0; // skip newline
      char *dirname = buff + 4;
      /* printf("create dir: %s\n", dirname); */
      fs_tree_insert(tree, dirname, fs_dir, 0);

      return tree;
    }
  }
}

// pass root
void sum_small_dir_sizes(fs_tree_t *tree, long *sum) {
  if (tree->filetype == fs_dir) {
    if (tree->size <= MAX_DIR_SIZE) {
      *sum += tree->size;
    }
  }
  for (size_t i = 0; i < tree->num_children; i++) {
    sum_small_dir_sizes(tree->children[i], sum);
  }
  return;
}

int main() {
  // init
  long answer = 0;

  // tree
  char *name = "/";
  enum fs_filetype_t filetype = fs_dir;
  size_t size = 0;
  fs_tree_t *tree = fs_tree_constructor(name, filetype, size, NULL);

  // read input
#ifdef TEST
  const char *input_path = "test";
#else
  const char *input_path = "input";
#endif
  FILE *fin = fopen(input_path, "re");
  char buff[BUFF_SIZE];

  // skip first line of input
  fgets(buff, BUFF_SIZE, fin);

  // construct fs tree
  while (fgets(buff, BUFF_SIZE, fin) != NULL) {
    /* printf("newline: %s", buff); */
    tree = process_line(buff, tree);
    fs_tree_print(fs_tree_find_root(tree), 0);
    /* printf("\n"); */
  }

  // calculate answer
  sum_small_dir_sizes(fs_tree_find_root(tree), &answer);

  /* printf("\n***************** Answer *****************\n"); */
  printf("%ld\n", answer);
}
