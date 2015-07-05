#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bp_node.h"

//create a new empty node;
bp_node* new_node() {
	bp_node* new = (bp_node *) malloc (sizeof(bp_node));
	new->size = 0;
	new->isLeaf = false;
	new->isRoot = false;
	new->father = NULL;
	new->previous = NULL;
	new->next = NULL;
	int i;
	for (i = 0; i < (NODE_LENGHT +1); i++) {
		new->pos[i] = NULL;
	}
	return new;
}

//search the node that will receive the new key
//recursion
//means ok
bp_node* search_node(bp_node* root, int key) {
	if (root->isLeaf == false) {
		int i;
		for (i = 0; i < NODE_LENGHT && root->pos[i]; i++) {
			if (key < root->key[i]) {
				//left of the satellite
				search_node (root->pos[i], key);
			} else if (root->size == i + 1) { //i + 1 because size never is zero in this case
				//right of the most right satellite
				search_node (root->pos[i + 1], key);
			}
		}
	}
	//searched!
	return root;
}

//miscelaneous
int mid_node( ) {
	if (NODE_LENGHT % 2 == 0) {
		return NODE_LENGHT / 2;
	} else {
		return (NODE_LENGHT -1) / 2;
	}
}

//update pointers o/
void update_pointers(bp_node* father, bp_node* r, int index) {
	father->pos[index+1] = r;
}

//all internal splits are caused by splits in the leaves
//danger zone, hard work (needs understand)
bp_node* split_node(bp_node* x) {
	int i, j;
	bp_node* new;
	new = new_node();
	x->size = mid_node();
	if (NODE_LENGHT % 2 == 0) {
		new->size = mid_node();
		for (j = 0, i = (mid_node() + 1); i < NODE_LENGHT; i++, j++) {
			new->key[j] = x->key[i];
		}
	} else {
		new->size = mid_node() + 1;
		for (j = 0, i = mid_node(); i < NODE_LENGHT; i++, j++) {
			new->key[j] = x->key[i];
		}
	}
	return new;
}

bp_node* best_node_for_this_key(bp_node* l, bp_node* r, int key) {
	if (l->key[l->size] < key) {
		return r;
	} else {
		return l;
	}
}

//insert once and for all
//and push "pointers" to forward 
int insert_key2(bp_node* x, int key) {
	int aux, flag = -1;
	int i, j;
	bp_node* n;
	bp_node* n2;
	//simple ordenation
	for (i = 0; i < x->size - 1; i++) {
		if (key < x->key[i]) {
			aux = x->key[i];
			x->key[i] = key;
			key = aux;
			//update pointers
			if (flag == -1) {
				flag = i;
				n = x->pos[i+1];
				for (j = i + 1; j < x->size; j++) {
					n2 = x->pos[j+1];
					x->pos[j+1] = n;
					n = n2;
				}
				x->pos[x->size] = n;
			}
				
		} else { 
			i++;
		}
	}
	x->size++;
	return flag; //return the index of the new element
}


//pre insert a new key on a leaf (root can be a leaf!)
//cases of insertion
void insert_key(bp_node* root, int key) {
	int index; //index of the new satellite, ifs needed
	bp_node* aux;
	bp_node* aux2;
	aux = search_node(root, key);
	//case 1: the leaf is not full
	if (aux->size < NODE_LENGHT) {
		insert_key2(aux, key);
	//case 2: the leaf is full
	} else if (aux->size == NODE_LENGHT) {
		//split!
		aux2 = split_node(aux);
		//make sure thats (right/left) is the best place
		index = insert_key2(best_node_for_this_key(aux, aux2, key), key);
		//case 2.1: the node is root, depth is increased
		if(aux->isRoot == true) {
			bp_node* new;
			new = new_node();
			new->isRoot = true;
			insert_key(new, aux2->key[0]);
			new->pos[0] = aux;
			update_pointers(new, aux2, 0); // same = new->pos[1] = aux2;
			aux->isRoot = false;
			aux2->isRoot = false;
		//case 2.2: if the internal node dont needs to split
		} else if (aux->father && aux->father->size < NODE_LENGHT) {
			insert_key2(aux->father, aux2->key[0]);
			update_pointers(aux->father, aux2, index);
		//case 2.3: an internal node needs to split
		} else if (aux->father && aux->father->size == NODE_LENGHT) {
			insert_key(aux->father, aux2->key[0]);
			update_pointers(aux->father, aux2, index);
		}
	}
}
