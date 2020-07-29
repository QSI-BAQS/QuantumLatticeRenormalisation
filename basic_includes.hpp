
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP


#include <list>
#include <unordered_set>

// defined in CartesianGraph
class Vertex;
class CartesianGraph;

// vertex = node
typedef Vertex Node;

// data structure typedefs
typedef std::list<Vertex> vertex_list;
typedef std::unordered_set<Vertex> vertex_set;
typedef u_int32_t vertex_index;

typedef std::list<CartesianGraph> graph_list;

// direction for cartesian logic
enum direction { right = 0 , up = 1, back = 2, left = 3 , down = 4 , front = 5 };

// vectors (follow inheritance so we can easily change 2d to 3d)
struct vec {};
struct vec2d : vec {
    int x;
    int y;
};
struct vec3d : vec {
    int x;
    int y;
    int z;
};

#endif //BASIC_INCLUDES_HPP

