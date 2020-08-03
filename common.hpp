
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP

#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <boost/graph/adjacency_list.hpp>

class CartesianGraph;

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
// direction for cartesian logic
enum direction {
    right = 0, up = 1, back = 2, left = 3, down = 4, front = 5
};

// vertex = node
typedef std::list<CartesianGraph> graph_list;


// this typedef for our graph data
// we store the vector of each node's coordinates because
// post-initialisation the id can change if we cut graphs. also
// helps with statistics.
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d> graph_t;

// vertex index
// typedef uint32_t vertex_ind;
typedef boost::graph_traits<graph_t>::vertices_size_type vertex_ind;


// edge is a pair of indices
typedef std::pair<vertex_ind, vertex_ind> edge_t;

// vertex and edge descriptor
typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_descriptor_t;
typedef boost::graph_traits<graph_t>::edge_descriptor edge_descriptor_t;

// out_edge_iterator, vertex_iterator, adjacency_iterator
// adjacency_iterator is for neighborhood detection
typedef boost::graph_traits<graph_t>::out_edge_iterator out_edge_iterator_t;
typedef boost::graph_traits<graph_t>::vertex_iterator vertex_iterator_t;
typedef boost::graph_traits<graph_t>::adjacency_iterator adj_iterator_t;


// their corresponding lists
typedef std::list<vertex_descriptor_t> vertex_descriptor_list_t;
typedef std::list<edge_descriptor_t> edge_descriptor_list_t;


#endif //BASIC_INCLUDES_HPP
