
#include "CartesianGraph.hpp"


void CartesianGraph::orbital(vertex_ind index) {
    adj_iterator_t a_inner, a_inner_end, a_outer, a_end;
    vertex_t a_vertex = vertex(index, g);

    // For every distinct pair in neighborhood(A), invert the edge in that pair

    // Outer loop: cover every index
    for (tie(a_outer, a_end) = adjacent_vertices(a_vertex, g);
         a_outer != a_end; ++a_outer) {
        // Inner loop: cover every index after the current outer index

        // current outer index
        a_inner = a_outer;
        // current outer index + 1
        a_inner++;
        for (; a_inner != a_end; ++a_inner) {
            // Outer index is a_outer, inner index is a_inner
            invert_edge(*a_inner, *a_outer);
        }
    }
}
void CartesianGraph::X_measure(vertex_ind index, vertex_ind special_neighbor) {
    orbital(special_neighbor);
    Y_measure(index);
}

void CartesianGraph::Y_measure(vertex_ind index) {
    orbital(index);
    clear_vertex(index, g);
    remove_vertex(index, g);
}

void CartesianGraph::Z_measure(vertex_ind index) {
    clear_vertex(index, g);
    remove_vertex(index, g);
}

// Modified from http://rosettacode.org/wiki/Combinations#C.2B.2B
// We need combinations for the inverted measures
// since we know the internal storage of the vertex indices is from 0 to N
// we don't need to change much here

// double-list of combinations
// depth-0 is for each combination
// depth-1 is for each index
std::list<std::list<int>> combinations(int N, int K) {
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    std::list<std::list<int>> medium_list;
    // print integers and permute bitmask
    do {
        std::list<int> small_list;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) {
                small_list.push_back(i);
            }
        }
        medium_list.push_back(small_list);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return medium_list;
}

// Triple list! waaaH!
// Could probably do it just with double list. Maybe there are some triviality rules
// for certain K related to N though, for optimisation in the measurements.
std::list<std::list<std::list<int>>> combinations_forall_K(int N) {
    std::list<std::list<std::list<int>>> big_list;
    for (int i = 1; i < N; i++) {
        big_list.push_back(combinations(N, i));
    }
    return big_list;
}

// Inverted measurement operators
// Non-cartesian approach
graph_list_raw CartesianGraph::inverted_Z_measure() {
    // temporary reference copy
    graph_t g_temp(g);
    // all the vertices in the original graph
    auto vertices_all = vertices(g);
    // Output data structure
    graph_list_raw out;
    // Add node A - won't have coordinates in this version
    auto A = add_vertex(g_temp);

    // For every permutation of order 1..|g|
    // Pretty messy loops... Will probably optimise with heuristics later
    auto combinations = combinations_forall_K(num_vertices(g));
    for (auto combination_size_k : combinations) {
        for (const auto &combination : combinations) {
            for (const auto &comb : combination) {
                // copy to g_dash
                graph_t g_dash(g_temp);
                for (auto ii : comb) {
                    // add edges to the matching permutations
                    add_edge(A, ii, g_dash);
                }
                // add to our global set
                out.push_back(g_dash);
            }
        }
    }
    return out;
}

graph_list_raw CartesianGraph::inverted_Y_measure() {

}

graph_list_raw CartesianGraph::inverted_X_measure() {

}