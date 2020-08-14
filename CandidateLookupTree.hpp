
#ifndef CANDIDATE_LOOKUP_TREE_HPP
#define CANDIDATE_LOOKUP_TREE_HPP

#include "common.hpp"
#include "Graph/structure_data.hpp"
#include "Graph/CartesianGraph.hpp"
#include "Print/DebugGraph.hpp"


// Wrap g with its reduced forms, distances and reduction pattern.
// Calculate these via constructor.
class Candidate {
public:

    graph_t g;
    // List representing how to return to the target graph by performing measuremnets.
    std::list<std::pair<pauli_operator, int>> measurement_pattern;
    int x_dist, y_dist, z_dist;


    explicit Candidate(const graph_t &g);

};

typedef Candidate candidate_t;

// Same as a candidate, except we are not storing the biggest part- the graph.
class HashedCandidate {
public:
    std::list<std::pair<pauli_operator, int>> measurement_pattern;
    int id;

};

typedef HashedCandidate hashed_candidate_t;

// Hash function specialisation for a Candidate.
namespace std {
    template<>
    struct hash<Candidate> {
        size_t operator()(const Candidate &c) const noexcept {
            return hash<string>()(print_edges_reduced(c.g));
        }
    };
}

// Isomorphism-reduction
Candidate iso_reduction(Candidate g);

// LU-reduction


typedef ulong hash_t;

class CandidateLookupTree {
    CandidateLookupTree();

    std::unordered_map<hash_t, hashed_candidate_t> candidate_map;


    // Put all the candidates into the map, using the provided measurement_pattern
    void insert_graphs(const std::list<Candidate> &list);

    // Just one graph input.
    void insert_graph(const Candidate &c);


    // Test if there is a matching hash in the graph or not
    // Return id if match, 0 otherwise.
    int find_graph(const graph_t &g);

    // Lookup directly from a hash. Return id if match, 0 otherwise.
    int find_hash(hash_t hash);


    // get a measurement pattern from a specified hash.
    // will return an empty list if there is no match.
    std::list<std::pair<pauli_operator, int>> get_measurement_pattern(hash_t hash);


private:
    int max_id;
};

#endif // CANDIDATE_LOOKUP_TREE_HPP
