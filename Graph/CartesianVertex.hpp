
#ifndef CARTESIAN_VERTEX_HPP
#define CARTESIAN_VERTEX_HPP

#include "../basic_includes.hpp"


class CartesianVertex {
public:
    explicit CartesianVertex(vec3d vector);
    vec3d vector;
    vertex_ind get_edge_count();
};


#endif //CARTESIAN_VERTEX_HPP
