
#ifndef VF2WRAPPER_HPP
#define VF2WRAPPER_HPP

#include "Graph/CartesianGraph.hpp"
#include "Graph/structure_data.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>
#include <boost/graph/subgraph.hpp>

// The way we interface to the VF2 algorithm is by configuring a callback to be run when an isomorphism is found.
// In this file we have a variety of callbacks for this purpose.
// See VF2Wrapper.cpp:test_isomorphic for examples on syntax.
// We are using return variables stored inside the callback struct to be accessed after the VF2 finishes.



bool test_isomorphic(const CartesianGraph &source, const CartesianGraph &target);

std::list<CartesianGraph> get_isomorphisms(const CartesianGraph &source, const CartesianGraph &target);

// Return true on the first isomorphism found, and discard the result.
template<typename Graph1,
        typename Graph2>
struct vf2_test_iso_callback {


    vf2_test_iso_callback(const Graph1 &graph1, const Graph2 &graph2)
            : graph1_(graph1), graph2_(graph2) {
        found = false;
    }

    template<typename CorrespondenceMap1To2,
            typename CorrespondenceMap2To1>
    bool operator()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {
        // return variable from callback
        found = true;


        // stop the search
        return false;
    }

    mutable bool found;
private:
    const Graph1 &graph1_;
    const Graph2 &graph2_;
};


// Get each isomorphism and return it.
template<typename Graph1,
        typename Graph2>
struct vf2_get_iso_list_callback {


    vf2_get_iso_list_callback(const Graph1 &graph1, const Graph2 &graph2)
            : graph1_(graph1), graph2_(graph2) {
        found = false;
    }

    template<typename CorrespondenceMap1To2,
            typename CorrespondenceMap2To1>
    bool operator()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {

        BGL_FORALL_VERTICES_T(v, graph1_, Graph1)
                std::cout << '(' << get(vertex_index_t(), graph1_, v) << ", "
                          << get(vertex_index_t(), graph2_, get(f, v)) << ") ";

        std::cout << std::endl;

        return true;
    }

    bool found;
private:
    const Graph1 &graph1_;
    const Graph2 &graph2_;
};


#endif //VF2WRAPPER_HPP
