#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

struct bst* bst_create(int value)
{
	struct bst *node = (struct bst *) malloc(sizeof(struct bst));
	node->val = value;
	node->larger = NULL;
	node->smaller = NULL;
	return node;
}

int bst_insert(struct bst *node, struct bst *new_node)
{
	if (new_node->val == node->val)
		return 1;
	if (new_node->val > node->val) {
		if (node->larger)
			return bst_insert(node->larger, new_node);
		else
			node->larger = new_node;
	}
	else {
		if (node->smaller)
			return bst_insert(node->smaller, new_node);
		else
			node->smaller = new_node;
	}
	return 0;
}

struct bst* bst_search(struct bst *node, int value)
{
	if (value == node->val) {
		return node;
	}
	else if (value > node->val) {
		if (node->larger)
			return bst_search(node->larger, value);
	}
	else {
		if (node->smaller)
			return bst_search(node->smaller, value);
	}
	return NULL;
}

void bst_free(struct bst *node)
{
	/* free larger child and its children */
	if (node->larger)
		bst_free(node->larger);
	/* free smaller child and its children */
	if (node->smaller)
		bst_free(node->smaller);
	/* free self */
	free(node);
}

void bst_print(struct bst *node)
{
	if (node == NULL)
		return;

	/* print larger/left child */
	if (node->larger) {
		printf("  %d\n", node->larger->val);
		printf(" /\n");
	}
	else
		printf(" (NULL)\n");

	/* print self */
	printf("%d\n", node->val);

	/* print larger/left child */
	if (node->smaller) {
		printf(" \\\n");
		printf("  %d\n", node->smaller->val);
	}
	else
		printf(" (NULL)\n");

	/* recurse through children */
	bst_print(node->larger);
	bst_print(node->smaller);
}
