
#include "CandidateLookupTree.hpp"

Candidate::Candidate(const graph_t &g) {
    this->g = g;
}

void CandidateLookupTree::insert_graphs(const std::list<Candidate> &list) {
    for (const Candidate &c : list) {
        insert_graph(c);
    }
}

void CandidateLookupTree::insert_graph(const Candidate &c) {
    hashed_candidate_t hashed;
    hashed.id = max_id;
    max_id++;
    hashed.measurement_pattern = c.measurement_pattern;
    hash_t hash = std::hash<candidate_t>{}(c);
    std::pair<size_t, hashed_candidate_t> pair(hash, hashed);
    candidate_map.insert(pair);
}

int CandidateLookupTree::find_graph(const graph_t &g) {
    Candidate c(g);
    hash_t hash = std::hash<candidate_t>{}(c);
    return find_hash(hash);
}

int CandidateLookupTree::find_hash(hash_t hash) {
    auto lookup = candidate_map.find(hash);
    if (lookup == candidate_map.end()) {
        return 0;
    }
    return lookup->second.id;
}

std::list<std::pair<pauli_operator, int>> CandidateLookupTree::get_measurement_pattern(hash_t hash) {
    auto lookup = candidate_map.find(hash);
    if (lookup == candidate_map.end()) {
        return std::list<std::pair<pauli_operator, int>>();
    }
    return lookup->second.measurement_pattern;

}

CandidateLookupTree::CandidateLookupTree() {
    max_id = 0;
}
