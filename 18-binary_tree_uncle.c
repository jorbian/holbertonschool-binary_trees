#include "binary_trees.h"

/**
 * find_ancestor - asdf
 * @node: asdf
 * @gens_back: asdf
 *
 * Return: asdf
*/
static binary_tree_t *find_ancestor(binary_tree_t *node, int gens_back)
{
	binary_tree_t *parent = node->parent;

	if (!node)
		return (NULL);

	gens_back--;

	if (gens_back == 0)
		return (parent);
	else
		return (find_ancestor(parent, gens_back));
}

/**
 * binary_tree_uncle - finds node uncle if it has one
 * @node: node we're looking for the uncle of
 *
 * Return: point to uncle or NULL if parents or grands are missing
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (!node || !find_ancestor(node, 1) || !find_ancestor(node, 2))
		return (NULL);

	if (find_ancestor(node, 2)->right != find_ancestor(node, 1))
		uncle = find_ancestor(node, 2)->right;
	else if (find_ancestor(node, 2)->left != find_ancestor(node, 1))
		uncle = find_ancestor(node, 2)->left;

	return (uncle);
}
