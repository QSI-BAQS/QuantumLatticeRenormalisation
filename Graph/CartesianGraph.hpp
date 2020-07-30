
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include "../basic_includes.hpp"
#include <boost/graph/adjacency_list.hpp>
using namespace boost;
struct vertex_x {
    typedef boost::vertex_property_tag kind;
};

struct vertex_y {
    typedef boost::vertex_property_tag kind;
};

struct vertex_z {
    typedef boost::vertex_property_tag kind;
};
typedef adjacency_list<vecS, vecS, undirectedS,
    vertex_x,
    vertex_y,
    vertex_z> MyGraphType;


class CartesianGraph {
    // constraints + assumptions:
    // - whole-numbered 3d cartesian coordinate system
    // - generated graphs have 100% of nodes successfully generateded in lattice
    // - imported graphs low overhead
    // - needs to be hashable. hash should only be based on edge permutation

    // - nodes have pair-records of the pointer to who they are connected to in the neighbor list.
    // if one side removes an edge, the other side gets updated as well.

    // methods may return exceptions if coordinates are already occupied / empty, or if node references are invalid.

    public:

    // and not affected by offset or relative coordinates.
    // methods may throw an exception if the index doesn't exist.
    // Generate a lattice given a percolation rate (probability) and dimensions.
    // "mercedes" = false is random probability.
    // "mercedes" = true follows KLM fusion probabilities.

    CartesianGraph(vertex_ind nodeCount, double probability, vec3d size, bool mercedes);

    // Create a graph register with no edges and the specified number of nodes.
    // CartesianGraph(vertex_ind node_count);

    // Generate a graph register containing the nodes of two graphs
    // sharing no edges.
    CartesianGraph(CartesianGraph  g1, const CartesianGraph& g2);


    // add a node at the coordinates specified, with no edges.
    void add_node(vec3d coorinates);
    // Search for node at a logical position inside the GraphRegister based on coordinate
    // don't consider offset.
    CartesianVertex get_node(vec3d coord);
    // Search for a node with a matching index
    CartesianVertex get_node(vertex_ind index);

    // add the node, keeping its exisitng edges.
    void add_node (CartesianVertex node);

    // get the size of graph in terms of number of nodes.
    vertex_ind get_size();

    // remove the provided nodes from the graph, and put them in a new graphRegister.
//    CartesianGraph split(vertex_set<VertexIndex> nodes_to_split);


    // edge operations
    // add_edge and del_edge will throw an exception if they would have no effect
    // in addition to if the index is not found in the graph.
    void add_edge(vertex_ind a, vertex_ind b);
    void del_edge(vertex_ind a, vertex_ind b);
    void invert_edge(vertex_ind a, vertex_ind b);



    // delete a node, and all of its edges(equivalent to Z_measure)
    void del_node(vertex_ind index);

    bool add_node_with_edges(const CartesianVertex&node, const vertex_set &neighbors);

    vertex_set get_neighborhood(vertex_ind a);

    // local pauli measurement operators (LPMOs)
    void X_measure(vertex_ind index, vertex_ind special_neighbor);
    void Y_measure(vertex_ind index);
    void Z_measure(vertex_ind index);
    void orbital(vertex_ind index);

    // inverted LPMOs
    // each returns a list of all possible inverted LPMOs ...
    // TODO more detail on inversion process
    graph_list  inverted_X_measure(const vertex_set& neighbors_a);
    graph_list  inverted_Y_measure(const vertex_set& neighbors_a);
    graph_list  inverted_Z_measure(const vertex_set& neighbors_a);



private:
    vec offset;
    vec bounding_box;
};

#endif //GRAPH_HPP
