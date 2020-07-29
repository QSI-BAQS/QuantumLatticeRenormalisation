
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "Graph.hpp"


extern std::mt19937_64 rng;

void Graph::add_node_with_edges(const Vertex& node, const vertex_list& neighbors){
    vertex_list::iterator i = neighbors.begin();
    while(i != neighbors.end()) {
        add_edge(node, neighbors.find(int(i)));
    }
}

Graph::Graph(Graph g1, const Graph& g2) : Graph(std::move(g1)) {
    for(auto & vertex : g2.vertices){
        add_node_with_edges(vertex, vertex.neighbors);
    }
}


Vertex Graph::get_node(int x, int y, int z) {
    return Vertex();
}
Graph::Graph(double probability, int x, int y, int z, bool mercedes) {
    max_index = 0;
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

vertex_index Graph::add_node() {
    return 0;
}

void Graph::X_measure(vertex_index index, vertex_index special_neighbor) {

}

void Graph::Y_measure(vertex_index index) {

}

void Graph::Z_measure(vertex_index index) {

}

void Graph::orbital(vertex_index index) {

}

Vertex Graph::get_node(vertex_index index) {
    return Vertex();
}

void Graph::add_node(Vertex node) {

}

void Graph::del_node(vertex_index index) {

}

void Graph::add_edge(vertex_index a, vertex_index b) {

}

void Graph::del_edge(vertex_index a, vertex_index b) {

}

void Graph::invert_edge(vertex_index a, vertex_index b) {

}

vertex_list Graph::get_neighborhood(vertex_index a) {
    return vertex_list();
}

graph_list Graph::inverted_X_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list Graph::inverted_Y_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list Graph::inverted_Z_measure(const vertex_list& neighbors_a) {
    return graph_list();
}

graph_list Graph::inverted_Z_measure(const vertex_list& neighbors_a, Vertex b) {
    return graph_list();
}

vertex_index Graph::get_next_index() {
    return 0;
}

vertex_index Graph::get_size() {
    return 0;
}

Graph::Graph(vertex_index node_count) {

}

CartesianVertex::CartesianVertex(vec vector) {
    this->vector = vector;
}

vertex_index CartesianVertex::get_index() {
    return 0;
}
