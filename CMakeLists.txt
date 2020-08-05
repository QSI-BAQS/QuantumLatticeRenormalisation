cmake_minimum_required(VERSION 3.13)
project(QuantumLatticeRenormalisation)

set(CMAKE_CXX_STANDARD 14)

# Debug mode
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")


# Graphsim import
set(GRAPHSIM_DIR ${CMAKE_SOURCE_DIR}/GraphSim)
add_library(graphsim ${GRAPHSIM_DIR}/graphsim.cpp ${GRAPHSIM_DIR}/loccliff.cpp ${GRAPHSIM_DIR}/stabilizer.cpp LatticeDistributionStatistics/test_gen_distribution.cpp)

include_directories(graphsim)
link_directories(graphsim)


# Boost import
find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# separate into library modules
add_library(Graph Graph/CartesianGraph.cpp Graph/CartesianGraph.hpp Graph/operators.cpp Graph/structure_data.hpp)
add_library(Foliation foliation.cpp foliation.hpp)
add_library(Similarity similarity.cpp similarity.hpp)
add_library(CandidateLookupTree CandidateLookupTree.cpp CandidateLookupTree.hpp)
add_library(Debug Debug/DebugGraph.cpp Debug/DebugGraph.hpp)
add_library(VF2Wrapper VF2Wrapper.cpp VF2Wrapper.hpp)

# GraphViz

add_library(GVWrapper GraphViz/gv_wrapper.cpp GraphViz/gv_wrapper.hpp)
target_link_libraries(GVWrapper PUBLIC gvc)
# combine libraries in executable
add_executable(QuantumLatticeRenormalisation main.cpp
        Foliation
        Similarity
        VF2Wrapper
        CandidateLookupTree
        Debug
        common.hpp)
target_link_libraries(QuantumLatticeRenormalisation graphsim ${BOOST_LIBRARIES} Graph GVWrapper Debug Foliation Similarity)

add_executable(test_gen_distribution LatticeDistributionStatistics/test_gen_distribution.cpp)

add_subdirectory(googletest)