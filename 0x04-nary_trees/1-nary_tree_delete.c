#include "nary_trees.h"

/**
 * nary_tree_delete - deallocates n-ary tree
 * @tree: root of n-ary tree
 *
 * Return: Nothing
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *tmp_child = NULL, *tmp_node = NULL;

	if (!tree)
		return;
	tmp_child = tree->children;
	while (tmp_child)
	{
		nary_tree_delete(tmp_child->children);
		free(tmp_child->content);
		tmp_node = tmp_child->next;
		free(tmp_child);
		tmp_child = tmp_node;
	}
	free(tree->content);
	free(tree);
}
