
#include "VF2Wrapper.hpp"



bool test_isomorphic(const CartesianGraph &source, const CartesianGraph &target) {
    // Sort of a cheat- We are using subgraph_iso, even though BGL has a "true" isomorphism algo implemented.
    // Unfortunately (and somewhat ironically), I think running the subgraph_iso is faster for testing regular iso,
    // as long as we confirm the node counts before passing in.

    // If I want to test coordinates for equality though, I'd have to use the "true" iso algo.
    // That use case is not the original intention for coordinates anyway... Can probably just do without it.

    auto source_v = num_vertices(source.g), target_v = num_vertices(target.g);
    // if they don't have the same number of nodes, they aren't isomorphic
    if (source_v != target_v) {
        return false;
    }

    vf2_test_iso_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);

}

std::list<CartesianGraph> get_isomorphisms(const CartesianGraph &source, const CartesianGraph &target) {
    auto source_v = num_vertices(source.g), target_v = num_vertices(target.g);
    // target must be smaller than or equal to source. (in terms of nodes)
    if (source_v < target_v) {
        // return empty list.
        return std::list<CartesianGraph>();
    }

    vf2_test_iso_callback<graph_t, graph_t> callback(source.g, target.g);

    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source.g, target.g, callback);

    return std::list<CartesianGraph>();
}
