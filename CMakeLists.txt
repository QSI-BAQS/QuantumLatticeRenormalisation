cmake_minimum_required(VERSION 3.13)
project(QuantumLatticeRenormalisation)

set(CMAKE_CXX_STANDARD 14)

# Graphsim import
set(GRAPHSIM_DIR ${CMAKE_SOURCE_DIR}/GraphSim)
add_library(graphsim ${GRAPHSIM_DIR}/graphsim.cpp ${GRAPHSIM_DIR}/loccliff.cpp ${GRAPHSIM_DIR}/stabilizer.cpp LatticeDistributionStatistics/test_gen_distribution.cpp)

include_directories(graphsim)
link_directories(graphsim)


# Boost import
find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_library(Graph Graph/CartesianGraph.cpp Graph/CartesianGraph.hpp Graph/operators.cpp)
add_executable(QuantumLatticeRenormalisation main.cpp
        foliation.cpp
        foliation.hpp
        similarity.cpp
        similarity.hpp
#        VF2Wrapper.cpp
#        VF2Wrapper.hpp
        CandidateLookupTree.cpp
        CandidateLookupTree.hpp
        basic_includes.hpp)
target_link_libraries(QuantumLatticeRenormalisation graphsim ${BOOST_LIBRARIES} Graph)

add_executable(test_gen_distribution LatticeDistributionStatistics/test_gen_distribution.cpp)

add_subdirectory(googletest)