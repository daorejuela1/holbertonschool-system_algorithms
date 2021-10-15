#include "nary_trees.h"


/**
 * biggest_depth - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 * @action: pointer to a function to execute for each node being traversed.
 * @depth: counter of the current depth
 * Return:  return the biggest depth of the tree pointed to by root
 */
static size_t biggest_depth(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth), size_t depth)
{
	nary_tree_t *child = NULL;
	unsigned int big_depth, current_depth;

	action(root, depth);
	child = root->children;
	big_depth = depth;
	while (child)
	{
		current_depth = biggest_depth(child, action, depth + 1);
		if (current_depth > big_depth)
			big_depth = depth;
		child = child->next;
	}
	return (big_depth);
}
/**
 * nary_tree_traverse - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 * @action: pointer to a function to execute for each node being traversed.
 *
 * Return:  return the biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth))
{

	if (!root)
		return (0);
	return (biggest_depth(root, action, 0));
}
