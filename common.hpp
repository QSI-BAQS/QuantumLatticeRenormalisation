
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP


#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include "Graph/CartesianGraph.hpp"

class CartesianGraph;

class CartesianVertex;


// vertex = node
typedef CartesianVertex Node;

// data structure typedefs
typedef std::list<CartesianVertex> vertex_list;
typedef uint32_t vertex_ind;

typedef std::unordered_set<CartesianVertex> vertex_set;
typedef std::list<CartesianGraph> graph_list;

// direction for cartesian logic
enum direction {
    right = 0, up = 1, back = 2, left = 3, down = 4, front = 5
};

// this typedef for our graph data
// we store the vector of each node's coordinates because
// post-initialisation the id can change if we cut graphs. also
// helps with statistics.
typedef adjacency_list<vecS, vecS, undirectedS, vec3d> graph_type;

// edge is a pair of indices
typedef std::pair<vertex_ind, vertex_ind> edge_t;

// vertex and edge descriptor
typedef boost::graph_traits<graph_type>::vertex_descriptor vertex_descriptor_t;
typedef boost::graph_traits<graph_type>::edge_descriptor edge_descriptor_t;

// their corresponding lists
typedef std::list<vertex_descriptor_t> vertex_descriptor_list_t;
typedef std::list<edge_descriptor_t> edge_descriptor_list_t;

// vectors
struct vec2d {
    int x;
    int y;
};
struct vec3d {
    int x;
    int y;
    int z;
};

#endif //BASIC_INCLUDES_HPP

