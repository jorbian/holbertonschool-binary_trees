#include "binary_trees.h"

/**
 * avl_search - Search an AVL tree and return the node that has the value
 * @node: The tree/subtree/node to search
 * @value: The value to search for in the tree
 * Return: The address of the node that stores the value, NULL if not found
*/

avl_t *avl_search(avl_t *node, int value)
{
	if (node == NULL)
		return (NULL);
	else if (node->n == value)
		return (node);
	else if (value < node->n)
		return (avl_search(node->left, value));
	else
		return (avl_search(node->right, value));
}

/**
 * rotate_avl - Rotate the AVL tree so that it is balanced again
 * @node: The address of the pointer to the node to rotate around
 * @value: The value that is being saved into the AVL tree
 * Return: void
 */
void rotate_avl(avl_t **node, int value)
{
	int balance;

	balance = binary_tree_balance(*node);

	if (balance > 1 && value < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (balance > 1 && value > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * avl_inserter - Inserts the value into the AVL tree
 * @tree: The address of the pointer of the root node
 * @value: The value to store inside of the AVL tree
 * Return: The address of the newly created node
 */
avl_t *avl_inserter(avl_t **tree, int value)
{
	avl_t *new_node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}

		new_node = avl_inserter(&((*tree)->left), value);
		if (new_node)
			rotate_avl(tree, value);
		return (new_node);
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}

		new_node = avl_inserter(&((*tree)->right), value);
		if (new_node)
			rotate_avl(tree, value);
		return (new_node);
	}
	return (NULL);
}

/**
 * avl_insert - Add a value to an AVL tree
 * @tree: The address of the pointer to the root node of the AVL tree
 * @value: The value to add to the AVL tree
 * Return: The address of the newly created node, NULL if failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = avl_search(*tree, value);

	if (!new_node)
		new_node = avl_inserter(tree, value);

	return (new_node);
}
