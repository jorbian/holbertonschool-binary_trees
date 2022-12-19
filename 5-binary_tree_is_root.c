#include "binary_trees.h"

/**
 * binary_tree_is_root - determines whether or not a given node is a root
 * @node: the node to be tested
 *
 * Return: '0' if it's not a leaf, '1' if it is.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if ((node->right != NULL) && (node->left != NULL))
		return (1);

	return (0);
}
