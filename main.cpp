#include <iostream>
#include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"
#include "Graph/structure_data.hpp"
#include "Debug/DebugGraph.hpp"
#include <boost/optional/optional_io.hpp>

#include "experiment/test_inv_measure_r_cell.cpp"
int main() {


    // pred_inv_measure_r_cell();
    CartesianGraph cg({3, 3, 3});

    optional<vertex_t> index = cg.g.vertex_by_property({1, 1, 1});
    std::cout << index;
    return 0;
}
