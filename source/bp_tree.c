#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "bp_tree.h"

//create a new empty node;
bp_node new_node () {
	bp_node* new = (bp_node *) malloc (sizeof(bp_node));
	new->size = 0;
	new->isLeaf = false;
	new->isRoot = false;
	new->father = NULL;
	new->previous = NULL;
	new->next = NULL;
	for (i = 0; i < (NODE_LENGHT +1); i++) {
		new->pos[i] = NULL;
	}
	return new;
}

//search the node that will receive the new key
//recursion
//means ok
bp_node search_node(bp_node root, int key) {
	if (root->isLeaf == false) {
		for (i = 0; i < NODE_LENGHT && root->pos[i]; i++) {
			if (key <= root->key[i]) {
				//left of the satellite
				search_node (root->pos[i], key);
			} else if (root->size == i + 1) { //i + 1 because size never is zero in this case
				//right of the most right satellite
				search_node (root->pos[i + 1], key);
			}
		}
	} else {
		//searched!
		return root;
	}
}

//miscelaneous
int mid_node( ) {
	if (NODE_LENGHT % 2 == 0) {
		return NODE_LENGHT / 2;
	} else {
		return (NODE_LENGHT -1) / 2;
	}
}

void split_node(bp_node x) {
	int i, j;
	bp_node* new = new_node();
	for (j = 0, i = (mid_node() + 1); i < NODE_LENGHT; i++, j++) {
		new->key[j] = x->key[i];
	
}


//pre insert a new key on a leaf (root can be a leaf!)
//cases of insertion
void insert_key(bp_node x, int key) {
	bp_node* aux;
	aux = search_node (root, key);
	//case 1: the leaf is not full
	if (aux->size < NODE_LENGHT) {
		insert_key2(x, key);
	//case 2: the leaf is full
	} else if (aux->size == NODE_LENGHT) {
	}
}

//insert once and for all 
void insert_key2(bp_node x, key) {
	//redistribuir os elementos do nodo
	
	
	
}












