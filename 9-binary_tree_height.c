#include "binary_trees.h"

/**
 * measure_branches - measure the subbranches of the tree
 * @t: node of the root or sub-root of the tree
 * @l: place to store the height down the left
 * @r: place to store the height down the right
*/
static void measure_branches(const binary_tree_t *t, int *l, int *r)
{
	*l = t->left ? 1 + binary_tree_height(t->left) : 0;
	*r = t->right ? 1 + binary_tree_height(t->right) : 0;
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int counters[2];

	if (tree == NULL)
		return (0);

	measure_branches(tree, &counters[LEFT], &counters[RIGHT]);

	return (
		(counters[LEFT] > counters[RIGHT]) ? counters[LEFT] : counters[RIGHT]
	);
}
