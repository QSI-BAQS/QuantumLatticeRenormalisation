#include <iostream>
#include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"

int main() {

    // CartesianGraph g3(0.75, 5, 5, 5);
    // GraphRegister g1(8);
    // GraphRegister g2(8)
    // g1.hadamard (4);
    // g1.hadamard (5);
    // g1.hadamard (6);
    // g1.cnot (6, 3);
    // g1.cnot (6, 1);
    // g1.cnot (6, 0);
    // g1.cnot (5, 3);
    // g1.cnot (5, 2);
    // g1.cnot (5, 0);
    // g1.cnot (4, 3);
    // g1.cnot (4, 2);
    // g1.cnot (4, 1);
    // for (int i=0;i<7;i++){
    //
    //     g1.cnot(i, 7);
    // }
    //
    // std::cout << g1.measure (7) << std::endl;
    // g1.print_adj_list();
    // g1.print_stabilizer();

    list<edge_t> edges = {{0, 3},
                          {0, 1}};

    graph_t BGLGraph(5);
    add_edge(0, 1, BGLGraph);
    BGLGraph[0].x = 4;
    for (int i = 0; i < 10; i++) {

        CartesianGraph cg({2, 3, 4}, vec3d());
        cout << "vertices: " << num_vertices(cg.g) << endl;
        cout << "edges: " << num_edges(cg.g) << endl;
        cg.invert_edge(0, 1);
    }
    return 0;
}
