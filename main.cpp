#include <iostream>
#include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"
#include "Graph/structure_data.hpp"
#include "Debug/DebugGraph.hpp"
#include "Graph/DiamondGraph.h"

int main() {
    // structure_data data;
    // for(auto edge : data.raussendorf_uc.edges){
    //     cout << edge.first << " " << edge.second << endl;
    // }
    // graph_t BGLGraph(5);
    // add_edge(0, 1, BGLGraph);
    // BGLGraph[0].x = 4;
    // for (int i = 0; i < 10; i++) {x
    //
    //     CartesianGraph cg({2, 3, 4}, vec3d());
    //     cout << "vertices: " << num_vertices(cg.g) << endl;
    //     cout << "edges: " << num_edges(cg.g) << endl;
    //     cg.invert_edge(0, 1);
    // }
//    CartesianGraph cg(3);
//    cg.load_edges({{0, 1},
//                   {1, 2}});
//    graph_list_raw inv_x_lpmo = cg.inverted_X_measure();
//    cout << print_edges_all_graphs(inv_x_lpmo);
//    vec3d vec({2, 2, 2});

    DiamondGraph prettydiamond;
    prettydiamond.generate_nodes();
    prettydiamond.generate_connections();


    return 0;
}
