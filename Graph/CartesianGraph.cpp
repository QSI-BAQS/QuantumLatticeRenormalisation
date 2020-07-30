
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "CartesianGraph.hpp"


extern std::mt19937_64 rng;

void CartesianGraph::add_node_with_edges(const Vertex& node, const vertex_set& neighbors){
    vertex_set::iterator i = neighbors.begin();
    while(i != neighbors.end()) {
        add_edge(node, neighbors.find(int(i)));
    }
}

CartesianGraph::CartesianGraph(CartesianGraph g1, const CartesianGraph& g2) : CartesianGraph(std::move(g1)) {
    for(auto & vertex : g2.vertices){
        add_node_with_edges(vertex, vertex.neighbors);
    }
}


void CartesianGraph::add_node(vec3d coorinates) {

}
 CartesianVertex CartesianGraph::get_node(vec3d coord) {
    return NULL;
}
CartesianVertex CartesianGraph::get_node(vertex_index index) {
    return Vertex();
}

CartesianGraph::CartesianGraph(vertex_index nodeCount, double probability, vec3d size, bool mercedes) {
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

void CartesianGraph::add_edge(vertex_index a, vertex_index b) {
    CartesianVertex a_node = get_node(a), b_node = get_node(b);
    a_node.neighbors.push_back()

}

void CartesianGraph::del_edge(vertex_index a, vertex_index b) {

}

void CartesianGraph::orbital(vertex_index index) {

}
void CartesianGraph::del_node(vertex_index index) {

}

void CartesianGraph::invert_edge(vertex_index a, vertex_index b) {

}

vertex_set CartesianGraph::get_neighborhood(vertex_index a) {
    return vertex_set();
}

vertex_index CartesianGraph::get_next_index() {
    vertex_index cur_max = cur_max_index;
    cur_max_index++;
    return cur_max;
}

vertex_index CartesianGraph::get_size() {
    return vertices.size();
}

void CartesianGraph::add_node(CartesianVertex node) {
    node.index = get_next_index();
    vertices.push_back(node);
}


CartesianVertex::CartesianVertex(vec3d vector) {
    this->vector = vector;
    this->index = 0;
}

vertex_index CartesianVertex::get_edge_count() {
    return neighbors
}
