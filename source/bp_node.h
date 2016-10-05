#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NODE_LENGHT 4

//typedef struct bp_node bp_node;
typedef struct _node {
	_Bool isLeaf, isRoot;
	int size; //who have values, (a leaf can be half full)
	int key[NODE_LENGHT]; //satellites if aren't leafs
	//int pos[NODE_LENGHT +1]; //literaly position of the left/right node.
	struct _node* pos[NODE_LENGHT +1]; //to walk on the tree, (left or right the chosen satellite)
	struct _node* father;
	struct _node* previous;
	struct _node* next;
} bp_node;

bp_node* new_node();
bp_node* search_node(bp_node*, int);
int mid_node();
void update_pointers(bp_node*, bp_node*, int);
bp_node* split_node(bp_node*);
bp_node* best_node_for_this_key(bp_node*, bp_node*, int);
int insert_key2(bp_node*, int);
void insert_key(bp_node*, int);
void print_tree(bp_node* root);
