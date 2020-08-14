
#include "DebugGraph.hpp"

std::string print_edges(const graph_t &g) {
    std::string out;
    edge_iterator_t e_start, e_end;
    boost::tie(e_start, e_end) = edges(g);
    for (; e_start != e_end; ++e_start)
        out += std::to_string(source(*e_start, g))
               + "," + std::to_string(target(*e_start, g)) + " ";
    return out;
}

std::string print_edges_reduced(const graph_t &g) {
    std::string out;
    edge_iterator_t e_start, e_end;
    boost::tie(e_start, e_end) = edges(g);
    for (; e_start != e_end; ++e_start)
        out += "(" + std::to_string(source(*e_start, g))
               + "," + std::to_string(target(*e_start, g)) + ") ";

    return out;
}


std::string print_edges_all_graphs(const graph_list_raw_t &g) {
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

std::string print_edges_all_graphs_reduced(const graph_list_raw_t &g) {
    // Don't mark graph number and no brackets.
    std::string out;
    for (const auto &graph : g) {
        edge_iterator_t e_start, e_end;
        boost::tie(e_start, e_end) = edges(graph);
        for (; e_start != e_end; ++e_start)
            out += std::to_string(source(*e_start, graph))
                   + "," + std::to_string(target(*e_start, graph)) + " ";
        out += "\n";
    }
    return out;
}

std::string get_formatted_datetime() {

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();

    return str;
}

void save_graphs(const graph_list_raw_t &list, const std::string &filepath) {
    std::ofstream out(filepath + ".txt");
    out << print_edges_all_graphs_reduced(list);
    out.close();
}

// For use
void save_graphs_json(const graph_list_raw_t &g, const std::string &filepath) {
    std::ofstream out(filepath + ".json");

    out.close();
}


graph_list_raw_t load_graphs(const std::string &filepath) {

    std::ifstream in(filepath);
    std::string line;
    graph_list_raw_t out;
    graph_t buffer;
    if (in.is_open()) {
        // for each line (one graph)
        while (getline(in, line)) {
            buffer = graph_t();
            std::list<std::string> tokens;
            // split the line to tokens
            boost::split(tokens, line, boost::is_any_of(delim_space));

            for (std::string token : tokens) {
                // boost::split gives emptry strings in between. Probably should of made my own split...
                if (token.empty()) { continue; }
                std::list<std::string> edge_parts;
                // split the token into the two nodes
                boost::split(edge_parts, token, boost::is_any_of(delim_comma));
                // convert the string to int
                std::pair<int, int> edge_pair;
                edge_pair.first = std::stoi(*edge_parts.begin());
                edge_pair.second = std::stoi(*std::next(edge_parts.begin()));
                // add the edge
                add_edge(edge_pair.first, edge_pair.second, buffer);
            }
            // add buffer to the list
            out.push_back(buffer);
        }
        // return the completed list
        return out;
    } else {
        return graph_list_raw_t();
    }

}

graph_list_raw_t load_graphs_json(const std::string &filepath) {
    return graph_list_raw_t();
}

nlohmann::json get_json_form(const graph_t &g) {
    return nlohmann::json();
}

nlohmann::json get_json_form(const graph_list_raw_t &list) {
    return nlohmann::json();
}


