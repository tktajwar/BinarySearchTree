#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int main(int argc, char *argv[])
{
	/* exit if no command line argument is given */
	if (!(argc > 1))
		return 1;

	/* create head node */
	struct bst *head = bst_create(atoi(argv[1]));

	/* insert all given int to the tree */
	for (int i = 2; i < argc; i++) {
		struct bst *new_node = bst_create(atoi(argv[i]));
		if (bst_insert(head, new_node)) /* insert new node */
			bst_free(new_node);     /* free if fails */
	}

	/* search for node with value */
	int search_val;
	printf("Search: ");
	while (scanf("%d", &search_val) != EOF) {
		if (bst_search(head, search_val))
			printf("%d found!\n", search_val);
		else
			printf("%d not found!\n", search_val);
		printf("Search: ");
	}

	return 0;
}
