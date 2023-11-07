#include "binary_trees.h"

/**
 * get_left - retrieve the left hand child node
 * @node: pointer to the node that's being looked at
 *
 * Return: A double pointer to the node on the side needed
*/
static binary_tree_t **get_left(binary_tree_t *node)
{
	return (&(node->left));
}

/**
 * insert_node - insert a node on the left or the right slot of the parent
 * @parent: the parent node being added to
 * @value: the value that will be stored in the new node.
 * @get_side: function pointer to the function that will dereference
 * needed side on parent node.
 *
 * Return: Pointer to the newly added node.
*/
static binary_tree_t *insert_node(
	binary_tree_t *parent, int value,
	binary_tree_t **(*get_side)(binary_tree_t *)
)
{
	binary_tree_t *new;
	binary_tree_t *parent_side, *new_side;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	parent_side = *get_side(parent);
	new_side = *get_side(new);

	if (new_side  != NULL)
	{
		new_side = parent_side;
		parent_side->parent = new;
	}
	parent_side = new;

	return (new);
}

/**
 * binary_tree_insert_left - insert a new node on a binary tree on left
 * @parent: parent node to the tree being added to
 * @value: the value of the new node
 *
 * Return: A pointer to the new node that was just added.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	return (insert_node(parent, value, get_left));
}
