#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

/*
 * Strucuture: Binary Search Tree
 * ------------------------------
 *  Ordered Binary Tree data structure
 *
 *  int val:      value stored in the node
 *  bst *larger:  link to child with larger val than self
 *  bst *smaller: link to child with smaller val than self
 */

struct bst
{
	int val;
	struct bst *larger;
	struct bst *smaller;
};

/*
 * Function: bst_create
 * --------------------
 *  Creates a new Binary Search Tree node
 *
 *  int value: the value to be stored in the node
 *
 *  returns the newly created node
 */

struct bst* bst_create(int value);

/*
 * Function: bst_insert
 * --------------------
 *  Inserts given node to the given search tree
 *
 *  bst *node:     the head of search tree
 *  bst *new_node: the new node to be added
 *
 *  returns 0 if success,
 *          1 if a node with same value already exists
 */

int bst_insert(struct bst *node, struct bst *new_node);

/*
 * Function: bst_search
 * --------------------
 *  Searches for a node with given value in given tree
 *
 *  bst *node: the head of search tree
 *  int value: the value to look for
 *
 *  returns pointer to node if success,
 *          NULL if result is not found
 */

struct bst* bst_search(struct bst *node, int value);

/*
 * Function: bst_free
 * ------------------
 *  Frees up given node and all its children (i.e entire binary tree)
 *
 *  bst *node: the head node of the binary tree
 */

void bst_free(struct bst *node);

#endif
