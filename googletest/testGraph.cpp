#include "gtest/gtest.h"
#include "../Graph/CartesianGraph.hpp"

TEST (CartesianGraph, InitialisationCube){
    // vertex count for cube
    CartesianGraph cg({3, 3, 3});
    EXPECT_EQ(3 * 3 * 3, num_vertices(cg.graph));

}
TEST (CartesianGraph, InitialisationRectangle){
    // vertex count for rectangular prism
    CartesianGraph cg({4, 5, 6});
    EXPECT_EQ(4 * 5 * 6, num_vertices(cg.graph));

}

TEST(CartesianGraph, InvertEdge){
    CartesianGraph cg({2, 2, 2});
    vertex_ind total1 = num_edges(cg.graph);
    auto edge_result1 = edge(0, 1, cg.graph);
    cg.invert_edge(0, 1);
    vertex_ind total2 = num_edges(cg.graph);
    auto edge_result2 = edge(0, 1, cg.graph);
    EXPECT_NE(std::get<1>(edge_result1), std::get<1>(edge_result2));
    EXPECT_NE(total1, total2);
}