
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "CartesianGraph.hpp"

extern std::mt19937_64 rng;
//
// void CartesianGraph::add_node_with_edges(const CartesianVertex& node, const vertex_set& neighbors){
//     vertex_set::iterator i = neighbors.begin();
//     while(i != neighbors.end()) {
//         add_edge(node, neighbors.find(int(i)));
//     }
// }

CartesianGraph::CartesianGraph(CartesianGraph g1, const CartesianGraph& g2) : CartesianGraph(std::move(g1)) {

}


void CartesianGraph::add_node(vec3d coorinates) {

}
// CartesianVertex CartesianGraph::get_node(vec3d coord) {
//     return 0;
// }
// CartesianVertex CartesianGraph::get_node(vertex_ind index) {
//     return NULL;
// }

CartesianGraph::CartesianGraph(vec3d bounding_size, bool mercedes, double seed, vec3d offset, double prob_success) {
    // indices from size struct
    vertex_ind x=bounding_size.x, y=bounding_size.y, z=bounding_size.z;
    bounding_box = bounding_size;
    this->offset = {0,0,0};
    // generate nodes and initial graph object
    graph = graph_type(x * y *z);

    // assign carteisan coordinates to nodes
    for(int zi = 0; zi < z; zi++){
        for(int yi = 0; yi < y; yi++){
            for(int xi = 0; xi < x; xi++){
                vertex_ind cur_index =
                        zi * x * y +
                        yi * x +
                        xi;
                graph[cur_index].x = xi;
                graph[cur_index].y = yi;
                graph[cur_index].z = zi;
            }
        }
    }
    // random setup
    std::random_device rd;
    if(seed == 0){
        seed = rd();
    }
    // mersenne_twister_engine seeded with rd() same generator as photonic_lattice
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dist(0.0, 1.0);
    double bond_failure_rate = 1.0 - prob_success;

    if(mercedes){
        // mercedes method: See
        // Gimeno-Segovia, Mercedes, et al.
        // "From three-photon Greenberger-Horne-Zeilinger states to ballistic universal quantum computation."
        // Physical review letters 115.2 (2015): 020502.

        // Method source code modified from https://github.com/herr-d/photonic_lattice


    }
    else{
        // simple probability method.
        // each edge has a chance of failing proportional to "probability".
        for(int zi = 0; zi <z; zi++){
            for(int yi = 0; yi < y; yi++){
                for(int xi = 0; xi < x; xi++){
                    if(zi > 0){
                        if(dist(gen) > bond_failure_rate )
                            add_edge(get_index({xi, yi, zi}),
                                     get_index({xi, yi, zi - 1}),
                                     graph);
                    }
                    if(yi > 0){
                        if(dist(gen) > bond_failure_rate )
                            add_edge(get_index({xi, yi, zi}),
                                     get_index({xi, yi - 1, zi}),
                                     graph);
                    }
                    if(xi > 0){
                        if(dist(gen) > bond_failure_rate )
                            add_edge(get_index({xi, yi, zi}),
                                     get_index({xi - 1, yi, zi}),
                                     graph);
                    }

                }
            }
        }
    }
}

void CartesianGraph::invert_edge(vertex_ind a, vertex_ind b) {
    // Get the edge between those two nodes
    auto edge_result = edge(a, b, graph);
    if(std::get<1>(edge_result)){
        // There is an edge: remove it
        remove_edge(a, b, graph);
    }
    else{
        // There is no edge: add one
        add_edge(a, b, graph);
    }
}

// vertex_set CartesianGraph::get_neighborhood(vertex_ind a) {
//     return vertex_set();
// }



vertex_ind CartesianGraph::get_index(vec3d vector) {
    vertex_ind x = bounding_box.x, y = bounding_box.y, z = bounding_box.z;
    return vector.z * x * y +
        vector.y * x +
        vector.x;
}
