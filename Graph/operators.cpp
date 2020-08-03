
#include "CartesianGraph.hpp"


void CartesianGraph::orbital(vertex_ind index) {
    out_edge_iterator_t e_start, e_end;
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


// graph_list CartesianGraph::inverted_X_measure(const vertex_set& neighbors_a) {
//     return graph_list();
// }
//
// graph_list CartesianGraph::inverted_Y_measure(const vertex_set& neighbors_a) {
//     return graph_list();
// }
//
// graph_list CartesianGraph::inverted_Z_measure(const vertex_set& neighbors_a) {
//     return graph_list();
// }
