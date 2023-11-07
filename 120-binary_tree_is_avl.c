#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
static int binary_tree_height(const binary_tree_t *tree)
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

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
bool binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (false);

	if(
		(abs(
			(binary_tree_height(tree->left)) - (binary_tree_height(tree->right)
		)) <= 1) &&
		(binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
	)
		return (true);

   return (false);
}
