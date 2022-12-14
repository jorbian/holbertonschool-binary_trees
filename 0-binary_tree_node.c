#include "binary_trees.h"

/**
 * binary_tree_node - creates a new node for a binary tree
 * @parent: parent node of the one to be created
 * @value: integer  value it is to be given
 *
 * Return: pointer to the new node.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (parent == NULL)
		return (NULL);

	parent->n = value;
	parent->parent = parent;
	parent->left = NULL;
	parent->right = NULL;

	return (new_node);
}
