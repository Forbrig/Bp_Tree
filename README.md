# Bp_Tree
A C implementation of B+ Tree. This implementation don't accept keys with duplicate values.

Main features:

 * In operation like insertion or exclusion the tree maintain his balancing.

 * Mantain an minimum ocupation per node (50%), except in the root (if the balancing on exclusion is implemented).

 * To search a register we need to pass all the height of the tree, that means we will pass through the root and one node per height until we reach the leaf.

The B+ Tree maintain, usually, 67% of the ocupation of the space.

The node formate:
	A node contain n entries for the index and n+1 pointers for the sons. The satellites are the indexes of a node that don't is a leaf, they are mean to search the position or the key that we need this way:
	* The pointer Pi reffers the subtree that all the values of the key K (satellite) are Ki <= K < Ki+1.

	Just a node leaf contain entries of data.
