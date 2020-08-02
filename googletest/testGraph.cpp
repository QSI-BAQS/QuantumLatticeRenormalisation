#include "gtest/gtest.h"
#include "../Graph/CartesianGraph.hpp"

TEST (CartesianGraph, InitialisationCube) {
    // vertex count for cube
    CartesianGraph cg({3, 3, 3}, vec3d());
    EXPECT_EQ(3 * 3 * 3, num_vertices(cg.g));

}

TEST (CartesianGraph, InitialisationRectangle) {
    // vertex count for rectangular prism
    CartesianGraph cg({4, 5, 6}, vec3d());
    EXPECT_EQ(4 * 5 * 6, num_vertices(cg.g));

}

TEST(CartesianGraph, InvertEdge) {
    CartesianGraph cg({2, 2, 2}, vec3d());
    vertex_ind total1 = num_edges(cg.g);
    auto edge_result1 = edge(0, 1, cg.g);
    cg.invert_edge(0, 1);
    vertex_ind total2 = num_edges(cg.g);
    auto edge_result2 = edge(0, 1, cg.g);
    EXPECT_NE(std::get<1>(edge_result1), std::get<1>(edge_result2));
    EXPECT_NE(total1, total2);
}

TEST(CartesianGraph, LoadEdges) {
    CartesianGraph cg({3, 3, 3});
    cg.load_edges({{0, 1},
                   {1, 2},
                   {2, 3},
                   {3, 20}});
    EXPECT_EQ(num_edges(cg.g), 4);
    EXPECT_TRUE(std::get<1>(edge(0, 1, cg.g)));
    EXPECT_FALSE(std::get<1>(edge(0, 2, cg.g)));
}
