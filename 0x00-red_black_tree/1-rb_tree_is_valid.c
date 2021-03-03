#include "rb_trees.h"
#include <limits.h>
/**
 * helper - helper func for binary_tree_is_bst
 * @tree: pointer to tree node
 * @min: minimum value of BST tree
 * @max: maximum value of BST tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
static int helper(const rb_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (helper(tree->left, min, tree->n - 1) &&
		helper(tree->right, tree->n + 1, max));
}


/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root of tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
static int is_bst(const rb_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
/**
 * check_colors - checks that the colors in the red black tree are ok
 * @tree: red black tree node
 * Return: 1 if no error found 0 otherwise
 */
static int check_colors(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED)
	{
		if (tree->left && tree->left->color != BLACK)
			return (0);
		if (tree->right && tree->right->color != BLACK)
			return (0);
	}
	if (!check_colors(tree->left) || !check_colors(tree->right))
		return (0);
	return (1);
}
/**
 * black_count - counts the number of black nodes
 * @tree: node counter
 * @left: left branch counter
 * @right: right branch counter
 *
 * Return: 1 if black count is the same 0 otherwise
 */
static int black_count(const rb_tree_t *tree, int left, int right)
{
	int left_sum = 0, right_sum = 0;

	if (!tree)
		return (1);
	if (tree->left && tree->left->color == BLACK)
		left_sum = 1;
	if (tree->right && tree->right->color == BLACK)
		right_sum = 1;
	left = black_count(tree->left, left, right) + left_sum;
	right = black_count(tree->right, left, right) + right_sum;
	if (left != right)
		return (0);
	return (1);
}
/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: node of the root of the tree
 *
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree || tree->color != BLACK)
		return (0);
	return (is_bst(tree) && check_colors(tree) && black_count(tree, 0, 0));
}
