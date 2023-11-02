#include "binary_trees.h"

/**
 * binary_tree_sibling - finds node sibling (if it even has one)
 * @node: node to find sibling of
 *
 * Return: Pointer to node sibling -- or NULL --
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL, *parent = node->parent;

	if (!node || !parent)
		return (NULL);

	if (parent->right != node)
		sibling = parent->right;
	else if (parent->left != node)
		sibling = parent->left;

	return (sibling);
}
