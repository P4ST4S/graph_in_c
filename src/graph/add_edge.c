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

void add_edge(t_graph *graph, void *dataDest, int srcId, void *dataSrc, int destId)
{
    t_node_graph *node;

    node = add_node(dataDest);
    node->next = graph->tab_neighbours[srcId].begin;
    graph->tab_neighbours[srcId].begin = node;
    if (!graph->oriented)
    {
        if (!dataSrc)
        {
            write(2, "Error: dataSrc is set to NULL but graph is not oriented\n", 57);
            return;
        }
        node = add_node(dataSrc);
        node->next = graph->tab_neighbours[destId].begin;
        graph->tab_neighbours[destId].begin = node;
    }
}