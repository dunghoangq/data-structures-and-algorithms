#pragma once
#include <vector>
#include <unordered_map>
#include "edge.h"
#include "node.h"


class Graph {
public:
    std::unordered_map<int, std::vector<Edge>> adjacency;
    std::unordered_map<int, Node>              nodes;

    int add_node(const std::string& name, double lat = 0, double lon = 0);
    void add_edge(int from, int to, double weight);
    void add_bidirectional_edge(int from, int to, double weight);
    void print_graph() const;

private:
    int next_id = 0;
};