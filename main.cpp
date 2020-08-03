#include <iostream>
#include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"

int main() {

    list<edge_io_t> edges = {{0, 3},
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
