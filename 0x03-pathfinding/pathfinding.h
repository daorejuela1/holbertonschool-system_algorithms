#ifndef _PATHFINDER_H
#define _PATHFINDER_H

#define RIGHT (x + 1)
#define BOTTOM (y + 1)
#define LEFT (x - 1)
#define TOP (y - 1)

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
#endif
