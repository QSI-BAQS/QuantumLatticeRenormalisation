
#ifndef DEBUG_GRAPH_HPP
#define DEBUG_GRAPH_HPP

#include <string>
#include <iomanip>
#include <ctime>
#include "../Graph/CartesianGraph.hpp"
#include "json.hpp"
#include <fstream>
#include <boost/algorithm/string.hpp>


static const std::string delim_space = " ";
static const std::string delim_comma = ",";

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


// For use with saving and loading.
nlohmann::json get_json_form(const graph_t &g);

nlohmann::json get_json_form(const graph_list_raw_t &list);


// Don't include coordinates in what we save to minimise space.
// Our own file type. (txt extension)
void save_graphs(const graph_list_raw_t &list, const std::string &filepath);

// For use with blender plugin.
// Json. (json extension)
void save_graphs_json(const graph_list_raw_t &g, const std::string &filepath);

// When the file can't be opened, we will return an empty instance.

// Load our graph file type.
graph_list_raw_t load_graphs(const std::string &filepath);

// Load the json file type.
graph_list_raw_t load_graphs_json(const std::string &filepath);


#endif // DEBUG_GRAPH_HPP