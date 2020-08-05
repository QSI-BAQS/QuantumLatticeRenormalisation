
#include "CandidateLookupTree.hpp"

Candidate::Candidate(const graph_t &g) {
    this->g = g;
    iso_reduced_form = get_iso_reduced_form();
}


std::string Candidate::get_iso_reduced_form() {
    // Idea here is to store the number of vertices, then sort the edge list.
    // Isomorphisms will always be equal under comparison given both graphs underwent reduction.
    // New me says to old me: don't be ridiculous... That problem is not that easy to solve.


}
