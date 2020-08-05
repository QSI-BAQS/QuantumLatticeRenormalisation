
#include "DebugGraph.hpp"

std::string print_edges(const graph_t &g) {
    std::string out;
    edge_iterator_t e_start, e_end;
    boost::tie(e_start, e_end) = edges(g);
    for (; e_start != e_end; ++e_start)
        out += "(" + std::to_string(source(*e_start, g))
               + "," + std::to_string(target(*e_start, g)) + ") ";

    return out;
}

std::string print_edges_all_graphs(const graph_list_raw &g) {
    std::string out;
    int i = 1;
    for (const auto &graph : g) {
        out += "Graph " + std::to_string(i) + ": ";
        i++;
        edge_iterator_t e_start, e_end;
        boost::tie(e_start, e_end) = edges(graph);
        for (; e_start != e_end; ++e_start)
            out += "(" + std::to_string(source(*e_start, graph))
                   + "," + std::to_string(target(*e_start, graph)) + ") ";
        out += "\n";
    }
    return out;
}
