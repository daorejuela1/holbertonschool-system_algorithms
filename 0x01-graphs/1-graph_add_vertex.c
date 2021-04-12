#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: pointer to the graph
 * @str: string value for new vertex
 * Return: pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *vertex;

	if (!graph || !str)
		return (NULL);
	vertex = graph->vertices;
	while (vertex && vertex->next)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		vertex = vertex->next;
	}
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);
	new_vertex->content = strdup(str);
	if (!new_vertex->content)
	{
		free(new_vertex);
		return (NULL);
	}
	new_vertex->index = graph->nb_vertices++;
	if (vertex)
		vertex->next = new_vertex;
	else
		graph->vertices = new_vertex;
	return (new_vertex);
}
