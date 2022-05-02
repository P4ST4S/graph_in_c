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

#include <lapin.h>
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
 * @brief function that copy src pixelarray in
 * target pixelarray
 *
 * @param target the target pixelarray
 * @param src the source pixelarray
 * @param pos position of the blit, NULL if you
 * want it in (0, 0)
 */
void std_blit(t_bunny_pixelarray *target, const t_bunny_pixelarray *src, const t_bunny_position *pos);

/**
 * @brief graph node (vertices)
 *
 */
typedef struct s_node_graph
{
    int linkedIdx;
    t_bunny_pixelarray *data;
    struct s_node_graph *next;
} t_node_graph;

/**
 * @brief adjency graph
 *
 */
typedef struct s_adjency_graph
{
    struct s_node_graph *begin;
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
 * @param oriented true if graph is oriented,
 * false if not
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
 * @brief function that create new node
 *
 * @param idx index of new node
 * @param data pixelarray for adventure,
 * NULL if you don't want to add one
 * @return t_node_graph* new_node
 */
t_node_graph *add_node(int idx, t_bunny_pixelarray *data);

/**
 * @brief function for erase your graph
 *
 * @param graph the graph you want to erase
 */
void erase_graph(t_graph *graph);

/**
 * @brief the function that will add node to edge,
 * if not oriented, source and destination is not
 * important
 *
 * @param graph the graph you want to modify
 * @param dest the destination index
 * @param src the source index
 */
void add_edge(t_graph *graph, int dest, int src);

/**
 * @brief function for print your graph
 *
 * @param graph the graph you want to print
 */
void print_graph(t_graph *graph);

/**
 * @brief function that add pixelarray to a
 * graph
 *
 * @param graph graph wher eyou want to stock
 * your pixelarray
 * @param idx index of the vertice where you
 * want to stock
 * @param data the pixelarray that you want to
 * stock
 */
void add_pixelarray(t_graph *graph, int idx, t_bunny_pixelarray *data);

#endif /* __GRAPH_H__ */