#ifndef H_NARY_TREES
#define H_NARY_TREES
/*
 * ==========================================================================
 *
 *       Filename:  nary_trees.h
 *
 *    Description: HEADER file to N-ry tree logic
 *
 *        Version:  1.0
 *        Created:  10/14/2021 08:07:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David Orejuela
 *   Organization:  HOLBERTON
 *
 * ==========================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct nary_tree_s - N-ary tree node structure
 *
 * @content: Content of the node
 * @parent: Pointer to the parent node
 * @nb_children: Number of children
 * @children: Pointer to the head node of the children linked list
 * @next: Pointer to the next child in the parent's children linked list
 */
typedef struct nary_tree_s
{
	char            *content;
	struct nary_tree_s  *parent;
	size_t          nb_children;
	struct nary_tree_s  *children;
	struct nary_tree_s  *next;
} nary_tree_t;

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str);
#endif
