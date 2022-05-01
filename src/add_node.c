/*
 ** @ Author: antoine.rospars@ecole-89.com
 ** @ Create Time: 2022-05-01 21:05:21
 ** @ Modified by: Antoine ROSPARS
 ** @ Modified time: 2022-05-01 21:11:57
 ** @ Copyright: 2022 © Antoine ROSPARS / antoine.rospars@ecole-89.com - All Rights Reserved.
 */

#include "graph.h"

node add_node(void *data)
{
    node new_node;

    if (!(new_node = malloc(sizeof(node_graph))))
    {
        write(2, "Error: malloc() of new_node\n", 29);
        exit(EXIT_FAILURE);
    }
    std_memcpy(new_node->data, data, sizeof(data));
    new_node->next = NULL;
    return (new_node);
}