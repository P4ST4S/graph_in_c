/*
 ** @ Author: antoine.rospars@ecole-89.com
 ** @ Create Time: 2022-05-01 20:30:15
 ** @ Modified by: Antoine ROSPARS
 ** @ Modified time: 2022-05-01 21:09:25
 ** @ Copyright: 2022 © Antoine ROSPARS / antoine.rospars@ecole-89.com - All Rights Reserved.
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief implementation of memcpy function made by me
 *
 * @param dest the destination of memory copied
 * @param src the source of memory copied
 * @param n the length of the source memory
 */
void std_memcpy(void *dest, void *src, size_t n);

/**
 * @brief graph node (vertices)
 *
 */
typedef struct node_graph
{
    void *data;
    struct node_graph *next;
} node_graph, *node;

/**
 * @brief adjency graph
 *
 */
typedef struct adjency_graph
{
    node_graph *begin;
} adjency_graph, *adjency;

/**
 * @brief graph structure
 *
 */
typedef struct graph_element
{
    bool oriented;
    int nb_vertices;
    adjency tab_neighbours;
} graph_element, *Graph;

/**
 * @brief new graph function
 *
 * @param vertices number of vertices
 * @param oriented true if graph is oriented, false if not
 * @return new Graph element
 * @return NULL on error
 */
Graph new_graph(int vertices, bool oriented);

/**
 * @brief function for verify if graph is empty or not
 *
 * @param graph graph you want to verify
 * @return true if is empty
 * @return false if isn't empty
 */
bool is_empty_graph(Graph graph);

/**
 * @brief function for add node to graph
 *
 * @param data the data you want to add
 * @return new node
 * @return NULL on error
 */
node add_node(void *data);

#endif /* __GRAPH_H__ */