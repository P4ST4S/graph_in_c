/**
 * @file add_node.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief function that create node
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "graph.h"

t_node_graph *add_node(int idx, t_bunny_pixelarray *data)
{
    t_node_graph *new_node;

    if (!(new_node = malloc(sizeof(*new_node))))
    {
        write(2, "Error: malloc() of new_node\n", 29);
        exit(EXIT_FAILURE);
    }
    new_node->linkedIdx = idx;
    new_node->next = NULL;
    if (data)
    {
        new_node->data = bunny_new_pixelarray(data->clipable.buffer.width, data->clipable.buffer.height);
        std_blit(new_node->data, data, NULL);
    }
    else
        new_node->data = NULL;
    return (new_node);
}