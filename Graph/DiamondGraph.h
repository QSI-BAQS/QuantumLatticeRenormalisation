//
// Created by voidlogic on 05/08/2020.
//

#ifndef QUANTUMLATTICERENORMALISATION_DIAMONDGRAPH_H
#define QUANTUMLATTICERENORMALISATION_DIAMONDGRAPH_H

#include "../common.hpp"
#include <random>
#include <iostream>
//#include <boost/graph/adjacency_list.hpp>

class DiamondGraph {

public:
    DiamondGraph();
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d> boostGraph;
    int size_x, size_y, size_z, size_xy;
    double fusionSuccessRate;

    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor get_vertex_from_coord(int x, int y, int z);
    void generate_nodes();
    void generate_connections();
};


#endif //QUANTUMLATTICERENORMALISATION_DIAMONDGRAPH_H
