

#include "gtest/gtest.h"
#include "../Graph/CartesianGraph.hpp"
#include "../Debug/DebugGraph.hpp"

TEST(operators, combinations_forall_K) {
    const char *target = "0 \n"
                         "1 \n"
                         "2 \n"
                         "3 \n"
                         "0 1 \n"
                         "0 2 \n"
                         "0 3 \n"
                         "1 2 \n"
                         "1 3 \n"
                         "2 3 \n"
                         "0 1 2 \n"
                         "0 1 3 \n"
                         "0 2 3 \n"
                         "1 2 3 \n"
                         "0 1 2 3 \n";
    std::string source;
    auto big_list = combinations_forall_K(4);
    for (const auto &medium_list : big_list) {
        for (const auto &small_list : medium_list) {
            for (auto index : small_list) {
                source += std::to_string(index) + " ";
            }
            source += "\n";
        }
    }
    ASSERT_EQ(target, source);
}

TEST(operators, inverted_Z_measure) {
    const char *target_o = "Graph 1: (0,1) (1,2) (3,0) \n"
                           "Graph 2: (0,1) (1,2) (3,1) \n"
                           "Graph 3: (0,1) (1,2) (3,2) \n"
                           "Graph 4: (0,1) (1,2) (3,0) (3,1) \n"
                           "Graph 5: (0,1) (1,2) (3,0) (3,2) \n"
                           "Graph 6: (0,1) (1,2) (3,1) (3,2) \n"
                           "Graph 7: (0,1) (1,2) (3,0) (3,1) (3,2) \n";
    std::string source_o;
    CartesianGraph cg(3);
    cg.load_edges({{0, 1},
                   {1, 2}});
    graph_list_raw inv_z_lpmo = cg.inverted_Z_measure();
    int i = 1;
    source_o = print_edges_all_graphs(inv_z_lpmo);

    ASSERT_EQ(target_o, source_o);
}

TEST(operators, inverted_Y_measure) {
    const char *target_o = "Graph 1: (0,1) (1,2) (3,0) \n"
                           "Graph 2: (0,1) (1,2) (3,1) \n"
                           "Graph 3: (0,1) (1,2) (3,2) \n"
                           "Graph 4: (1,2) (3,0) (3,1) \n"
                           "Graph 5: (0,1) (1,2) (3,0) (3,2) (2,0) \n"
                           "Graph 6: (0,1) (3,1) (3,2) \n"
                           "Graph 7: (3,0) (3,1) (3,2) (2,0) \n";
    std::string source_o;
    CartesianGraph cg(3);
    cg.load_edges({{0, 1},
                   {1, 2}});
    graph_list_raw inv_y_lpmo = cg.inverted_Y_measure();
    int i = 1;
    source_o = print_edges_all_graphs(inv_y_lpmo);

    ASSERT_EQ(target_o, source_o);
}