
#include "VF2Wrapper.hpp"



bool test_isomorphic(CartesianGraph source, CartesianGraph target) {

    // Build graph unit cell 1  
    int num_verticesUC1 = 18;
    CartesianGraph graphUC1(num_vertices_ruc);

    vf2_test_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);

}

