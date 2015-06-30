#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define NODE_LENGHT 4
#define NODE_MINIMUM 2

typedef struct bp_node {
	boolean isLeaf, isRoot;
	int size;
	int key[NODE_LENGHT];//satellites if aren't leafs
	//int pos[NODE_LENGHT +1]; //literaly position of the left/right node.
	struct bp_node[]* pos[NODE_LENGHT +1];
	struct bp_node* father;
	struct bp_node* previous;
	struct bp_node* next;
} bp_node;
