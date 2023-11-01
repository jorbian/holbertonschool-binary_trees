#include "binary_trees.h"

/**
 * binary_tree_balance - Measure balance factor of binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, returns 0, else returns balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (
		find_height(tree->left) - find_height(tree->right)
	);
}

/**
 * find_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
static size_t find_height(const binary_tree_t *tree)
{
	size_t counters[2];

	if (tree == NULL)
		return (0);

	counters[LEFT] = tree->left ? 1 + find_height(tree->left) : 0;
	counters[RIGHT] = tree->right ? 1 + find_height(tree->right) : 0;

	return (
		(counters[LEFT] > counters[RIGHT]) ? counters[LEFT] : counters[RIGHT]
	);
}
