// basic c implementation of set, uses an array of linked lists

typedef struct set_node {
    int key;
    struct set_node* next;
} set_node;

int set_hash(int key);

void set_insert(int key);

int set_contains(int key);

void set_remove_key(int key);

void set_print();
