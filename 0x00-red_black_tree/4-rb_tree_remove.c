#include "rb_trees.h"

/**
 * min_value - gets the min value of a BST
 * @node: node to be search of
 *
 * Return: min value of the node
 */
rb_tree_t *min_value(rb_tree_t *node)
{
	rb_tree_t *current = node;

	while (current && current->left != NULL)
		current = current->left;
	return (current);
}

/**
 * rb_tree_remove - removes the red black tree indicated value
 * @root: root of the red black tree
 * @n: value to remove
 *
 * Return: Root of the tree
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *temp = NULL;

	if (root == NULL)
		return (root);
	if (n < root->n)
		root->left = rb_tree_remove(root->left, n);
	else if (n > root->n)
		root->right = rb_tree_remove(root->right, n);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = min_value(root->right);
		root->n = temp->n;
		root->right = rb_tree_remove(root->right, temp->n);
	}
	return (root);
}
