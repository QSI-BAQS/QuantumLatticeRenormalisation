
#include <random>
#include <boost/range/size_type.hpp>
#include <utility>
#include "CartesianGraph.hpp"

extern std::mt19937_64 rng;


CartesianGraph::CartesianGraph(CartesianGraph g1, const CartesianGraph &g2) : CartesianGraph(std::move(g1)) {

}

CartesianGraph::CartesianGraph(vertex_ind num_vertices) {
    g = graph_t(num_vertices);
    this->offset = {0, 0, 0};
    this->bounding_box = {0, 0, 0};
    vec3d oops({0,1,1});
}

CartesianGraph::CartesianGraph(const graph_t &g, bool dummy) {
    this->g = g;
    this->offset = {0, 0, 0};
    this->bounding_box = {0, 0, 0};

}

void CartesianGraph::add_node(vec3d coords) {
    // add the node
    vertex_t vertex_new = add_vertex(g);

    // add its coordinates
    g[vertex_new].x = coords.x;
    g[vertex_new].y = coords.y;
    g[vertex_new].z = coords.z;
}

void CartesianGraph::load_nodes(const std::list<vec3d> &coords) {
    if (num_vertices(g) != 0) {
        return;
    }
    for (auto coord : coords) {
        add_node(coord);
    }
}

void CartesianGraph::add_neighbors_to_node(vertex_ind index, const vertex_list_t &neighbors) {
    for (const auto &i : neighbors) {
        add_edge(index, i, g);
    }
}

// CartesianVertex CartesianGraph::get_node(vec3d coord) {
//     return 0;
// }
// CartesianVertex CartesianGraph::get_node(vertex_ind index) {
//     return NULL;
// }

CartesianGraph::CartesianGraph(vec3d bounding_size, vec3d offset) {
    // indices from size struct
    vertex_ind x = bounding_size.x, y = bounding_size.y, z = bounding_size.z;
    bounding_box = bounding_size;

    this->offset = offset;
    // generate nodes and initial graph object
    g = graph_t(x * y * z);

    // assign cartesian coordinates to nodes
    for (int zi = 0; zi < z; zi++) {
        for (int yi = 0; yi < y; yi++) {
            for (int xi = 0; xi < x; xi++) {
                vertex_ind cur_index =
                        zi * x * y +
                        yi * x +
                        xi;
                g[cur_index].x = xi;
                g[cur_index].y = yi;
                g[cur_index].z = zi;
            }
        }
    }
}

void CartesianGraph::gen_edges_mercedes(double seed, double prob_success) {
    vertex_ind x = bounding_box.x, y = bounding_box.y, z = bounding_box.z;
    // random setup
    std::random_device rd;
    if(seed == 0){
        seed = rd();
    }
    // mersenne_twister_engine seeded with rd() same generator as photonic_lattice
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dist(0.0, 1.0);
    double bond_failure_rate = 1.0 - prob_success;

    // mercedes method: See
    // Gimeno-Segovia, Mercedes, et al.
    // "From three-photon Greenberger-Horne-Zeilinger states to ballistic universal quantum computation."
    // Physical review letters 115.2 (2015): 020502.

    // Method source code modified from https://github.com/herr-d/photonic_lattice


}

void CartesianGraph::gen_edges_simple(double seed, double prob_success) {
    vertex_ind x = bounding_box.x, y = bounding_box.y, z = bounding_box.z;
    // random setup
    std::random_device rd;
    if(seed == 0){
        seed = rd();
    }
    // mersenne_twister_engine seeded with rd() same generator as photonic_lattice
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dist(0.0, 1.0);
    // inverting logic (no particular reason to do this)
    double bond_failure_rate = 1.0 - prob_success;


    // simple probability method.
// each edge has a chance of failing proportional to "probability".
    for(int zi = 0; zi <z; zi++){
        for(int yi = 0; yi < y; yi++){
            for(int xi = 0; xi < x; xi++){
                if(zi > 0){
                    if(dist(gen) > bond_failure_rate )
                        add_edge(get_index({xi, yi, zi}),
                                 get_index({xi, yi, zi - 1}),
                                 g);
                }
                if(yi > 0){
                    if(dist(gen) > bond_failure_rate )
                        add_edge(get_index({xi, yi, zi}),
                                 get_index({xi, yi - 1, zi}),
                                 g);
                }
                if(xi > 0){
                    if (dist(gen) > bond_failure_rate)
                        add_edge(get_index({xi, yi, zi}),
                                 get_index({xi - 1, yi, zi}),
                                 g);
                }

            }
        }
    }
}

void CartesianGraph::load_edges(const std::list<edge_io_t> &edges_to_load) {
    for (edge_io_t edge_i : edges_to_load) {
        add_edge(std::get<0>(edge_i), std::get<1>(edge_i), g);
    }
}

void CartesianGraph::invert_edge(vertex_ind a, vertex_ind b) {
    // Get the edge between those two nodes
    auto edge_result = edge(a, b, g);
    // second part of the pair (tuple) is a bool indicating whether edge exists. access with std::get<1>
    if (std::get<1>(edge_result)) {
        // There is an edge: remove it
        remove_edge(a, b, g);
    } else {
        // There is no edge: add one
        add_edge(a, b, g);
    }
}

// vertex_set CartesianGraph::get_neighborhood(vertex_ind a) {
//     return vertex_set();
// }



vertex_ind CartesianGraph::get_index(vec3d vector) {
    vertex_ind x = bounding_box.x, y = bounding_box.y, z = bounding_box.z;
    return vector.z * x * y +
        vector.y * x +
        vector.x;
}
