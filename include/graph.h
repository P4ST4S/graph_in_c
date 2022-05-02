/**
 * @file graph.h
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief header file for graph
 * @version 0.3
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
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
typedef struct s_node_graph
{
    void *data;
    struct s_node_graph *next;
} t_node_graph;

/**
 * @brief adjency graph
 *
 */
typedef struct s_adjency_graph
{
    node_graph *begin;
} t_adjency_graph;

/**
 * @brief graph structure
 *
 */
typedef struct s_graph
{
    bool oriented;
    int nb_vertices;
    t_adjency_graph *tab_neighbours;
} t_graph;

/**
 * @brief new graph function
 *
 * @param vertices number of vertices
 * @param oriented true if graph is oriented, false if not
 * @return new Graph element
 * @return NULL on error
 */
t_graph *new_graph(int vertices, bool oriented);

/**
 * @brief function for verify if graph is empty or not
 *
 * @param graph graph you want to verify
 * @return true if is empty
 * @return false if isn't empty
 */
bool is_empty_graph(t_graph *graph);

/**
 * @brief function for add node to graph
 *
 * @param data the data you want to add
 * @return new node
 * @return NULL on error
 */
t_node_graph *add_node(void *data);

/**
 * @brief function for erase your graph
 *
 * @param graph the graph you want to erase
 */
void erase_graph(t_graph *graph);

/**
 * @brief the function that will add node to edge
 *
 * @param graph the graph you want to modify
 * @param dataDest the data of destination
 * @param srcId the source index (form 0)
 * @param dataSrc the data of source, if graph is oriented set to NULL
 * @param destId the destination index, if graph is not oriented set to 0
 */
void add_edge(t_graph *graph, void *dataDest, int srcId, void *dataSrc, int destId);

#endif /* __GRAPH_H__ */