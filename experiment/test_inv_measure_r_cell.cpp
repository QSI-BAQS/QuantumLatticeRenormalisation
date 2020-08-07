
#include "../Graph/CartesianGraph.hpp"
#include "../Graph/structure_data.hpp"
#include "../Debug/DebugGraph.hpp"
#include "combinatorics.hpp"
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>

using namespace std::chrono;




// Perform one inverted measurement of each type on the Raussendorf cell.
// How many new graphs did we create? What properties do they have?

void pred_inv_measure_r_cell() {
    // Predictions

    // Graph size (Y = Z, but X is bigger)
    // 262142
    std::cout << "Predicted Z graph-count: " << count_combinations_between_k(18, 1, 18)
              << " (same for Y graph-count)" << std::endl;

    double x_nodecount = 0;
    double rcell_vertices = 18;
    for (int i = 0; i < 18; ++i) {
        x_nodecount += i * count_combinations(rcell_vertices, i);
    }
    // 2.35928e+06
    std::cout << "Predicted X graph-count: " << x_nodecount << std::endl;


}


void exp_inv_measure_r_cell() {
    // Experiment to compare with predictions

    // File IO
    std::string data_path = "experiment/data/";
    std::ofstream out_z(data_path + "inv_z_measure_r_cell " + get_formatted_datetime() + ".txt");
    std::ofstream out_y(data_path + "inv_y_measure_r_cell " + get_formatted_datetime() + ".txt");
    std::ofstream out_x(data_path + "inv_x_measure_r_cell " + get_formatted_datetime() + ".txt");

    // Load R-cell
    structure_data data;
    auto r_cell_edges = data.raussendorf_uc.edges;

    CartesianGraph cg1(18);
    CartesianGraph cg2(18);
    CartesianGraph cg3(18);

    // inverted Z-measure
    cg1.load_edges(r_cell_edges);
    auto start = high_resolution_clock::now();
    graph_list_raw inv_z_plmo = cg1.inverted_Z_measure();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "inv Z measure: " << duration.count() << " milliseconds. " << std::endl;
    out_z << print_edges_all_graphs_reduced(inv_z_plmo);
    out_z.close();

    // inverted Y-measure

    cg2.load_edges(r_cell_edges);
    start = high_resolution_clock::now();
    graph_list_raw inv_y_plmo = cg2.inverted_Y_measure();
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    std::cout << "inv Y measure: " << duration.count() << " milliseconds. " << std::endl;

    out_y << print_edges_all_graphs_reduced(inv_y_plmo);
    out_y.close();



    // inverted X-measure

    // cg3.load_edges(r_cell_edges);
    // start = high_resolution_clock::now();
    // graph_list_raw inv_x_plmo = cg3.inverted_X_measure();
    // stop = high_resolution_clock::now();
    // duration = duration_cast<milliseconds>(stop - start);
    // std::cout << "inv X measure: " << duration.count() << " milliseconds. ";
    //
    // out_x << print_edges_all_graphs_reduced(inv_x_plmo);
    // out_x.close();

}