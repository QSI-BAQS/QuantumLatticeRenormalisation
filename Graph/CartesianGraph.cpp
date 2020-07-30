
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "CartesianGraph.hpp"
#include "CartesianVertex.hpp"

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

CartesianGraph::CartesianGraph(vertex_ind nodeCount, double probability, vec3d size, bool mercedes) {
    vertex_ind x=size.x, y=size.y, z=size.z;
    // generate nodes
    for(int zi = 0; zi <z; ++z){
        for(int yi = 0; yi < y; ++y){
            for(int xi = 0; xi < x; ++x){

            }
        }
    }
    // mercedes method: See
    // Gimeno-Segovia, Mercedes, et al.
    // "From three-photon Greenberger-Horne-Zeilinger states to ballistic universal quantum computation."
    // Physical review letters 115.2 (2015): 020502.

    // Method source code modified from https://github.com/herr-d/photonic_lattice

    if(mercedes){

    }
    else{
        // generate edges based on percolation probability
        for(int zi = 0; zi <z; ++z){
            for(int yi = 0; yi < y; ++y){
                for(int xi = 0; xi < x; ++x){
                    // roll probability

                    std::uniform_real_distribution<double> dist(0,1);

                }
            }
        }
    }
}

void CartesianGraph::add_edge(vertex_ind a, vertex_ind b) {

}

void CartesianGraph::del_edge(vertex_ind a, vertex_ind b) {

}

void CartesianGraph::orbital(vertex_ind index) {

}
void CartesianGraph::del_node(vertex_ind index) {

}

void CartesianGraph::invert_edge(vertex_ind a, vertex_ind b) {

}

// vertex_set CartesianGraph::get_neighborhood(vertex_ind a) {
//     return vertex_set();
// }


vertex_ind CartesianGraph::get_size() {
    return 0;
}


CartesianVertex::CartesianVertex(vec3d vector) {
    this->vector = vector;
}

vertex_ind CartesianVertex::get_edge_count() {
    return 0;
}
