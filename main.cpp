#include <iostream>
// #include "GraphSim/graphsim.h"
#include "Graph/CartesianGraph.hpp"
#include "Graph/structure_data.hpp"
#include "Print/DebugGraph.hpp"
#include <boost/optional/optional_io.hpp>

#include "experiment/test_inv_measure_r_cell.cpp"
int main() {

    auto list = load_graphs("experiment/data/inv_z_measure_r_cell 14-08-2020 10-11-48.txt");





    // exp_inv_measure_r_cell();
    // pred_inv_measure_r_cell();
    CartesianGraph cg({3, 3, 3});

    optional<vertex_t> index = cg.g.vertex_by_property({1, 1, 1});
    std::cout << index;
    return 0;
}
