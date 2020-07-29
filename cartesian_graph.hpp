
#include "Graph.hpp"
#include "basic_includes.hpp"

#ifndef CARTESIAN_GRAPH_HPP
#define CARTESIAN_GRAPH_HPP


class CartesianGraph : Graph{
    // A graph where each node must be cartesian.
    // Nodes adeded must have coordinates specified.
    // methods may return exceptions if coordinates are already occupied / empty.

public:
    // Generate a lattice given a percolation rate (probability) and dimensions.
    // "mercedes" = false is random probability.
    // "mercedes" = true follows KLM fusion probabilities.

    CartesianGraph(vertex_index nodeCount, double probability, int x, int y, int z, bool mercedes);
    // add a node at the coordinates specified, with no edges. Replaces Graph method.
    void add_node(vec coorinates);
    // Search for node at a logical position inside the GraphRegister based on coordinate
    // don't consider offset.
    Vertex get_node(int x, int y, int z);
    // Search for a node with a matching index

    vec offset;
    vec bounding_box;
private:
    using Graph::add_node;

};


#endif //CARTESIAN_GRAPH_HPP