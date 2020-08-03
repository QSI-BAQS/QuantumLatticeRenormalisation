
#include "VF2Wrapper.hpp"



int raussendorf_unit_cell[24][2] = {
        {0,  2},
        {1,  2},
        {2,  3},
        {2,  4},
        {0,  6},
        {1,  8},
        {3,  9},
        {4,  11},
        {5,  6},
        {5,  8},
        {6,  7},
        {7,  9},
        {8,  10},
        {9,  12},
        {10, 11},
        {11, 12},
        {6,  13},
        {8,  14},
        {9,  16},
        {11, 17},
        {13, 15},
        {14, 15},
        {15, 16},
        {15, 17}
};
int num_vertices_ruc = 18;

bool test_equal(CartesianGraph source, CartesianGraph target){

    // Build graph unit cell 1  
    int num_verticesUC1 = 18;
    CartesianGraph graphUC1(num_vertices_ruc);

    vf2_test_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);

}

