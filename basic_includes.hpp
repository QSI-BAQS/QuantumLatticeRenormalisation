
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP


#include <list>
#include <unordered_set>

class CartesianGraph;
class CartesianVertex;


// vertex = node
typedef CartesianVertex Node;

// data structure typedefs
typedef std::list<CartesianVertex> vertex_list;
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


// Hash function for CartesianVertex
template <class T>
inline void hash_combine(std::size_t & s, const T & v)
{
    std::hash<T> h;
    s^= h(v) + 0x9e3779b9 + (s<< 6) + (s>> 2);
}



typedef std::unordered_set<CartesianVertex> vertex_set;
class CartesianVertex {
public:
    explicit CartesianVertex(vec3d vector);
    vec3d vector;

namespace std {
    template<>
    struct hash<CartesianVertex> {
        size_t operator()(CartesianVertex const &s) const {
            std::size_t res = 0;
            hash_combine(res, s.vector.x);
            hash_combine(res, s.vector.y);
            hash_combine(res, s.vector.z);
            return res;
        }
    };
    // comparator for unordered_set
    struct ==<CartesianVertex> {
    size_t operator()(const CartesianVertex &other) const {
        return (vector.x == other.vector.x
                && vector.y == other.vector.y
                && vector.z == other.vector.z);
    }
}
}
    std::unordered_set<CartesianVertex> neighbors;
    vertex_index get_edge_count();





};


#endif //BASIC_INCLUDES_HPP

