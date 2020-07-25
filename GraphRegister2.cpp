
#include <random>
#include <boost/range/size_type.hpp>
#include "GraphRegister2.hpp"


extern std::mt19937_64 rng;

// GraphRegister with additional constructors and related functions.

void GraphRegister2::add_node(QubitVertex node, hash_set<VertexIndex> neighbors) {
    vertices.push_back(node);
    hash_set<VertexIndex>::iterator i = neighbors.begin();
    while(i != neighbors.end()) {
        // add_edge(node, neighbors.find());   // TODO error: no matching function for call to ‘__gnu_cxx::hash_set<long unsigned int>::find()’
    }
}
void GraphRegister2::add_node(QubitVertex node) {
    vertices.push_back(node);
}
GraphRegister2::GraphRegister2(Stabilizer stab) : GraphRegister(stab.numQubits){
    // TODO
}

GraphRegister2::GraphRegister2(const GraphRegister& g1, GraphRegister g2) : GraphRegister(g1) {
    for(auto & vertex : g2.vertices){
        this->add_node(vertex, vertex.neighbors);
    }
}

//GraphRegister2::GraphRegister2(double probability, std::vector<size_type>) : GraphRegister(x * y * z){
//    // generate nodes
//
//    // generate edges based on percolation probability
//        for(VertexIndex zi = 0; zi <z; ++z){
//            for(VertexIndex yi = 0; yi < y; ++y){
//                for(VertexIndex xi = 0; xi < x; ++x){
//                    // roll probability
//
//                    std::uniform_real_distribution<double> dist(0,1);
//
//                }
//
//                }}}

QubitVertex GraphRegister2::get_node(int x, int y, int z) {
    return QubitVertex();
}

//GraphRegister2::GraphRegister2(double probability, int x, int y, int z) {

//}
