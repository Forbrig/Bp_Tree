#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bp_node new_node(int key);
void insert_key(bp_node node, int key);
void destroy_node(bp_node node);
void split_node(int v[]);
bp_node merge_node(bp_node left, bp_node right, bp_node me);
bp_node insert_node(bp_node root);
bp_node search_node(bp_node node);
