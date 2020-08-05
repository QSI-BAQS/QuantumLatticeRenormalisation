
#ifndef CANDIDATE_LOOKUP_TREE_HPP
#define CANDIDATE_LOOKUP_TREE_HPP

#include "../common.hpp"
#include "../Graph/structure_data.hpp"
#include "Graph/CartesianGraph.hpp"


// Wrap g with its reduced forms, distances and reduction pattern.
// Calculate these via constructor.
class Candidate {
public:
    // Reduced forms
    std::string iso_reduced_form;
    bool is_lu_reduced_form;

    graph_t g;
    // List representing how to return to the target graph by performing measuremnets.
    std::list<std::pair<pauli_operator, int>> measurement_pattern;
    int x_dist, y_dist, z_dist;


    Candidate(const graph_t &g);

    std::string get_iso_reduced_form();
};

typedef Candidate candidate_t;

// Same as a candidate, except we are not storing the biggest part- the graph.
class HashedCandidate {
    std::string hash;
    std::list<std::pair<pauli_operator, int>> measurement_pattern;


};

typedef HashedCandidate hashed_candidate_t;

// Hash function specialisation for a Candidate.
namespace std {
    template<>
    struct hash<Candidate> {
        size_t operator()(const Candidate &g) const noexcept {
            return hash<string>()(g.iso_reduced_form);
        }
    };
}

// Isomorphism-reduction
Candidate iso_reduction(Candidate g);

// LU-reduction



class CandidateLookupTree {

};

#endif // CANDIDATE_LOOKUP_TREE_HPP
