
#include "VF2Wrapper.hpp"



bool test_isomorphic(const CartesianGraph &source, const CartesianGraph &target) {
    auto source_v = num_vertices(source.g), target_v = num_vertices(target.g);
    // if they don't have the same number of nodes, they aren't isomorphic
    // target must be smaller than source.
    if (source_v == target_v || source_v < target_v) {
        return false;
    }

    vf2_test_iso_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);

}

std::list<CartesianGraph> get_isomorphisms(const CartesianGraph &source, const CartesianGraph &target) {
    auto source_v = num_vertices(source.g), target_v = num_vertices(target.g);
    // if they don't have the same number of nodes, they aren't isomorphic
    // target must be smaller than source.
    if (source_v == target_v || source_v < target_v) {
        // return empty list.
        return std::list<CartesianGraph>();
    }

    vf2_test_iso_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);
    subgrap

}
