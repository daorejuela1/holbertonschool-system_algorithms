#include "graphs.h"
#include <stdlib.h>
#include <string.h>


/**
 * init_edge - initialize edge
 * @src: source vertex
 * @dest: destination vertex
 * Return: 1 on success 0 otherwise
 **/
static int init_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *new, **p;

	if (!dest || !src)
		return (0);
	p = &src->edges;
	while (*p)
	{
		if ((*p)->dest == dest)
			return (0);
		 p = &(*p)->next;
	}
	new = malloc(sizeof(edge_t));
	if (!new)
		return (0);
	new->dest = dest;
	new->next = NULL;
	*p = new;
	src->nb_edges += 1;
	return (1);
}

/**
 * get_vertex - gets the vertex from a graph
 * @graph: pointer to graph
 * @content: content of vertex
 * Return: vertex or null on failure
 **/
static vertex_t *get_vertex(graph_t *graph, const char *content)
{
	vertex_t *p;

	p = graph->vertices;
	while (p)
	{
		if (!strcmp(p->content, content))
			return (p);
		p = p->next;
	}
	return (p);
}

/**
 * graph_add_edge - adds an edge between two vertices in an existing graph
 * @graph:  pointer to the graph to add the edge to
 * @src: string identifying the vertex to make the connection from
 * @dest: string identifying the vertex to connect to
 * @type: type of edge.
 * Return:  return 1 on success, or 0 on failure
 **/
int graph_add_edge(
	graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *src_vertex, *dest_vertex;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (0);
	src_vertex = get_vertex(graph, src);
	if (!src_vertex)
		return (0);
	dest_vertex = get_vertex(graph, dest);
	if (!dest_vertex)
		return (0);
	if (type == UNIDIRECTIONAL)
		return (init_edge(src_vertex, dest_vertex));
	init_edge(src_vertex, dest_vertex);
	init_edge(dest_vertex, src_vertex);
	return (1);
}
