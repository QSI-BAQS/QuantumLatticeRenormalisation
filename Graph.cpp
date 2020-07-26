
#include <random>
#include <boost/range/size_type.hpp>
#include "Graph.hpp"


extern std::mt19937_64 rng;

void Graph::add_node(const QubitVertex& node) {
    vertices.push_back(node);

}
void Graph::add_node_with_edges(const QubitVertex& node, const hash_set<VertexIndex>& neighbors){
    hash_set<VertexIndex>::iterator i = neighbors.begin();
    while(i != neighbors.end()) {
        add_edge(node, neighbors.find(int(i)));
    }
}
void Graph::add_node(QubitVertex node) {
    vertices.push_back(node);
}

Graph::Graph(const GraphRegister& g1, GraphRegister g2) : GraphRegister(g1) {
    for(auto & vertex : g2.vertices){
        add_node_with_edges(vertex, vertex.neighbors);
    }
}

Graph::Graph(double probability, int x, int y, int z) : GraphRegister(x * y * z){
    // generate nodes

    // generate edges based on percolation probability
        for(VertexIndex zi = 0; zi <z; ++z){
            for(VertexIndex yi = 0; yi < y; ++y){
                for(VertexIndex xi = 0; xi < x; ++x){
                    // roll probability

                    std::uniform_real_distribution<double> dist(0,1);

                }

                }}}

Vertex Graph::get_node(int x, int y, int z) {
    return Vertex();
}
Graph::Graph(double probability, int x, int y, int z, bool mercedes) {
    // generate nodes

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

            }}
    }
}

CartesianVertex::CartesianVertex(vec vector) {
    this->vector = vector;
}

vertex_index CartesianVertex::get_index() {
    return 0;
}
