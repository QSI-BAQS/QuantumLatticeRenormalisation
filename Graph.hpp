
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include "basic_includes.hpp"


class Vertex {
public:
    vertex_list neighbors;
};

class CartesianVertex : Vertex{
public:
    explicit CartesianVertex(vec vector);
    vertex_index get_index();
    vec vector;
};

class Graph {
    // constraints + assumptions:
    // - whole-numbered 3d cartesian coordinate system
    // - generated graphs have 100% of nodes successfully generateded in lattice
    // - imported graphs low overhead
    // - needs to be hashable. hash should only be based on edge permutation
    // and not affected by offset or relative coordinates
    public:

    // Generate a graph register containing the nodes of two graphs
    // sharing no edges.
    Graph(const Graph& g1, Graph g2);
    // Generate a lattice given a percolation rate (probability) and dimensions.
    // "mercedes" = false is random probability.
    // "mercedes" = true follows KLM fusion probabilities.
    Graph(double probability, int x, int y, int z, bool mercedes);

    // Search for node at a logical position inside the GraphRegister based on coordinate
    // don't consider offset.
    Vertex get_node(int x, int y, int z);

    void add_node(Vertex node);

    // remove the provided nodes from the graph, and put them in a new graphRegister.
//    Graph split(hash_set<VertexIndex> nodes);

    void add_node(const Vertex &node);

    void add_node_with_edges(const Vertex &node, const std::unordered_set<vertex_index> &neighbors);

    void Z_measure();

private:

    vec offset;
    vec size;

};


#endif //GRAPHCONSTRUCTOR_HPP
