#include "binary_trees.h"

static binary_tree_t **get_left(binary_tree_t *node)
{
	return (&(node->left));
}


static binary_tree_t *insert_node(binary_tree_t *parent, int value, binary_tree_t **(*get_side)(binary_tree_t *))
{
	binary_tree_t *new;
	binary_tree_t **parent_side;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	parent_side = get_side(parent);

	if (*parent_side != NULL)
	{
		(*parent_side)->parent = new;
	}
	parent_side = &new;

	return (new);
}

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	return (insert_node(parent, value, get_left));
}