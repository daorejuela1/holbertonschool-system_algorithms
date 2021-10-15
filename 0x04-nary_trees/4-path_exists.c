#include "nary_trees.h"

/**
 * path_finder - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 * @path: path to find
 *
 * Return:  return the biggest depth of the tree pointed to by root
 */
static int path_finder(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t const *next_node = NULL;

	if (!*path)
		return (1);
	if (!root)
		return (0);
	next_node = root;
	while (next_node)
	{
		if (strcmp(*path, next_node->content) == 0)
			if (path_finder(next_node->children, path + 1) == 1)
				return (1);
		next_node = next_node->next;
	}
	return (0);
}

/**
 * path_exists - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 * @path: List of strings to represent the path
 *
 * Return:  return the biggest depth of the tree pointed to by root
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	if (!root || !path)
		return (0);
	return (path_finder(root, path));
}
