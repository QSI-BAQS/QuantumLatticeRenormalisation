
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "CartesianGraph.hpp"


extern std::mt19937_64 rng;

void CartesianGraph::add_node_with_edges(const Vertex& node, const vertex_list& neighbors){
    vertex_list::iterator i = neighbors.begin();
    while(i != neighbors.end()) {
        add_edge(node, neighbors.find(int(i)));
    }
}

CartesianGraph::CartesianGraph(CartesianGraph g1, const CartesianGraph& g2) : CartesianGraph(std::move(g1)) {
    for(auto & vertex : g2.vertices){
        add_node_with_edges(vertex, vertex.neighbors);
    }
}


void CartesianGraph::add_node(vec coorinates) {

}

Vertex CartesianGraph::get_node(int x, int y, int z) {
    return Vertex();
}


Vertex CartesianGraph::get_node(int x, int y, int z) {
    return Vertex();
}
 {

}
CartesianGraph::CartesianGraph(vertex_index nodeCount, double probability, vec3d size, bool mercedes) {
    max_index = 0;
    vertex_index x=size.x, y=size.y, z=size.z;
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

vertex_index CartesianGraph::add_node() {
    return 0;
}

void CartesianGraph::X_measure(vertex_index index, vertex_index special_neighbor) {

}

void CartesianGraph::Y_measure(vertex_index index) {

}

void CartesianGraph::Z_measure(vertex_index index) {

}

void CartesianGraph::orbital(vertex_index index) {

}

Vertex CartesianGraph::get_node(vertex_index index) {
    return Vertex();
}

void CartesianGraph::add_node(Vertex node) {

}

void CartesianGraph::del_node(vertex_index index) {

}

void CartesianGraph::add_edge(vertex_index a, vertex_index b) {

}

void CartesianGraph::del_edge(vertex_index a, vertex_index b) {

}

void CartesianGraph::invert_edge(vertex_index a, vertex_index b) {

}

vertex_list CartesianGraph::get_neighborhood(vertex_index a) {
    return vertex_list();
}

graph_list CartesianGraph::inverted_X_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list CartesianGraph::inverted_Y_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list CartesianGraph::inverted_Z_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list CartesianGraph::inverted_Z_measure(const vertex_list& neighbors_a, Vertex b) {
    return graph_list();
}

vertex_index CartesianGraph::get_next_index() {
    return 0;
}

vertex_index CartesianGraph::get_size() {
    return 0;
}

CartesianGraph::CartesianGraph(vertex_index node_count) {

}



CartesianVertex::CartesianVertex(vec vector) {
    this->vector = vector;
}

vertex_index CartesianVertex::get_index() {
    return 0;
}
