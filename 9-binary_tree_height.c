#include "binary_trees.h"

/**
 * measure_branches - measure the subbranches of the tree
 * @tree: node of the root or sub-root of the tree
 * @counters: pointer to counter array
*/
static void measure_branches(const binary_tree_t *tree, int *counters)
{
	counters[LEFT] = (
		(tree->left) ? 1 + binary_tree_height(tree->left) : 0
	);
	counters[RIGHT] = (
		(tree->right) ? 1 + binary_tree_height(tree->right) : 0
	);
}

/**
 * binary_tree_height - Measures the height of binary tree.
 * @tree: Pointer to root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int counters[2];

	if (tree == NULL)
		return (0);

	measure_branches(tree, (size_t *)&counters);

	return (MAX(counters[LEFT], counters[RIGHT]));
}
