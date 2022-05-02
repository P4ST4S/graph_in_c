/**
 * @file add_data.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function that add data to graph
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "graph.h"

void add_pixelarray(t_graph *graph, int idx, t_bunny_pixelarray *data)
{
    t_node_graph *node;

    if (idx >= graph->nb_vertices)
    {
        write(2, "Error: index not found\n", 24);
        return;
    }
    node = graph->tab_neighbours[idx].begin;
    if (!node)
    {
        write(2, "Error: this vertices isn't allocated\n", 38);
        return;
    }
    if (!node->data)
        node->data = bunny_new_pixelarray(data->clipable.buffer.width, data->clipable.buffer.height);
    else
    {
        bunny_delete_clipable(&node->data->clipable);
        node->data = bunny_new_pixelarray(data->clipable.buffer.width, data->clipable.buffer.height);
    }
    std_blit(node->data, data, NULL);
}