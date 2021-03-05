#include "rb_trees.h"
/**
 * array_to_rb_tree - converts an array into a red black tree
 * @array: array to be used
 * @size: size of the array
 *
 * Return: pointer to the root node of the created R-B tree, or NULL on failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i = 0;
	rb_tree_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		rb_tree_insert(&root, array[i]);
	}
	while (root && root->parent)
		root = root->parent;
	return (root);
}
