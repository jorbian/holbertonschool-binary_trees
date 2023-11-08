#include "binary_trees.h"

/**
 * get_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
static int get_height(const binary_tree_t *tree)
{
	int counters[2];
																										
	if (tree == NULL)
		return (0);

	counters[LEFT] = get_height(tree->left);
	counters[RIGHT] = get_height(tree->right);

	if (counters[LEFT] > counters[RIGHT])
		return (counters[LEFT] + 1);
	else
		return (counters[RIGHT] + 1);
}
/**
 * is_balanced - Check if the binary tree is balanced (not more than a
 * difference of 1 in height)
 * @tree: The tree or subtree to check
 * Return: true if balanced, false if unbalanced
*/
static bool is_balanced(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (true);
	else if (
		abs(get_height(tree->left) - get_height(tree->right)) > 1
	)
		return (false);
	else
		return (
			is_balanced(tree->left) &&
			is_balanced(tree->right)
		);
}
/**
 * validate_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lowest: The value of the smallest node visited thus far.
 * @highest: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
static int validate_avl(const binary_tree_t *tree, int lowest, int highest)
{
	int height[2];

	if (tree != NULL)
	{
		if (tree->n < lowest || tree->n > highest)
			return (0);

		height[LEFT] = get_height(tree->left);
		height[RIGHT] = get_height(tree->right);

		if (abs(height[LEFT] - height[RIGHT]) > 1)
			return (0);
		else
			return (
				validate_avl(tree->left, lowest, tree->n - 1) &&
				validate_avl(tree->right, tree->n + 1, highest) &&
				is_balanced(tree)
			);
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
bool binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (validate_avl(tree, INT_MIN, INT_MAX));
}
