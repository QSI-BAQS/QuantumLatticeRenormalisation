
#include <climits>
#include "similarity.hpp"

int Similarity::edit_similarity(GraphRegister target, GraphRegister source) {
    int target_nodes = target.vertices.size();
    int source_nodes = source.vertices.size();

    // if the target has more nodes than the source, there is no possible transformation
    if(target_nodes > source_nodes){
        return INT_MAX ;
    }
    // if the nodes and are equal, they must already match. otherwise 0
    else if(target_nodes == source_nodes){
    }

    // otherwise, we need to perform an exact number of measurement operators
    int ops_required = source_nodes - target_nodes;

    // now look at the edges of the input graphs. the current edge count of the graphs will
    // have to match at the end so we can use the current edge count as an approximation to the goal state.



    return 0;
}

//std::vector<VertexIndex, LocCliffOp> Similarity::solve(GraphRegister target, GraphRegister source, int ops) {
//    // test all permutations of node removals corresponding to necessary number of measurements
//    std::vector<VertexIndex, LocCliffOp> out;
//
//    return out;
//}
