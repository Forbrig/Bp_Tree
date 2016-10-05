#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bp_node.h"


void print_main() {
	printf("Wellcome to bp_tree 0.1 (ALPHA)!\n");
	printf("Chose an option:\n");
	printf("1 - Insert a key;\n");
	printf("2 - Search a key;\n");
	printf("3 - Insert 'n' random keys;\n");
	printf("4 - Print the tree;\n");
}

int main () {
	//print_main();
	bp_node* root;
	root = new_node();
	root->isRoot = true;
	
	insert_key(root, 10);
	insert_key(root, 12);
	insert_key(root, 11);
	insert_key(root, 13);
	insert_key(root, 14);
	/*
	insert_key(root, 15);
	insert_key(root, 16);
	*/
	print_tree(root);
	return 0;
}
