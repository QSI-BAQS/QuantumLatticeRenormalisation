
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include "basic_includes.hpp"


class Vertex {
public:
    vertex_list neighbors;
    vertex_index index;
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

    // - nodes have pair-records of the pointer to who they are connected to in the neighbor list.
    // if one side removes an edge, the other side gets updated as well.

    // and not affected by offset or relative coordinates.
    // methods may throw an exception if the index doesn't exist.
    public:

    // Create a graph register with no edges and the specified number of nodes.
    Graph(vertex_index node_count);

    // Generate a graph register containing the nodes of two graphs
    // sharing no edges.
    Graph(Graph  g1, const Graph& g2);
.
    Vertex get_node(vertex_index index);


    // add the node, keeping its exisitng edges.
    void add_node(Vertex node);

    // get the size of graph in terms of number of nodes.
    vertex_index get_size();

    // remove the provided nodes from the graph, and put them in a new graphRegister.
//    Graph split(vertex_list<VertexIndex> nodes_to_split);


    // edge operations
    // add_edge and del_edge will throw an exception if they would have no effect
    // in addition to if the index is not found in the graph.
    void add_edge(vertex_index a, vertex_index b);
    void del_edge(vertex_index a, vertex_index b);
    void invert_edge(vertex_index a, vertex_index b);

    // add a node, return its index. it will be initialised disconnected from the rest of the graph (ie. no edges)
    vertex_index add_node();



    // delete a node, and all of its edges(equivalent to Z_measure)
    void del_node(vertex_index index);

    bool add_node_with_edges(const Vertex &node, const std::unordered_set<vertex_index> &neighbors);

    vertex_list get_neighborhood(vertex_index a);

    // local pauli measurement operators (LPMOs)
    void X_measure(vertex_index index, vertex_index special_neighbor);
    void Y_measure(vertex_index index);
    void Z_measure(vertex_index index);
    void orbital(vertex_index index);

    // inverted LPMOs
    // each returns a list of all possible inverted LPMOs ...
    // TODO more detail on inversion process
    graph_list  inverted_X_measure(const vertex_list& neighbors_a);
    graph_list  inverted_Y_measure(const vertex_list& neighbors_a);
    graph_list  inverted_Z_measure(const vertex_list& neighbors_a);
    graph_list  inverted_Z_measure(const vertex_list& neighbors_a, Vertex b);



private:

    // get the next index to use for node assignment, and increment the private counter.
    vertex_index get_next_index();
    vertex_list vertices;
    vertex_index max_index;
};

#endif //GRAPH_HPP
