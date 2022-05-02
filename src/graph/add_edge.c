/**
 * @file add_edge.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function that add node to your edge
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "graph.h"

void add_edge(t_graph *graph, int dest, int src)
{
    t_node_graph *node;

    if (dest >= graph->nb_vertices || src >= graph->nb_vertices)
    {
        write(2, "Error: invalid source or destination index\n", 44);
        return;
    }
    node = add_node(dest, NULL);
    node->next = graph->tab_neighbours[src].begin;
    graph->tab_neighbours[src].begin = node;
    if (!graph->oriented)
    {
        node = add_node(src, NULL);
        node->next = graph->tab_neighbours[dest].begin;
        graph->tab_neighbours[dest].begin = node;
    }
}