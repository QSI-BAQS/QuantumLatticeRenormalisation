
#ifndef DEBUG_GRAPH_HPP
#define DEBUG_GRAPH_HPP

#include <string>
#include <iomanip>
#include <ctime>
#include "../Graph/CartesianGraph.hpp"
#include "json.hpp"


/*
(0,1) (1,2) (3,0)
*/
std::string print_edges(const graph_t &g);

/*
0,1 1,2 3,0
*/
std::string print_edges_reduced(const graph_t &g);


// Note there is a newline at the end.
/*
Graph 1: (0,1) (1,2) (3,0)
Graph 2: (0,1) (1,2) (3,1)
Graph 3: (0,1) (1,2) (3,2)

 */
std::string print_edges_all_graphs(const graph_list_raw_t &g);

std::string print_edges_all_graphs_reduced(const graph_list_raw_t &g);

std::string get_formatted_datetime();

void writeout_graph(const graph_t &g, const std::string &filepath);

void writeout_graph_with_coords(const graph_t &g, const std::string &filepath);


#endif // DEBUG_GRAPH_HPP