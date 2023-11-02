#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t counters[2];
																										
	if (tree == NULL)
		return (0);

	counters[LEFT] = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	counters[RIGHT] = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (
		(counters[LEFT] > counters[RIGHT]) ? counters[LEFT] : counters[RIGHT]
	);
}
