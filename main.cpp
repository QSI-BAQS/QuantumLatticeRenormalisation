#include <iostream>
#include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"
#include "Graph/structure_data.hpp"

int main() {

    // structure_data data;
    // for(auto edge : data.raussendorf_uc.edges){
    //     cout << edge.first << " " << edge.second << endl;
    // }
    // graph_t BGLGraph(5);
    // add_edge(0, 1, BGLGraph);
    // BGLGraph[0].x = 4;
    // for (int i = 0; i < 10; i++) {
    //
    //     CartesianGraph cg({2, 3, 4}, vec3d());
    //     cout << "vertices: " << num_vertices(cg.g) << endl;
    //     cout << "edges: " << num_edges(cg.g) << endl;
    //     cg.invert_edge(0, 1);
    // }
    CartesianGraph cg(3);
    auto big_list = cg.combinations_forall_K(4);
    for (const auto &medium_list : big_list) {
        for (const auto &small_list : medium_list) {
            for (auto index : small_list) {
                std::cout << index << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
