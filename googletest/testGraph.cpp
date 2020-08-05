#include "gtest/gtest.h"
#include "../Graph/CartesianGraph.hpp"
#include "../VF2Wrapper.hpp"
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

TEST(CartesianGraph, orbital) {
    CartesianGraph cg({3, 3, 3});
    cg.load_edges({{0, 1},
                   {1, 2},
                   {2, 3}});
    cg.orbital(2);
    EXPECT_TRUE(std::get<1>(edge(1, 3, cg.g)));
    EXPECT_EQ(num_edges(cg.g), 4);

}

TEST(CartesianGraph, Z_measure) {
    CartesianGraph cg({3, 3, 3});
    cg.load_edges({{0, 1},
                   {1, 2}});
    cg.Z_measure(1);
    EXPECT_FALSE(std::get<1>(edge(0, 2, cg.g)));
    EXPECT_EQ(num_edges(cg.g), 0);
}

TEST(CartesianGraph, Y_measure) {
    CartesianGraph cg({3, 3, 3});
    cg.load_edges({{0, 1},
                   {1, 2},
                   {2, 3}});
    cg.Y_measure(2);
    // index of vertex 3 "3" changes to "2" with Y_measure
    EXPECT_TRUE(std::get<1>(edge(1, 2, cg.g)));
    EXPECT_EQ(num_edges(cg.g), 2);
    EXPECT_EQ(num_vertices(cg.g), 26);

}

TEST(CartesianGraph, X_measure) {

}

TEST(VF2Wrapper, test_isomorphic) {
    // testing isomorphism for a simple graph of 5 nodes
    CartesianGraph cg1({5, 1, 1});
    CartesianGraph cg2({1, 1, 5});
    cg1.load_edges({
                           {0, 1},
                           {0, 2},
                           {0, 3},
                           {3, 4}
                   });
    cg2.load_edges({
                           {1, 0},
                           {1, 2},
                           {1, 3},
                           {3, 4}
                   });
    bool result = test_isomorphic(cg1, cg2);
    ASSERT_TRUE(result);
}
