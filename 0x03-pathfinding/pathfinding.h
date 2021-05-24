#ifndef _PATHFINDER_H
#define _PATHFINDER_H

#define RIGHT (x + 1)
#define BOTTOM (y + 1)
#define LEFT (x - 1)
#define TOP (y - 1)
#define STRDUP(x) ((str = strdup(x)) ? str : (exit(1), NULL))
#define ALLOCATE_ALL \
	do { \
		dists = calloc(graph->nb_vertices, sizeof(*dists)); \
		fists = calloc(graph->nb_vertices, sizeof(*fists)); \
		from = calloc(graph->nb_vertices, sizeof(*from)); \
		verts = calloc(graph->nb_vertices, sizeof(*verts)); \
	} while (0)
#define H(a) ((int)sqrt(pow((a->x - target->x), 2) + \
	pow((a->y - target->y), 2)))

#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "queues.h"
#include "graphs.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

queue_t *backtracking_array(char **map, int rows, int cols,
		point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
		vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
		vertex_t const *target);
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
		vertex_t const *target);
#endif
