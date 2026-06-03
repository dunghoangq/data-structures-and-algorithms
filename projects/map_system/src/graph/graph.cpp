#include "graph/graph.h"
#include <iostream>

int Graph::add_node(const std::string& name, double lat, double lon) {
    int id = next_id++;
    nodes[id] = {id, name, lat, lon};
    adjacency[id] = {};
    return id;
}

void Graph::add_edge(int from, int to, double weight) {
    adjacency[from].push_back({to, weight});
}

void Graph::add_bidirectional_edge(int from, int to, double weight) {
    add_edge(from, to, weight);
    add_edge(to, from, weight);
}

void Graph::print_graph() const {
    for (const auto& [id, edges] : adjacency) {
        std::cout << nodes.at(id).name << "→";

        for (const auto& e : edges) {
            std::cout << nodes.at(e.to).name
                      << "(" << e.weight << ") ";
        }
        std::cout << "\n";
    }
}