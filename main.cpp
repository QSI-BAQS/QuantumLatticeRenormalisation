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
    cg.load_edges({{0, 1},
                   {1, 2}});
    graph_list_raw inv_z_lpmo = cg.inverted_Z_measure();
    for (const auto &graph : inv_z_lpmo) {
        int i = 1;
        std::cout << "Graph " << i << ": ";
        i++;
        edge_iterator_t e_start, e_end;
        boost::tie(e_start, e_end) = edges(graph);
        for (; e_start != e_end; ++e_start)
            std::cout << "(" << source(*e_start, graph)
                      << "," << target(*e_start, graph) << ") ";
        std::cout << std::endl;

    }


    return 0;
}
