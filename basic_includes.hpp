
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP


#include <list>
#include <unordered_set>

// defined in Graph
class Vertex;
typedef Vertex Node;

typedef std::list<Vertex> vertex_list;
typedef std::unordered_set<Vertex> vertex_set;
typedef u_int32_t vertex_index;

enum direction { right = 0 , up = 1, back = 2, left = 3 , down = 4 , front = 5 };

// vectors
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

