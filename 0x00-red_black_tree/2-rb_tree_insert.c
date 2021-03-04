#include "rb_trees.h"
#include <limits.h>

/**
 *rotate_left - rotate node to the left
 *@root: tree node
 *@tree: tree node
 *Return: rotated node
 */
static rb_tree_t *rotate_left(rb_tree_t **root, rb_tree_t *tree)
{
	rb_tree_t *right = NULL;

	right = tree->right;
	tree->right = right->left;
	if (tree->right)
		tree->right->parent = tree;
	right->parent = tree->parent;
	if (!tree->parent)
		*root = right;
	else if (tree == tree->parent->left)
		tree->parent->left = right;
	else
		tree->parent->right = right;
	right->left = tree;
	tree->parent = right;
	return (tree);
}

/**
 *rotate_right - rotate node to the left
 *@root: tree node
 *@tree: tree node
 *Return: rotated node
 */
static rb_tree_t *rotate_right(rb_tree_t **root, rb_tree_t *tree)
{
	rb_tree_t *left = NULL;

	left = tree->left;
	tree->left = left->right;
	if (tree->left)
		tree->left->parent = tree;
	left->parent = tree->parent;
	if (!tree->parent)
		*root = left;
	else if (tree == tree->parent->left)
		tree->parent->left = left;
	else
		tree->parent->right = left;
	left->right = tree;
	tree->parent = left;
	return (tree);
}

/**
 * bst_insert - inserts a new node following bst rules
 *
 * @root: common red black tree parent
 * @value: new node to be added in the red black tree
 *
 * Return: red black tree with the added node
 */
static rb_tree_t *bst_insert(rb_tree_t **root, int value)
{
	rb_tree_t *node, *prev = NULL, *curr;

	if (!root)
		return (NULL);
	curr = *root;
	while (curr)
	{
		prev = curr;
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else
			return (NULL);
	}
	node = rb_tree_node(prev, value, RED);
	if (!node)
		return (NULL);
	if (!prev)
	{
		node->color = BLACK;
		*root = node;
		return (node);
	}
	if (value < prev->n)
		prev->left = node;
	else
		prev->right = node;
	return (node);
}

/**
 * fix_left - fixes RB subtree relative to left uncle
 * @root: address of pointer to root node
 * @new: pointer to node inserted node to start fix
 * Return: pointer to inserted node
 */
static rb_tree_t *fix_left(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *uncle = GRANDPARENT(new)->left;

	/* printf("FIX LEFT UNCLE [%d]\n", new->n); */
	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		new = GRANDPARENT(new);
	}
	else
	{
		if (new == PARENT(new)->left)
		{
			new = PARENT(new);
			rotate_right(root, new);
		}
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		rotate_left(root, GRANDPARENT(new));
	}
	return (new);
}

/**
 * fix_right - fixes RB subroot relative to right uncle
 * @root: address of pointer to root new
 * @new: pointer to new inserted new to start fix
 * Return: pointer to inserted new
 */
rb_tree_t *fix_right(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *uncle = GRANDPARENT(new)->right;

	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		new = GRANDPARENT(new);
	}
	else
	{
		if (new == PARENT(new)->right)
		{
			new = PARENT(new);
			rotate_left(root, new);
		}
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		rotate_right(root, GRANDPARENT(new));
	}
	return (new);
}
/**
 * conserve_properties - assures that rb is ok
 * @root: root new of the rb_root
 * @new: new added
 *
 */
void conserve_properties(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *grand_parent = NULL;

	while (new != *root && PARENT(new) && PARENT(new)->color == RED)
	{
		grand_parent = GRANDPARENT(new);
		if (PARENT(new) == grand_parent->left)
		{
			new = fix_right(root, new);
		}
		else
		{
			new = fix_left(root, new);
		}
	}
	(*root)->color = BLACK;
}

/**
 * rb_tree_insert -  inserts a value in a Red-Black Tree
 *
 * @root: pointer to the root of the rb root
 * @value: value to be added into the red black root
 *
 * Return:  pointer to the created new, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **root, int value)
{
	rb_tree_t *new_node = NULL;

	if (!root)
		return (NULL);
	new_node = bst_insert(root, value);
	if (!new_node)
		return (NULL);
	conserve_properties(root, new_node);
	return (new_node);
}
