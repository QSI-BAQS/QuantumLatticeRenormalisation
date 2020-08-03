
#ifndef VF2WRAPPER_HPP
#define VF2WRAPPER_HPP

#include "Graph/CartesianGraph.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>

// The way we interface to the VF2 algorithm is by configuring a callback to be run when an isomorphism is found.

// In this file we have a variety of callbacks for this purpose. See VF2Wrapper.cpp:test_equal for examples on syntax.



template<typename Graph1,
        typename Graph2>
struct vf2_test_callback {


    vf2_test_callback(const Graph1 &graph1, const Graph2 &graph2)
            : graph1_(graph1), graph2_(graph2) {}

    template<typename CorrespondenceMap1To2,
            typename CorrespondenceMap2To1>
    bool operator()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {

        BGL_FORALL_VERTICES_T(v, graph1_, Graph1)std::cout << '(' << get(vertex_index_t(), graph1_, v) << ", "
                                                           << get(vertex_index_t(), graph2_, get(f, v)) << ") ";

        std::cout << std::endl;

        return true;
    }

private:
    const Graph1 &graph1_;
    const Graph2 &graph2_;
};


#endif //VF2WRAPPER_HPP
