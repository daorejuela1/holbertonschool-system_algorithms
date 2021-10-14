#include "nary_trees.h"
static nary_tree_t *create_node(char const *str)
{
	nary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(nary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->content = calloc(strlen(str) + 1, 1);
	if (!new_node->content)
		return (NULL);
	strcpy(new_node->content, str);
	new_node->parent = NULL;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * nary_tree_insert - inserts a new node in a N nary tree
 * @parent: pointer to the parent node
 * @str: string to be stored
 *
 * Return: return a pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node = NULL;

	if (!str)
		return (NULL);
	new_node = create_node(str);
	if (!new_node)
		return (NULL);
	if (!parent)
		return (new_node);

	new_node->parent = parent;
	new_node->next = parent->children;
	parent->children = new_node;
	parent->nb_children++;
	return (new_node);
}
