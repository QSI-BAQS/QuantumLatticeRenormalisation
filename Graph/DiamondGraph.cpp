//
// Created by voidlogic on 05/08/2020.
//

#include "DiamondGraph.h"

DiamondGraph::DiamondGraph() {
    boostGraph = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>();
    size_x = size_y = size_z = 3;
    size_xy = size_x * size_y;
    fusionSuccessRate = 0.75;

}

void DiamondGraph::generate_nodes() {
    for(int z = 0; z < size_z; ++z){
        for(int y = 0; y < size_y; ++y){
            for(int x = 0; x < size_x; ++x){
                boost::add_vertex({x, y, z}, boostGraph);
            }
        }
    }
}

// its really just an unsigned long I think, but I like this way
// this function is remarkably inefficient and a better coordinate access strategy is needed maybe
boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor
DiamondGraph::get_vertex_from_coord(int x, int y, int z) {
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor out = x;
    out += y * size_x;
    out += z * size_y * size_x;
    return out;
}

void DiamondGraph::generate_connections() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 dice(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> roll(0.0, 1.0);

    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor cutedarcypointing = 0;

    for(int z = 0; z < size_z; ++z){
        for(int y = 0; y < size_y; ++y){
            for(int x = 0; x < size_x; ++x){
                // X DIRECTION
                if(x != size_x - 1){
                    if(roll(dice) <= fusionSuccessRate){  // yellow gate in X axis
                        if(roll(dice) <= fusionSuccessRate){  // blue gate in +X direction
                            boost::add_edge(cutedarcypointing, cutedarcypointing + 1,boostGraph);
                        }
                    }else{
                        boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor
                                cutedarcylookingbackwardinXdirection = 0;
                        for(auto fwend : make_iterator_range(boost::adjacent_vertices(cutedarcypointing, boostGraph))){
                            if(boostGraph[fwend].x < x){
                                cutedarcylookingbackwardinXdirection = fwend;
                            }
                        }
                        if(cutedarcylookingbackwardinXdirection != 0){
                            boost::remove_edge(cutedarcypointing, cutedarcylookingbackwardinXdirection,boostGraph);
                            if(roll(dice) <= fusionSuccessRate){  // blue gate in +X direction
                                boost::add_edge(cutedarcylookingbackwardinXdirection, cutedarcypointing + 1,boostGraph);
                            }
                        }
                    }
                }

                // YZ DIRECTION
                if((x+y+z)%2 == 0){  // qubit is +y,-z
                    if(y != size_y - 1){
                        if(roll(dice) <= fusionSuccessRate){  // yellow gate in Y axis
                            if(roll(dice) <= fusionSuccessRate){  // blue gate in +Y direction
                                boost::add_edge(cutedarcypointing, cutedarcypointing + size_x,boostGraph);
                            }
                        }else{
                            boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor
                                    cutedarcylookingbackwardinZdirection = 0;
                            for(auto fwend : make_iterator_range(boost::adjacent_vertices(cutedarcypointing, boostGraph))){
                                if(boostGraph[fwend].z < z){
                                    cutedarcylookingbackwardinZdirection = fwend;
                                }
                            }
                            if(cutedarcylookingbackwardinZdirection != 0){
                                boost::remove_edge(cutedarcypointing, cutedarcylookingbackwardinZdirection,boostGraph);
                                if(roll(dice) <= fusionSuccessRate){  // blue gate in +Y direction
                                    boost::add_edge(cutedarcylookingbackwardinZdirection, cutedarcypointing + size_x,boostGraph);
                                }
                            }
                        }
                    }
                }else{  // qubit is -y,+z
                    if(z != size_z - 1){
                        if(roll(dice) <= fusionSuccessRate){  // yellow gate in Z axis
                            if(roll(dice) <= fusionSuccessRate){  // blue gate in +Z direction
                                boost::add_edge(cutedarcypointing, cutedarcypointing + size_xy,boostGraph);
                            }
                        }else{
                            boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, vec3d>::vertex_descriptor
                                    cutedarcylookingbackwardinYdirection = 0;
                            for(auto fwend : make_iterator_range(boost::adjacent_vertices(cutedarcypointing, boostGraph))){
                                if(boostGraph[fwend].y < y){
                                    cutedarcylookingbackwardinYdirection = fwend;
                                }
                            }
                            if(cutedarcylookingbackwardinYdirection != 0){
                                boost::remove_edge(cutedarcypointing, cutedarcylookingbackwardinYdirection,boostGraph);
                                if(roll(dice) <= fusionSuccessRate){  // blue gate in +Z direction
                                    boost::add_edge(cutedarcylookingbackwardinYdirection, cutedarcypointing + size_x,boostGraph);
                                }
                            }
                        }
                    }
                }
                cutedarcypointing += 1;
            }
        }
    }

}



