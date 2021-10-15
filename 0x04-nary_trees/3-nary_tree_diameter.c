#include "nary_trees.h"

static int max_diam;

/**
 * tree_diameter - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 *
 * Return:  return the biggest depth of the tree pointed to by root
 */
static int tree_diameter(nary_tree_t *root)
{
	nary_tree_t *child = NULL;
	int max1 = 0, max2 = 0;
	int current_diameter = 0, diameter = 0;

	if (!root)
		return (-1);

	child = root->children;
	while (child)
	{
		diameter = tree_diameter(child);
		current_diameter = current_diameter > diameter ? current_diameter : diameter;
		if (diameter > max1)
			max2 = max1, max1 = diameter;
		else if (diameter > max2)
			max2 = diameter;
		child = child->next;
	}
	max_diam = (max1 + max2 + 1) > max_diam ? (max1 + max2 + 1) : max_diam;
	return (current_diameter + 1);
}

/**
 * nary_tree_diameter - goes through an N-ary tree, node by node.
 * @root: root node of the tree to traverse
 *
 * Return:  return the biggest depth of the tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	if (!root)
		return (0);
	tree_diameter((nary_tree_t *)root);
	return (max_diam);
}
