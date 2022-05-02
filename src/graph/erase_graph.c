/**
 * @file erase_graph.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function that erase your graph
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "graph.h"

void erase_graph(t_graph *graph)
{
    t_node_graph *node, *tmp;
    int loop = 0;

    if (is_empty_graph(graph))
    {
        write(2, "Error: your graph is already empty\n", 36);
        return;
    }
    if (graph->tab_neighbours)
    {
        while (loop < graph->nb_vertices)
        {
            node = graph->tab_neighbours[loop].begin;
            while (node != NULL)
            {
                tmp = node;
                if (tmp->data != NULL)
                    bunny_delete_clipable(&tmp->data->clipable);
                node = node->next;
                free(tmp);
                tmp = NULL;
            }
            loop++;
        }
        free(graph->tab_neighbours);
        graph->tab_neighbours = NULL;
    }
    free(graph);
    graph = NULL;
}