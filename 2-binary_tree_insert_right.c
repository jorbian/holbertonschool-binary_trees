#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node in parents' right
 * @parent: parent of the node to be added
 * @value: numberic value
 * 
 * Return: pointer to the new node.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	if (parent->right != NULL)
		free(parent->right);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	parent->right = new_node;

	return (new_node);
}
