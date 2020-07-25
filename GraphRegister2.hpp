
#ifndef GRAPHSIMTEST_GRAPHCONSTRUCTOR_HPP
#define GRAPHSIMTEST_GRAPHCONSTRUCTOR_HPP


#include <graphsim.h>


class GraphRegister2 : GraphRegister{

    public:
    // Generate a graph register containing the nodes of two graphs
    // sharing no edges.
    GraphRegister2(const GraphRegister& g1, GraphRegister g2);
    // Generate a GraphRegister from a stabilizer.
//    GraphRegister2(Stabilizer stab);
    // Generate a lattice given a percolation rate (probability) and dimensions.
    GraphRegister2(double probability, int x, int y, int z);

    // Access nodes at a logical position inside the GraphRegister based on coordinate
    QubitVertex get_node(int x, int y, int z);

    void add_node(QubitVertex node);

    // remove the provided nodes from the graph, and put them in a new graphRegister.
//    GraphRegister2 split(hash_set<VertexIndex> nodes);

    void add_node(const QubitVertex &node);

    void add_node_with_edges(const QubitVertex &node, const hash_set<VertexIndex> &neighbors);
};


#endif //GRAPHSIMTEST_GRAPHCONSTRUCTOR_HPP
