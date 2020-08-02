#include <iostream>
#include <random>
//#include "VF2Wrapper.hpp"
//#include "GraphConstructor.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>
#include <boost/graph/copy.hpp>

using namespace boost;
typedef adjacency_list<setS, vecS, bidirectionalS> graph_t;


int iso_callback_count;
graph_t working_graph;

template <typename Graph1,
        typename Graph2>
struct vf2_test_callback {

    vf2_test_callback(const Graph1& graph1, const Graph2& graph2)
            : graph1_(graph1), graph2_(graph2) {}

    template <typename CorrespondenceMap1To2,
            typename CorrespondenceMap2To1>
    bool operator()(CorrespondenceMap1To2 f, CorrespondenceMap2To1) const {

        BGL_FORALL_VERTICES_T(v, graph1_, Graph1)
                remove_vertex(get(vertex_index_t(), graph2_, get(f, v)), working_graph);
        iso_callback_count++;
        return false;
    }
private:
    const Graph1& graph1_;
    const Graph2& graph2_;
};

graph_t gen_random_boost_lattice(double bond_failure_rate, int dimension, double seed = 0) {

    std::random_device rd;
    if (seed == 0) {
        seed = rd();
    }
    // mersenne_twister_engine seeded with rd() same generator as photonic_lattice
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(1.0, 2.0);

    // build random graph of dimension
    graph_t graph_boost(dimension * dimension * dimension);

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            for(int k=0;k<dimension;k++){
                int current_pos = i*dimension*dimension+j*dimension+k;
                int last_k = current_pos-1;
                int last_j = current_pos-dimension;
                int last_i = current_pos-dimension*dimension;
                if(k>0){
                    if(dis(gen) > bond_failure_rate + 1){
                        add_edge(current_pos, last_k, graph_boost);
                    }
                }
                if(j>0){
                    if(dis(gen) > bond_failure_rate + 1){
                        add_edge(current_pos, last_j, graph_boost);
                    }
                }
                if(i>0){
                    if(dis(gen) > bond_failure_rate + 1){
                        add_edge(current_pos, last_i, graph_boost);
                    }
                }
            }
        }
    }
    return graph_boost;

}
int main() {
    // Build graph unit cell 1
    int num_verticesUC1 = 18;
    graph_t graphUC1(num_verticesUC1);
    int edgesUC1[24][2] = {
            {0,  2},
            {1,  2},
            {2,  3},
            {2,  4},
            {0,  6},
            {1,  8},
            {3,  9},
            {4,  11},
            {5,  6},
            {5,  8},
            {6,  7},
            {7,  9},
            {8,  10},
            {9,  12},
            {10, 11},
            {11, 12},
            {6,  13},
            {8,  14},
            {9,  16},
            {11, 17},
            {13, 15},
            {14, 15},
            {15, 16},
            {15, 17}
    };
    for (int i = 0; i<24; i++){
        add_edge(edgesUC1[i][0],edgesUC1[i][1],graphUC1);
    }


    // Build graph unit cell 2 (deformed with extra edges)
    int num_verticesUC2 = 18;
    graph_t graphUC2(num_verticesUC2);
    int edgesUC2[25][2] = {
            {0,  2},
            {1,  2},
            {2,  3},
            {2,  4},
            {0,  6},
            {1,  8},
            {3,  9},
            {4,  11},
            {5,  6},
            {5,  8},
            {6,  7},
            {7,  9},
            {8,  10},
            {9,  12},
            {10, 11},
            {11, 12},
            {6,  13},
            {8,  14},
            {9,  16},
            {11, 17},
            {13, 15},
            {14, 15},
            {15, 16},
            {15, 17},
            {15, 1}
    };
    for (int i = 0; i<24; i++){
        add_edge(edgesUC2[i][0],edgesUC2[i][1],graphUC2);
    }

    int sample_size = 30;
    for(int dimension=5;dimension<10;dimension++){
        std::cout << std::endl <<  "Box size " << dimension << std::endl;
        for(int i=0;i<sample_size;i++){

            iso_callback_count = 0;
            graph_t graph_boost = gen_random_boost_lattice(0.25, dimension);
            copy_graph(graph_boost, working_graph);
            // set new callback
            vf2_test_callback<graph_t, graph_t> callback(graphUC1, working_graph);


            // run vf2 until no isomorphisms are found.
            // the callback removes all verticies in any found isomorphism- ensuring each cell is not sharing nodes.
            while(vf2_subgraph_iso(graphUC1, working_graph, callback)){
            }

//        std::cout << "VF2 finished, found " << iso_callback_count << " vertex disjoint isomorphisms." << std::endl;
            std::cout << iso_callback_count << std::endl;
        }
    }
    return 0;
}