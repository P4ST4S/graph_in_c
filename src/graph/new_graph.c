/**
 * @file new_graph.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function create a new graph
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "graph.h"

t_graph *new_graph(int vertices, bool oriented)
{
    int loop = 0;
    t_graph *elem;

    if (!(elem = malloc(sizeof(*elem))))
    {
        write(2, "Error: malloc() of elem\n", 25);
        exit(EXIT_FAILURE);
    }
    elem->oriented = oriented;
    elem->nb_vertices = vertices;
    if (!(elem->tab_neighbours = malloc(sizeof(t_graph) * vertices)))
    {
        write(2, "Error: malloc() elem->tab_neighbours\n", 38);
        exit(EXIT_FAILURE);
    }
    while (loop < elem->nb_vertices)
        elem->tab_neighbours[loop++].begin = NULL;
    return (elem);
}