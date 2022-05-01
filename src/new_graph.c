/*
 ** @ Author: antoine.rospars@ecole-89.com
 ** @ Create Time: 2022-05-01 20:47:34
 ** @ Modified by: Antoine ROSPARS
 ** @ Modified time: 2022-05-01 20:57:33
 ** @ Copyright: 2022 © Antoine ROSPARS / antoine.rospars@ecole-89.com - All Rights Reserved.
 */

#include "graph.h"

Graph new_graph(int vertices, bool oriented)
{
    int loop = 0;
    graph_element *elem;

    if (!(elem = malloc(sizeof(graph_element))))
    {
        write(2, "Error: malloc() of elem\n", 25);
        exit(EXIT_FAILURE);
    }
    elem->oriented = oriented;
    elem->nb_vertices = vertices;
    if (!(elem->tab_neighbours = malloc(sizeof(adjency_graph) * vertices)))
    {
        write(2, "Error: malloc() elem->tab_neighbours\n", 38);
        exit(EXIT_FAILURE);
    }
    while (loop < elem->nb_vertices)
        elem->tab_neighbours[loop++].begin = NULL;
    return (elem);
}