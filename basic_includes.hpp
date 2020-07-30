
#ifndef BASIC_INCLUDES_HPP
#define BASIC_INCLUDES_HPP


#include <list>
#include <unordered_set>
#include <unordered_map>

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
// See https://marknelson.us/posts/2011/09/03/hash-functions-for-c-unordered-containers.html
// https://stackoverflow.com/questions/34877531/unordered-map-with-custom-key-compiler-error
// Hash function for CartesianVertex


// declare our hash function
namespace std
{
    template<> class hash<CartesianVertex>
    {
        size_t operator()(const CartesianVertex & x) const;
    };
}

// typedef std::unordered_set<CartesianVertex> vertex_set;
class CartesianVertex {
public:
    explicit CartesianVertex(vec3d vector);
    vec3d vector;
    // class my_hash {
    //     size_t operator()(const CartesianVertex &s) const noexcept {
    //         std::size_t res = 0;
    //         hash_combine(res, s.vector.x);
    //         hash_combine(res, s.vector.y);
    //         hash_combine(res, s.vector.z);
    //         return res;
    //     }
    // };
    class my_equal {
        bool equals(const CartesianVertex &a, const CartesianVertex &b) const {
            return (a.vector.x == b.vector.x
                    && a.vector.y == b.vector.y
                    && a.vector.z == b.vector.z);
        }
    };

    // comparator for unordered_set
    // bool operator==(const CartesianVertex &other) const
    // {
    //     return (vector.x == other.vector.x
    //           && vector.y == other.vector.y
    //           && vector.z == other.vector.z);
    // }

    std::unordered_set<CartesianVertex, CartesianVertex> neighbors;
    vertex_index get_edge_count();
};


// define hash function using hash_combine from boost
template <typename T>
inline void hash_combine(std::size_t & s, const T & v)
{
    std::hash<T> h;
    s^= h(v) + 0x9e3779b9 + (s<< 6) + (s>> 2);
}

namespace std {
    size_t hash<CartesianVertex>::operator()(const CartesianVertex &s) const {
        std::size_t res = 0;
        hash_combine(res, s.vector.x);
        hash_combine(res, s.vector.y);
        hash_combine(res, s.vector.z);
        return res;
};
#endif //BASIC_INCLUDES_HPP

