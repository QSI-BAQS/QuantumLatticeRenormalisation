
#include "VF2Wrapper.hpp"
#include "Graph/CartesianGraph.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>
using namespace boost;

typedef adjacency_list< setS, vecS, bidirectionalS > graph_type;

template <typename Graph1,
        typename Graph2>
struct vf2_test_callback {

    vf2_test_callback(const Graph1& graph1, const Graph2& graph2)
            : graph1_(graph1), graph2_(graph2) {}

    template <typename CorrespondenceMap1To2,
            typename CorrespondenceMap2To1>
    bool operator()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {

        BGL_FORALL_VERTICES_T(v, graph1_, Graph1)
                std::cout << '(' << get(vertex_index_t(), graph1_, v) << ", "
                          << get(vertex_index_t(), graph2_, get(f, v)) << ") ";

        std::cout << std::endl;

        return true;
    }

private:
    const Graph1& graph1_;
    const Graph2& graph2_;
};

graph_type convert(CartesianGraph gr){


	graph_type gr_converted(gr.vertices.size());
	int counter=0;
	for (auto &vertex: gr.vertices)
	{
		for(auto innervertex : vertex.neighbors){
			add_edge(innervertex,counter,gr_converted);
		}
	    counter++;
	}
	return gr_converted;
}

bool test_equal_raussendorf(CartesianGraph source){
    // Build graph unit cell 1
    int num_verticesUC1 = 18;
    graph_type graphUC1(num_verticesUC1);
    int edgesUC1[24][2] = {
            {0,2}, {1,2}, {2,3}, {2,4},
            {0,6}, {1,8}, {3,9}, {4,11},
            {5,6}, {5,8}, {6,7}, {7,9}, {8,10}, {9,12}, {10,11}, {11,12},
            {6,13}, {8,14}, {9,16}, {11,17},
            {13,15}, {14,15}, {15,16}, {15,17}
    };
    for (auto & i : edgesUC1){
        add_edge(i[0],i[1],graphUC1);
    }


}

bool test_equal(CartesianGraph source, CartesianGraph target){

	graph_type source_converted = convert(source);

	graph_type target_converted = convert(target);
	
    // Build graph unit cell 1  
    int num_verticesUC1 = 18;
    graph_type graphUC1(num_verticesUC1);
    int edgesUC1[24][2] = {
    	{0,2}, {1,2}, {2,3}, {2,4},
		{0,6}, {1,8}, {3,9}, {4,11},
		{5,6}, {5,8}, {6,7}, {7,9}, {8,10}, {9,12}, {10,11}, {11,12},
		{6,13}, {8,14}, {9,16}, {11,17},
		{13,15}, {14,15}, {15,16}, {15,17}
		};
	for (int i = 0; i<24; i++){
		add_edge(edgesUC1[i][0],edgesUC1[i][1],graphUC1);
	}

    vf2_test_callback< graph_type, graph_type > callback(source_converted, target_converted);
	callback.operator =


//	        bool (&fp)()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {
        // Print (sub)graph isomorphism map
//        BGL_FORALL_VERTICES_T(v, graph1_, Graph1)
//                std::cout << '(' << get(vertex_index_t(), graph1_, v) << ", "
//                          << get(vertex_index_t(), graph2_, get(f, v)) << ") ";
//
//        std::cout << std::endl;
//
//        return true;
//    };
    // Print out all subgraph isomorphism mappings between graph1 and graph2.
    // Vertices and edges are assumed to be always equivalent.
    vf2_subgraph_iso(source_converted, target_converted, callback);

}

