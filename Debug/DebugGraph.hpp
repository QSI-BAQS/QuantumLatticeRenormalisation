
#ifndef DEBUG_GRAPH_HPP
#define DEBUG_GRAPH_HPP

#include <string>
#include "../Graph/CartesianGraph.hpp"


std::string print_edges(const graph_t &g);

// Format below. Note there is a newline at the end.
/*
Graph 1: (0,1) (1,2) (3,0)
Graph 2: (0,1) (1,2) (3,1)
Graph 3: (0,1) (1,2) (3,2)

 */
std::string print_edges_all_graphs(const graph_list_raw &g);


#endif // DEBUG_GRAPH_HPP