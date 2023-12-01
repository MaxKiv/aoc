/*
 * Filesystem tree type, heap allocated
 */
#ifndef FS_TREE_H
#define FS_TREE_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp

#define FS_TREE_MAX_CHILDREN 100

// Filetype enum for fs_tree_t
enum fs_filetype_t { fs_file, fs_dir };

// Filesystem tree type
typedef struct fs_tree_t {
  // data members
  char *name;
  size_t size;
  enum fs_filetype_t filetype;
  // tree members
  size_t num_children;
  struct fs_tree_t *children[FS_TREE_MAX_CHILDREN];
  struct fs_tree_t *parent;
} fs_tree_t;

/*** fs_tree_t function declarations ***/
fs_tree_t *fs_tree_constructor(char *name, enum fs_filetype_t filetype,
                               size_t size, fs_tree_t *parent);
void fs_tree_destructor(fs_tree_t *node);
void fs_tree_insert(fs_tree_t *parent, char *name, enum fs_filetype_t filetype,
                    size_t size);
fs_tree_t *fs_tree_search_child(fs_tree_t *tree, char *dirname);
void fs_tree_print(fs_tree_t *tree, size_t depth);
/* void fs_tree_traverse(fs_tree_t *tree, char (*op)); */

/*** fs_tree_t function definitions ***/
// construct a new filesystem tree
fs_tree_t *fs_tree_constructor(char *name, enum fs_filetype_t filetype,
                               size_t size, fs_tree_t *parent) {
  fs_tree_t *node = malloc(sizeof(fs_tree_t));
  if (node == NULL) {
    // proper library stuff yeah
    /* printf("ERROR: no heap space for new tree node\n"); */
    assert(0);
  }
  node->name = malloc(sizeof(char) * strlen(name) + 1);
  if (node == NULL) {
    // proper library stuff yeah
    /* printf("ERROR: no heap space for new tree node member\n"); */
    assert(0);
  }
  strcpy(node->name, name);
  node->size = size;
  node->filetype = filetype;
  node->num_children = 0;
  node->parent = parent;
  return node;
}

// TODO this seems garbage
void fs_tree_destructor(fs_tree_t *node) {
  if (node->num_children == 0) {
    free(node->name);
    free(node);
    return;
  } else {
    for (size_t i = 0; i < node->num_children; i++) {
      fs_tree_destructor(node->children[i]);
    }
  }
}

// Insert a new node into a tree
void fs_tree_insert(fs_tree_t *node, char *name, enum fs_filetype_t filetype,
                    size_t size) {
  if (node == NULL) {
    // Go to jail, do not pass start
    /* printf("ERROR: parent == NULL in fs_tree_insert\n"); */
    assert(0);
  }
  if (node->num_children == FS_TREE_MAX_CHILDREN) {
    // Go to jail, do not pass start
    /* printf("ERROR: max size of children reached in fs_tree_insert\n"); */
    assert(0);
  }
  // insert new child node
  node->children[node->num_children++] =
      fs_tree_constructor(name, filetype, size, node);

  // if its a file -> update dir size of all parents
  if(filetype == fs_file) {
    fs_tree_t *parent = node;
    while(parent != NULL) {
      parent->size += size;
      parent = parent->parent;
    }
  }
}

fs_tree_t *fs_tree_search_child(fs_tree_t *tree, char *name) {
  for (size_t i = 0; i < tree->num_children; i++) {
    if (strcmp(tree->children[i]->name, name) == 0) {
      return tree->children[i];
    }
  }
  return NULL;
}

// print from node to root
void fs_tree_print_to_root(fs_tree_t *tree) {
  /* printf("%s ", tree->name); */
  if (tree->parent == NULL) {
    /* printf("\n"); */
    return;
  } else {
    fs_tree_print_to_root(tree->parent);
  }
}

fs_tree_t *fs_tree_find_root(fs_tree_t *tree) {
  if (tree->parent == NULL) {
    return tree;
  } else {
    return fs_tree_find_root(tree->parent);
  }
}

// this little maneuver is gonna cost us the entire stack!
void fs_tree_print(fs_tree_t *tree, size_t depth) {
  for (size_t i = 0; i < depth; i++) {
    /* printf("  "); */
  }
  char str[32];
  if (tree->filetype == fs_dir) {
    snprintf(str, 32, "(dir, size=%zu)", tree->size);
  } else {
    snprintf(str, 32, "(file, size=%zu)", tree->size);
  }
  /* printf("- %s %s\n", tree->name, str); */

  depth++;
  for (size_t i = 0; i < tree->num_children; i++) {
    fs_tree_print(tree->children[i], depth);
  }
}

#endif /* FS_TREE_H */
