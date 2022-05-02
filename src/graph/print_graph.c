/**
 * @file print_graph.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function that print your graph
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "graph.h"
#include <stdio.h>

void print_graph(t_graph *graph)
{
    t_node_graph *node;
    int loop = 0;

    if (is_empty_graph(graph))
    {
        write(2, "Error: graph is empty or doesn't exist\n", 40);
        return;
    }
    while (loop < graph->nb_vertices)
    {
        node = graph->tab_neighbours[loop].begin;
        printf("(%d) is linked to : ", loop);
        while (node != NULL)
        {
            printf("%d, ", node->linkedIdx);
            node = node->next;
        }
        printf("NULL\n");
        loop++;
    }
}