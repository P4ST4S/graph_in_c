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

t_node_graph *add_node(void *data)
{
    t_node_graph *new_node;

    if (!(new_node = malloc(sizeof(*new_node))))
    {
        write(2, "Error: malloc() of new_node\n", 29);
        exit(EXIT_FAILURE);
    }
    std_memcpy(new_node->data, data, sizeof(data));
    new_node->next = NULL;
    return (new_node);
}